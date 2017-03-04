
#include <jgLedCube/common/defines.h>
#include <jgLedCube/common/serial.h>

#include <boost/asio/serial_port.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>



class blocking_reader
{
    boost::asio::serial_port& port;
    size_t timeout;
    char c;
    boost::asio::deadline_timer timer;
    bool read_error;

    // Called when an async read completes or has been cancelled
    void read_complete(const boost::system::error_code& error,
                       size_t bytes_transferred) {

        read_error = (error || bytes_transferred == 0);

        // Read has finished, so cancel the
        // timer.
        timer.cancel();
    }

    // Called when the timer's deadline expires.
    void time_out(const boost::system::error_code& error) {

        // Was the timeout was cancelled?
        if (error) {
            // yes
            return;
        }

        // no, we have timed out, so kill
        // the read operation
        // The read callback will be called
        // with an error
        port.cancel();
    }

public:

    // Constructs a blocking reader, pass in an open serial_port and
    // a timeout in milliseconds.
    blocking_reader(boost::asio::serial_port& port, size_t timeout) :
            port(port), timeout(timeout),
            timer(port.get_io_service()),
            read_error(true) {

    }

    // Reads a character or times out
    // returns false if the read times out
    bool read_char(char& val) {

        val = c = '\0';

        // After a timeout & cancel it seems we need
        // to do a reset for subsequent reads to work.
        port.get_io_service().reset();

        // Asynchronously read 1 character.
        boost::asio::async_read(port, boost::asio::buffer(&c, 1),
                                boost::bind(&blocking_reader::read_complete,
                                            this,
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::bytes_transferred));

        // Setup a deadline time to implement our timeout.
        timer.expires_from_now(boost::posix_time::milliseconds(timeout));
        timer.async_wait(boost::bind(&blocking_reader::time_out,
                                     this, boost::asio::placeholders::error));

        // This will block until a character is read
        // or until the it is cancelled.
        port.get_io_service().run();

        if (!read_error)
            val = c;

        return !read_error;
    }
};


/// TODO: Support arbitrary serial port locations and pass in the cmake definition for testing only
namespace jgLedCube {
    namespace serial {

        static uint8_t outBuf[1];

        boost::asio::io_service io_service;
        boost::asio::serial_port outSerialPort(io_service, LED_CUBE_OUT_SERIAL_PORT);
        boost::asio::serial_port inSerialPort(io_service, LED_CUBE_IN_SERIAL_PORT);
        blocking_reader inReader(inSerialPort, 50);

        void init() {
            outSerialPort.set_option(boost::asio::serial_port_base::baud_rate(LED_CUBE_SERIAL_BAUD));
            inSerialPort.set_option(boost::asio::serial_port_base::baud_rate(LED_CUBE_SERIAL_BAUD));
        }

        /// Sends a transport packet down the serial line
        /// \param outTransportPacket
        void sendTransportPacket(uint8_t outTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE]) {
            outSerialPort.write_some(boost::asio::buffer(outTransportPacket, LED_CUBE_TRANSPORT_PACKET_SIZE));
        }

        bool serialAvailable() {
            return true;
        }

        uint8_t readByte() {
            static char inBuf = 0;
            inReader.read_char(inBuf);
            return (uint8_t)inBuf;
        };


        bool receiveTransportPacket(uint8_t inTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE]) {
            static uint8_t buffer[20] = {255};  // TODO: Find a better way of doing this init
            // need to pre fill with serial data to get a valid return from the first shot
            bool noSerial = false;
            uint8_t tempByte = 0;

            if (buffer[0] == 255){
                for (int k = 0; k < 20; ++k) {
                    if (noSerial){
                        tempByte = 0;

                    }else{
                        tempByte = readByte();
                    }

                    if (tempByte) {
                        buffer[k] = tempByte;
                    }
                    else{
                        noSerial = true;
                        buffer[k] = 0;
                    }
                }
            }

            int8_t startIndex = -1;
            bool foundPacket = false;

            noSerial = false;

            while (!foundPacket and !noSerial) {  /// or serial not available

                /// Identify packet
                startIndex = -1;
                for (int i = 0; i < 12; ++i) {

                    if (buffer[i] == jgLedCube::serial::transportSB &&
                        buffer[i + 1] == jgLedCube::serial::transportSB &&
                        buffer[i + 7] == jgLedCube::serial::transportEB &&
                        buffer[i + 6] == (uint8_t) ~buffer[i + 2]) {

                        foundPacket = true;
                        startIndex = i;

                        for (int j = 0; j < LED_CUBE_TRANSPORT_PACKET_SIZE; j++) {
                            inTransportPacket[j] = buffer[i + j];
                            buffer[i + j] = 0;
                        }
                        break;
                    }
                }

                /// Slide values along to remove the packet we just grabbed
                int8_t offset = 19;
                for (int l = 0; l < 20; ++l) {
                    if (buffer[l] == 0 && buffer[l + 1] != 0) {
                        offset = l;
                        break;
                    }
                }

                for (int l = 0; l < 20; ++l) {
                    if (l + offset > 19) {
                        if (noSerial){
                            tempByte = 0;
                        }else{
                            tempByte = jgLedCube::serial::readByte();
                        }

                        if (tempByte){
                            buffer[l] = tempByte;
                        }else{
                            noSerial = true;
                            buffer[l] = 0;
                        }

                    } else {
                        buffer[l] = buffer[l + offset];
                    }
                }
            }
            return foundPacket;
        }


    }
}

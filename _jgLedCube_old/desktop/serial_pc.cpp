/// PC Specific impl components for serial communication

#include "serial.h"
#include "defines.h"

#include <iostream>
#include <boost/asio/serial_port.hpp>


namespace jgLedCube {
    namespace serial {

        /// Sends a byte of data down TX
#if PHONY_SERIAL
        bool sendByte(uint8_t data){
            std::cout << "Serial Send: " << (int)data << std::endl;
            return true;
        }
#else
        static uint8_t outBuf[1];

        boost::asio::io_service io_service;
        boost::asio::serial_port serial_port = boost::asio::serial_port( io_service, "/dev/ttyUSB0" );

        bool sendByte(uint8_t data){
            serial_port.set_option( boost::asio::serial_port_base::baud_rate( 19200 ) );
            outBuf[0] = data;
            serial_port.write_some(boost::asio::buffer(outBuf, 1));
            return true;
        }
#endif
    }
}

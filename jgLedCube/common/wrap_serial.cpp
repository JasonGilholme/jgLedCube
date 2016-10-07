/// Python bindings for serial library

#include <jgLedCube/common/serial.h>

#include <boost/python.hpp>


BOOST_PYTHON_MODULE( _jgLedCubeSerial )
{
    boost::python::def("decode_command_id",
                       jgLedCube::serial::decode_commandId);

    boost::python::def("encode_clear",
                       jgLedCube::serial::encode_clear);

    boost::python::def("encode_set_led",
                       jgLedCube::serial::encode_setLed);
    boost::python::def("decode_set_led",
                       jgLedCube::serial::decode_setLed);

    boost::python::def("encode_get_led",
                       jgLedCube::serial::encode_getLed);
    boost::python::def("decode_get_led",
                       jgLedCube::serial::decode_getLed);

    boost::python::def("encode_get_led_return",
                       jgLedCube::serial::encode_getLedReturn);
    boost::python::def("decode_get_led_return",
                       jgLedCube::serial::decode_getLedReturn);

    boost::python::def("encode_get_config",
                       jgLedCube::serial::encode_getConfig);

    boost::python::def("encode_get_config_return",
                       jgLedCube::serial::encode_getConfigReturn);
    boost::python::def("decode_get_config_return",
                       jgLedCube::serial::decode_getConfigReturn);

    boost::python::def("deconstruct_transport_packet",
                       jgLedCube::serial::deconstructTransportPacket);
    boost::python::def("construct_transport_packet",
                       jgLedCube::serial::constructTransportPacket);

}

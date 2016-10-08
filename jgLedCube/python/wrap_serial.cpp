/// Python bindings for serial library

#include <jgLedCube/common/serial.h>
#include <jgLedCube/common/defines.h>

#include <boost/python.hpp>
#include <map>


void _uint8_to_list(uint8_t cList[], boost::python::list &pyList, uint8_t size){
    for (int i = 0; i < size; ++i) {
        pyList.append(cList[i]);
    }
}


void _list_to_uint8(boost::python::list &pyList, uint8_t cList[], uint8_t size){
    for (int i = 0; i < size; ++i) {
        cList[i] = boost::python::extract<uint8_t>(pyList[i]);
    }
}


int decode_command_id(boost::python::list inList){
    uint8_t inCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
    _list_to_uint8(inList, inCommandPacket, LED_CUBE_COMMAND_PACKET_SIZE);
//    uint8_t = jgLedCube::serial::decode_commandId(inCommandPacket);
    //cmdIds.value()
    return jgLedCube::serial::decode_commandId(inCommandPacket);
}


boost::python::list encode_clear(){
    uint8_t outCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
    boost::python::list outList;
    jgLedCube::serial::encode_clear(outCommandPacket);
    _uint8_to_list(outCommandPacket, outList, LED_CUBE_COMMAND_PACKET_SIZE);
    return outList;
}


boost::python::list encode_set_led(uint8_t x, uint8_t y, uint8_t z, uint8_t r, uint8_t g, uint8_t b){
    uint8_t outCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
    boost::python::list outList;
    jgLedCube::serial::encode_setLed(outCommandPacket, x, y, z, r, g, b);
    _uint8_to_list(outCommandPacket, outList, LED_CUBE_COMMAND_PACKET_SIZE);
    return outList;
}


boost::python::list encode_get_led(uint8_t x, uint8_t y, uint8_t z){
    uint8_t outCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
    boost::python::list outList;
    jgLedCube::serial::encode_getLed(outCommandPacket, x, y, z);
    _uint8_to_list(outCommandPacket, outList, LED_CUBE_COMMAND_PACKET_SIZE);
    return outList;
}


boost::python::list decode_get_led_return(boost::python::list inList){
    uint8_t inCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
    uint8_t retArgs[3]; // Returns R G B
    boost::python::list outList;

    // Convert the in pyt list to uint8_t
    _list_to_uint8(inList, inCommandPacket, LED_CUBE_COMMAND_PACKET_SIZE);
    // Decode the cmd
    jgLedCube::serial::decode_getLedReturn(inCommandPacket, retArgs);
    // Convert the decoded values to pylist
    _uint8_to_list(retArgs, outList, 3);
    return outList;
}


boost::python::list encode_get_config(){
    uint8_t commandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
    boost::python::list outList;
    jgLedCube::serial::encode_getConfig(commandPacket);
    _uint8_to_list(commandPacket, outList, LED_CUBE_COMMAND_PACKET_SIZE);
    return outList;
}


boost::python::list decode_get_config_return(boost::python::list inList){
    uint8_t inCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
    uint8_t retArgs[6]; // Returns X Y Z N V ID
    boost::python::list outList;

    // Convert the in pyt list to uint8_t
    _list_to_uint8(inList, inCommandPacket, LED_CUBE_COMMAND_PACKET_SIZE);
    // Decode the cmd
    jgLedCube::serial::decode_getConfigReturn(inCommandPacket, retArgs);
    // Convert the decoded values to pylist
    _uint8_to_list(retArgs, outList, 6);
    return outList;
}


boost::python::list deconstruct_transport_packet(boost::python::list py_inTransportPacket){
    uint8_t c_inTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE];
    boost::python::list py_inCommandPacket;
    uint8_t c_inCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];

    // Convert types and deconstruct
    _list_to_uint8(py_inTransportPacket, c_inTransportPacket, LED_CUBE_TRANSPORT_PACKET_SIZE);
    jgLedCube::serial::deconstructTransportPacket(c_inTransportPacket, c_inCommandPacket);
    _uint8_to_list(c_inCommandPacket, py_inCommandPacket, LED_CUBE_COMMAND_PACKET_SIZE);

    return py_inCommandPacket;
}


boost::python::list construct_transport_packet(boost::python::list py_outCommandPacket){
    uint8_t c_outCommandPacket[LED_CUBE_COMMAND_PACKET_SIZE];
    boost::python::list py_outTransportPacket;
    uint8_t c_outTransportPacket[LED_CUBE_TRANSPORT_PACKET_SIZE];

    // Convert types and deconstruct
    _list_to_uint8(py_outCommandPacket, c_outCommandPacket, LED_CUBE_COMMAND_PACKET_SIZE);
    jgLedCube::serial::constructTransportPacket(c_outTransportPacket, c_outCommandPacket);
    _uint8_to_list(c_outTransportPacket, py_outTransportPacket, LED_CUBE_TRANSPORT_PACKET_SIZE);

    return py_outTransportPacket;
}


std::map<std::string, int> cmdIds = {
        {"set_led", LED_CUBE_CMD_SET_LED},
        {"set_mode", LED_CUBE_CMD_SET_MODE},
        {"get_config", LED_CUBE_CMD_GET_CONFIG},
        {"get_led", LED_CUBE_CMD_GET_LED},
        {"get_modes", LED_CUBE_CMD_GET_MODES},
        {"get_mode", LED_CUBE_CMD_GET_MODE},
        {"get_led_return", LED_CUBE_CMD_GET_LED_RETURN},
        {"get_config_return", LED_CUBE_CMD_GET_CONFIG_RETURN},
        {"get_modes_return", LED_CUBE_CMD_GET_MODES_RETURN},
        {"get_mode_return", LED_CUBE_CMD_GET_MODE_RETURN},
        {"clear", LED_CUBE_CMD_CLEAR},
};


BOOST_PYTHON_MODULE( _jgLedCubeSerial )
{

    boost::python::class_<std::map<std::string, int>>("CMDS")
            .def_readonly("set_led", cmdIds.at("set_led"))
            .def_readonly("set_mode", cmdIds.at("set_mode"))
            .def_readonly("get_config", cmdIds.at("get_config"))
            .def_readonly("get_led", cmdIds.at("get_led"))
            .def_readonly("get_modes", cmdIds.at("get_modes"))
            .def_readonly("get_mode", cmdIds.at("get_mode"))
            .def_readonly("get_led_return", cmdIds.at("get_led_return"))
            .def_readonly("get_config_return", cmdIds.at("get_config_return"))
            .def_readonly("get_modes_return", cmdIds.at("get_modes_return"))
            .def_readonly("get_mode_return", cmdIds.at("get_mode_return"))
            .def_readonly("clear", cmdIds.at("clear"));

    boost::python::def("decode_command_id",
                       &decode_command_id);

    boost::python::def("encode_clear",
                       &encode_clear);

    boost::python::def("encode_set_led",
                       &encode_set_led);

    boost::python::def("encode_get_led",
                       &encode_get_led);

    boost::python::def("decode_get_led_return",
                       &decode_get_led_return);

    boost::python::def("encode_get_config",
                       &encode_get_config);

    boost::python::def("decode_get_config_return",
                       &decode_get_config_return);

    boost::python::def("deconstruct_transport_packet",
                       &deconstruct_transport_packet);
    boost::python::def("construct_transport_packet",
                       &construct_transport_packet);
}

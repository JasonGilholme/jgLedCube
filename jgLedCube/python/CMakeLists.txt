
install( FILES test.py DESTINATION lib/python )
install( FILES __init__.py DESTINATION lib/python/jgLedCube )

add_library( _jgLedCubeSerial SHARED wrap_serial.cpp )
target_link_libraries( _jgLedCubeSerial jgLedCubeSerial boost_python )
set_target_properties( _jgLedCubeSerial PROPERTIES PREFIX "")
install( TARGETS _jgLedCubeSerial LIBRARY DESTINATION lib/python/jgLedCube)

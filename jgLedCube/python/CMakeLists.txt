
install( FILES test.py DESTINATION lib/python )
install( FILES __init__.py DESTINATION lib/python/jgLedCube )

add_library( _common_serial SHARED wrap_serial.cpp )
target_link_libraries( _common_serial common_serial ${Boost_PYTHON_LIBRARY_RELEASE} )
set_target_properties( _common_serial PROPERTIES PREFIX "")
install( TARGETS _common_serial LIBRARY DESTINATION lib/python/jgLedCube)

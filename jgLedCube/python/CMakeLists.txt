
install( FILES test.py DESTINATION lib/python )
install( FILES __init__.py DESTINATION lib/python/jgLedCube )

add_library( _cube_serial SHARED wrap_serial.cpp )
target_link_libraries( _cube_serial cube_serial ${Boost_PYTHON_LIBRARY_RELEASE} )
set_target_properties( _cube_serial PROPERTIES PREFIX "")
install( TARGETS _cube_serial LIBRARY DESTINATION lib/python/jgLedCube)

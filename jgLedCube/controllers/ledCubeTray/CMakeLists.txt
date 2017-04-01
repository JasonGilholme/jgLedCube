#
# Add the ledCubeTray App
#
add_executable(ledCubeTray main.cpp ui/ledCubeTray.cpp)
target_link_libraries(ledCubeTray Qt5::Widgets Qt5::SerialPort)
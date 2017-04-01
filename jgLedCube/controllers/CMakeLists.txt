
if (${CUBE_TARGET_PLATFORM} STREQUAL desktop)
    #
    # Build desktop controllers
    #
    add_subdirectory(common)
    add_subdirectory(ledCubeTray)
else ()
    #
    # Build embedded controllers
    #
endif()

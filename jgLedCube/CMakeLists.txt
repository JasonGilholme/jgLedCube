
add_subdirectory(common)

#
# Include platform compatible directories
#
if (${CUBE_TARGET_PLATFORM} STREQUAL desktop)
    add_subdirectory(controllers/ledCubeTray)
elseif (${CUBE_TARGET_PLATFORM} STREQUAL android)
elseif (${CUBE_TARGET_PLATFORM} STREQUAL arduino)
elseif (${CUBE_TARGET_PLATFORM} STREQUAL stm)
endif()

cmake_minimum_required(VERSION 3.5)

project(LOST_Test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FILE(GLOB_RECURSE LOST_Test_include "include/*.h")
add_custom_target(_LOST_Test_include SOURCES ${LOST_Test_include})


add_executable(LOST_Test
    Main.cpp
)

target_include_directories(LOST_Test PUBLIC
                            "${PROJECT_SOURCE_DIR}"
)

#if (WIN32)
#    target_link_libraries(LOST_Test PUBLIC
#        opengl32
#        user32
#        gdi32
#        shell32
#    )
#endif (WIN32)

#if (UNIX)
#    target_link_libraries(LOST_Test PUBLIC
#        pthread
#        GL
#        X11
#        dl
#    )
#endif (UNIX)

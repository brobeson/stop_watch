cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

# no in-source builds
if (CMAKE_BINARY_DIR MATCHES "${CMAKE_SOURCE_DIR}.*")
    message(FATAL_ERROR "In source builds are not allowed.")
endif()

project(stop_watch
    VERSION 0.1.0.0
    DESCRIPTION "A class for timing an operation."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#add_library(${PROJECT_NAME} INTERFACE)
#target_compile_options(${PROJECT_NAME}
#    PRIVATE
#        -Werror
#        -Wpedenatic
#)

# create a unit test
add_executable(stop_watch_test stop_watch_test.cpp)
#target_link_libraries(stop_watch_test stop_watch)
target_compile_options(stop_watch_test
    PRIVATE
        -Werror
        -Wpedantic
)

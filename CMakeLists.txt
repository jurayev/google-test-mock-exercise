cmake_minimum_required(VERSION 3.2)
project(google-test-mock-exercise)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/test/mocks
        ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
        ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)
link_directories(${LIBRARY_OUTPUT_PATH})

add_subdirectory(lib)
add_subdirectory(test)

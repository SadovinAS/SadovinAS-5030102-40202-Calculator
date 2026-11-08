add_library(sqrt SHARED sqrt.h sqrt.cpp)
target_include_directories(sqrt PRIVATE ${CMAKE_SOURCE_DIR}/header)
set_target_properties(sqrt PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/plugins")

add_library(pow SHARED pow.h pow.cpp)
target_include_directories(pow PRIVATE ${CMAKE_SOURCE_DIR}/header)
set_target_properties(pow PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/plugins")

add_library(trig SHARED trig.h trig.cpp)
target_include_directories(trig PRIVATE ${CMAKE_SOURCE_DIR}/header)
set_target_properties(trig PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/plugins")

add_library(deg SHARED deg.h deg.cpp)
target_include_directories(deg PRIVATE ${CMAKE_SOURCE_DIR}/header)
set_target_properties(deg PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/plugins"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/plugins")


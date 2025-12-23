cmake_minimum_required(VERSION 3.10) # required

file(GLOB_RECURSE objc_headers headers/*.h)
file(GLOB_RECURSE objc_sources sources/*.mm)
set(objc_srcs ${objc_headers} ${objc_sources})

add_library(${PROJECT_NAME}_iOS_bridge STATIC ${objc_srcs})

message(STATUS "project ${CMAKE_PROJECT_NAME}")
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/headers
    ${PROJECT_SOURCE_DIR}/..)

target_compile_features(${PROJECT_NAME}_iOS_bridge PRIVATE ObjectiveCXX_11)

set_target_properties(${PROJECT_NAME}_iOS_bridge PROPERTIES LINKER_LANGUAGE CXX)
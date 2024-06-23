cmake_minimum_required(VERSION 3.10) # required
project(tlbx)  # project name
		
file(GLOB_RECURSE cpp_headers src/headers/*.hpp)
file(GLOB_RECURSE cpp_sources src/sources/*.cpp)
set(srcs src/${PROJECT_NAME}.hpp ${cpp_headers} ${cpp_sources})

add_library(${PROJECT_NAME} STATIC ${srcs})
        
# Enable include with <> pair
target_include_directories(${PROJECT_NAME} PUBLIC src/headers)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

## build type ##
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif ()

find_package(Git QUIET)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

cmake_minimum_required(VERSION 3.10) # required
project(tlbx)  # project name
		
file(GLOB_RECURSE cpp_headers src/cpp/headers/*.hpp)
file(GLOB_RECURSE cpp_sources src/cpp/sources/*.cpp)
set(srcs src/${PROJECT_NAME}.hpp ${cpp_headers} ${cpp_sources})

option(${PROJECT_NAME}_CPP_BRIDGE "Build ${PROJECT_NAME} Objective-C" ON)

if (${PROJECT_NAME}_CPP_BRIDGE)
	file(GLOB_RECURSE objc_files src/objC/*.h src/objC/*.mm)
	set(srcs ${srcs} ${objc_files})
endif()

add_library(${PROJECT_NAME} STATIC ${srcs})

add_compile_definitions("TARGET_MACOS")

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-D${PROJECT_NAME}_STATIC_DEFINE")

target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra>
        )
        
# Enable include with <> pair
target_include_directories(${PROJECT_NAME} PUBLIC src/cpp/headers)

if (${PROJECT_NAME}_CPP_BRIDGE)
        target_include_directories(${PROJECT_NAME} PUBLIC src/objC)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

## build type ##
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif ()

find_package(Git QUIET)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

#include(compiler-flags)

#add_subdirectory(vendor)


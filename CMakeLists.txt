cmake_minimum_required(VERSION 3.10) # required

project(tlbx)  # project name
	
file(GLOB_RECURSE cpp_headers headers/*.hpp)
file(GLOB_RECURSE cpp_sources sources/*.cpp)
set(cpp_srcs ${PROJECT_NAME}.hpp ${cpp_headers} ${cpp_sources})

# Organize files into groups for Xcode/Visual Studio
source_group("headers" FILES ${cpp_headers})
source_group("sources" FILES ${cpp_sources})
source_group("" FILES ${PROJECT_NAME}.hpp)

add_library(${PROJECT_NAME} STATIC ${cpp_srcs})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/headers)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
# Code sign to avoid macOS permission dialogs
if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "-"
        XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO"
        XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    )
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

if(${PROJECT_NAME}_TARGET_IOS)
    add_subdirectory(iOS_bridge)
endif()

if (${PROJECT_NAME}_BUILD_TESTING)
    # Only add googletest if tlbx is the main project
    if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
        enable_testing()
        set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
        set(CMAKE_SUPPRESS_REGENERATION ON CACHE BOOL "" FORCE)
        add_subdirectory(googletest)
    endif() 
    add_subdirectory(test)
endif()

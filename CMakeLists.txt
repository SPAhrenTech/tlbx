cmake_minimum_required(VERSION 3.10) # required
project(tlbx)  # project name
		
file(GLOB_RECURSE cpp_headers headers/*.hpp)
file(GLOB_RECURSE cpp_sources sources/*.cpp)
set(cpp_srcs ${PROJECT_NAME}.hpp ${cpp_headers} ${cpp_sources})

add_library(${PROJECT_NAME} STATIC ${cpp_srcs})
        
# Enable include with <> pair
target_include_directories(${PROJECT_NAME} PUBLIC headers)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# iOS library
file(GLOB_RECURSE objC_headers iOS_bridge/headers/*.h)
file(GLOB_RECURSE objC_sources iOS_bridge/sources/*.mm)
set(objC_srcs ${objC_headers} ${objC_sources})

# Enable Objective-C
enable_language(OBJC)

add_library(${PROJECT_NAME}_iOS STATIC ${cpp_srcs} ${objC_srcs})
        
# Enable include with <> pair
target_include_directories(${PROJECT_NAME}_iOS PUBLIC headers iOS_bridge/headers)

target_compile_features(${PROJECT_NAME}_iOS PRIVATE cxx_std_17)

# Set target properties
set_target_properties(${PROJECT_NAME}_iOS PROPERTIES
    MACOSX_BUNDLE YES
    MACOSX_BUNDLE_IDENTIFIER "com.example.tlbx_iOS"
    XCODE_ATTRIBUTE_ENABLE_STRICT_OBJC_MSGS YES
)

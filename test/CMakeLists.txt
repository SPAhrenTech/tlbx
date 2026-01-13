set(files
        unit-test.hpp
        cpxTest.cpp
        unit-test-main.cpp
        )

add_executable(${PROJECT_NAME}_tests ${files})

target_compile_features(${PROJECT_NAME}_tests PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME}_tests PRIVATE "${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/headers")

target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME} gtest)

include(GoogleTest)

gtest_discover_tests(
        ${PROJECT_NAME}_tests
        TEST_PREFIX ${PROJECT_NAME}:
)

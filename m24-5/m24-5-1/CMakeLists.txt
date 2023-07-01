cmake_minimum_required(VERSION 3.0.0)

project(m24-5-1
        VERSION 0.0.1
        DESCRIPTION "Test Description"
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/suzumeone/homework")

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(${PROJECT_NAME} src/main.cpp src/logic.cpp src/logic.h)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)




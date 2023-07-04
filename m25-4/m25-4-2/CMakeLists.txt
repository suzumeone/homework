cmake_minimum_required(VERSION 3.5)

project(m25-4-2
        VERSION 1.0.0
        DESCRIPTION "Test Description"
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/suzumeone/homework")

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(${PROJECT_NAME} src/main.cpp src/gpu.cpp src/disk.cpp src/cpu.cpp src/kbd.cpp src/ram.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

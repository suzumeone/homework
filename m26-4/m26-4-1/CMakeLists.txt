cmake_minimum_required(VERSION 3.5)

project(m26-4-1
        VERSION 1.0.0
        DESCRIPTION "Test Description"
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/suzumeone/homework")

set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(${PROJECT_NAME} src/main.cpp)
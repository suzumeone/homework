add_executable(${PROJECT_NAME} main.cpp gpu.cpp disk.cpp cpu.cpp kbd.cpp ram.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

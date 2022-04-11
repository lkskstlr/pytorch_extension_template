cmake_minimum_required(VERSION 3.18)
project(raytracing LANGUAGES CXX)

find_package(Torch REQUIRED PATHS ${CMAKE_CURRENT_LIST_DIR}/thirdparty/libtorch/libtorch)
find_package(Python REQUIRED COMPONENTS Development)

# Test Executable
add_executable(test src/test.cpp src/example.cpp)
target_include_directories(test PRIVATE include)
target_compile_features(test PRIVATE cxx_std_17)
target_link_libraries(test PRIVATE ${TORCH_LIBRARIES})

# Our Python lib
add_library(raytracing SHARED src/example.cpp src/raytracing.cpp)
target_include_directories(raytracing PRIVATE include)
target_compile_features(raytracing PRIVATE cxx_std_17)
target_link_libraries(raytracing PRIVATE ${TORCH_LIBRARIES} Python::Python)

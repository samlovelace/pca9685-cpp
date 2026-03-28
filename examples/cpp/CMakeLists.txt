cmake_minimum_required(VERSION 3.10)
project(example)

set(CMAKE_CXX_STANDARD 17)

find_package(pca9685 REQUIRED)

add_executable(example-cpp main.cpp)
target_link_libraries(example-cpp pca9685::pca9685)

cmake_minimum_required(VERSION 3.10)
project(hw-prog)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.c temp_api.c)
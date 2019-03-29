cmake_minimum_required(VERSION 3.13)
project(SW_Tools_HW_10)

set(CMAKE_CXX_STANDARD 14)

# create executable with make
#add_executable(SW_Tools_HW_10 COMMAND make)
add_custom_target(example COMMAND make)
cmake_minimum_required(VERSION 3.0)
project(patcher)
file(GLOB sources *.c *.h)
add_executable(patch ${sources})

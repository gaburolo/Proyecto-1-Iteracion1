cmake_minimum_required(VERSION 3.12)
project(proyecto)

set(D_GLICBCXX_USE_CXX11_ABI 0)

set(CMAKE_CXX_STANDARD 14)

add_executable(proyecto main.cpp Sort/Bubblesort.cpp Sort/InsertSort.cpp)

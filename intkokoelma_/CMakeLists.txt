cmake_minimum_required(VERSION 3.16)
project(intkokoelma)

set(CMAKE_CXX_STANDARD 98)

add_executable(main.cpp intkokoelma.h intlista.cpp intlista.h intkokoelma.cpp)
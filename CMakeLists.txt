cmake_minimum_required(VERSION 3.30)
project(rule_of_three_property_value)

set(CMAKE_CXX_STANDARD 20)

add_executable(rule_of_three_property_value v1/main.cpp
        v1/property.cpp
        v1/property.h)

cmake_minimum_required(VERSION 3.5)
project(Modelling LANGUAGES CXX VERSION 1.0 DESCRIPTION "Investment portfolio management system")
set (CMAKE_CXX_STANDARD 23)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_subdirectory(src/logic)
add_subdirectory(src/app)

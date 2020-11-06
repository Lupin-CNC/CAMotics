cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
project(camotics)

find_package(Cbang CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_subdirectory(src)

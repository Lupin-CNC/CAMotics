cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC OFF)
# set(CMAKE_AUTORCC ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

project(Camotics)
set (Camotics_VERSION_MAJOR "1")
set (Camotics_VERSION_MINOR "2")
set (Camotics_VERSION_PATCH "1")
set (PROJECT_VERSION "${Camotics_VERSION_MAJOR}.${Camotics_VERSION_MINOR}.${Camotics_VERSION_PATCH}")

find_package( Cbang  REQUIRED )
message(STATUS "Cbang libs: ${CBANG_LIBRARIES}")

include(QtCamoticsConfig)
find_package(Qt5 ${QT_VERSION} 
    COMPONENTS 
        Core
        Gui
        OpenGL
        Widgets
        WebSockets
        Network
    REQUIRED
    HINTS
        ${QT_LIBRARY_HINTS}
)
message(STATUS "Qt version: ${QT_VERSION}")
message(STATUS "Qt spec: ${QT_MKSPEC}")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_subdirectory(src)

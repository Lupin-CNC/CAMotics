set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${Cbang_INCLUDE_DIR}" 
    "${Camotics_SOURCE_DIR}/src")

configure_file("build_info.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/build_info.cpp" @ONLY)
configure_file("resources.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/resources.cpp" @ONLY)

add_subdirectory(gcode)
add_library(CamoticsGcode STATIC
    $<TARGET_OBJECTS:gcode-main>
    $<TARGET_OBJECTS:gcode-ast>
    $<TARGET_OBJECTS:gcode-interp>
    $<TARGET_OBJECTS:gcode-machine>
    $<TARGET_OBJECTS:gcode-parse>
    $<TARGET_OBJECTS:gcode-plan>
)
target_compile_definitions(CamoticsGcode PRIVATE USING_CBANG)
target_include_directories(CamoticsGcode PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/gcode" 
)
target_link_libraries(CamoticsGcode PRIVATE
    ${CBANG_LIBRARIES}
)

add_subdirectory(dxflib)
add_library(CamoticsDXF STATIC
    $<TARGET_OBJECTS:dxf-main>
)
target_include_directories(CamoticsDXF PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/dxflib"
)

add_subdirectory(cairo)
add_subdirectory(stl)
add_subdirectory(dxf)
add_subdirectory(camotics)
add_library(CamoticsCore STATIC
    $<TARGET_OBJECTS:camotics-main>
    $<TARGET_OBJECTS:camotics-contour>
    $<TARGET_OBJECTS:camotics-machine>
    $<TARGET_OBJECTS:camotics-opt>
    $<TARGET_OBJECTS:camotics-probe>
    $<TARGET_OBJECTS:camotics-project>
    $<TARGET_OBJECTS:camotics-render>
    $<TARGET_OBJECTS:camotics-sim>
    $<TARGET_OBJECTS:camotics-value>
    $<TARGET_OBJECTS:camotics-cairo>
    $<TARGET_OBJECTS:camotics-stl>
    $<TARGET_OBJECTS:camotics-dxf>
)
target_compile_definitions(CamoticsCore PRIVATE USING_CBANG)
target_include_directories(CamoticsCore PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/cairo"
    "${CMAKE_CURRENT_SOURCE_DIR}/stl"
    "${CMAKE_CURRENT_SOURCE_DIR}/dxf"
    "${CMAKE_CURRENT_SOURCE_DIR}/camotics"
)
target_link_libraries(CamoticsCore PRIVATE
    CamoticsGcode
    CamoticsDXF
)

qt5_add_resources(CAMotics_Resources_RCC
    ${CMAKE_SOURCE_DIR}/qt/camotics.qrc
)
set_property(SOURCE ${CAMotics_Resources_RCC}
    PROPERTY SKIP_AUTOGEN ON
)
add_executable(CAMotics
    $<TARGET_OBJECTS:camotics-qt>
    $<TARGET_OBJECTS:camotics-view>
    "${CMAKE_CURRENT_BINARY_DIR}/build_info.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/resources.cpp"
    "camotics.cpp"
    ${CAMotics_Resources_RCC}
)
target_compile_definitions(CAMotics PRIVATE USING_CBANG)
target_link_libraries(CAMotics PRIVATE
    CamoticsGcode 
    CamoticsDXF
    CamoticsCore
    Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL Qt5::Network Qt5::WebSockets
    ${CBANG_LIBRARIES} 
)

add_executable(gcodetool 
    $<TARGET_OBJECTS:camotics-main>
    "${CMAKE_CURRENT_BINARY_DIR}/build_info.cpp"
    "gcodetool.cpp" )
target_compile_definitions(gcodetool PRIVATE USING_CBANG)
target_link_libraries(gcodetool PRIVATE
    CamoticsGcode
    ${CBANG_LIBRARIES}
)

# Install target
set_target_properties(CamoticsGcode PROPERTIES
    FRAMEWORK       FALSE
    VERSION             ${Camotics_VERSION}
    SOVERSION           ${Camotics_SOVERSION}
    DEFINE_SYMBOL       MAKE_CBANG_LIB
)
install(TARGETS CamoticsGcode
    EXPORT          CamoticsGcode-targets
    RUNTIME         DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics
    PUBLIC_HEADER   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics
)

set_target_properties(CamoticsDXF PROPERTIES
    FRAMEWORK       FALSE
    VERSION             ${Camotics_VERSION}
    SOVERSION           ${Camotics_SOVERSION}
    DEFINE_SYMBOL       MAKE_CBANG_LIB
)
install(TARGETS CamoticsDXF
    EXPORT          CamoticsDXF-targets
    RUNTIME         DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics
    PUBLIC_HEADER   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics
)

set_target_properties(CamoticsCore PROPERTIES
    FRAMEWORK       FALSE
    VERSION             ${Camotics_VERSION}
    SOVERSION           ${Camotics_SOVERSION}
    DEFINE_SYMBOL       MAKE_CBANG_LIB
)
install(TARGETS CamoticsCore
    EXPORT          CamoticsCore-targets
    RUNTIME         DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE         DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics
    PUBLIC_HEADER   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics
)

#install(EXPORT Camotics-targets
#    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/camotics
#)
configure_package_config_file(
    ${Camotics_SOURCE_DIR}/cmake/camoticsConfig.cmake.in ${CMAKE_BINARY_DIR}/camoticsConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/camotics
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR
)
write_basic_package_version_file(${CMAKE_BINARY_DIR}/camoticsConfigVersion.cmake
    VERSION ${Camotics_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(FILES
    ${CMAKE_BINARY_DIR}/camoticsConfig.cmake
    ${CMAKE_BINARY_DIR}/camoticsConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/camotics
)

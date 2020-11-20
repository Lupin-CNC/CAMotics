set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${Cbang_INCLUDE_DIR}" 
    "${Camotics_SOURCE_DIR}/src")

configure_file("build_info.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/build_info.cpp" @ONLY)
configure_file("resources.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/resources.cpp" @ONLY)

add_subdirectory(gcode)
add_library(Gcode STATIC
    $<TARGET_OBJECTS:gcode-main>
    $<TARGET_OBJECTS:gcode-ast>
    $<TARGET_OBJECTS:gcode-interp>
    $<TARGET_OBJECTS:gcode-machine>
    $<TARGET_OBJECTS:gcode-parse>
    $<TARGET_OBJECTS:gcode-plan>
)
target_compile_definitions(Gcode PRIVATE USING_CBANG)

add_library(DXF STATIC 
    dxflib/dl_attributes.h dxflib/dl_codes.h dxflib/dl_creationadapter.h
    dxflib/dl_creationinterface.h dxflib/dl_dxf.h dxflib/dl_entities.h
    dxflib/dl_exception.h dxflib/dl_extrusion.h dxflib/dl_global.h
    dxflib/dl_writer_ascii.h dxflib/dl_writer.h
    dxflib/dl_dxf.cpp dxflib/dl_writer_ascii.cpp )
target_include_directories(DXF PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dxflib )

add_subdirectory(cairo)
add_subdirectory(stl)
add_subdirectory(dxf)
add_subdirectory(camotics)
add_executable(CAMotics
    $<TARGET_OBJECTS:camotics-main>
    $<TARGET_OBJECTS:camotics-contour>
    $<TARGET_OBJECTS:camotics-machine>
    $<TARGET_OBJECTS:camotics-opt>
    $<TARGET_OBJECTS:camotics-probe>
    $<TARGET_OBJECTS:camotics-project>
    $<TARGET_OBJECTS:camotics-qt>
    $<TARGET_OBJECTS:camotics-render>
    $<TARGET_OBJECTS:camotics-sim>
    $<TARGET_OBJECTS:camotics-value>
    $<TARGET_OBJECTS:camotics-view>
    $<TARGET_OBJECTS:camotics-cairo>
    $<TARGET_OBJECTS:camotics-stl>
    $<TARGET_OBJECTS:camotics-dxf>
    "${CMAKE_CURRENT_BINARY_DIR}/build_info.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/resources.cpp"
    "camotics.cpp")
target_compile_definitions(CAMotics PRIVATE USING_CBANG)
target_link_libraries(CAMotics PRIVATE
    Gcode DXF
    Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL Qt5::Network Qt5::WebSockets
    ${CBANG_LIBRARIES} 
)

add_executable(gcodetool 
    $<TARGET_OBJECTS:camotics-main>
    "${CMAKE_CURRENT_BINARY_DIR}/build_info.cpp"
    "gcodetool.cpp" )
target_compile_definitions(gcodetool PRIVATE USING_CBANG)
target_link_libraries(gcodetool PRIVATE
    Gcode
    ${CBANG_LIBRARIES}
)



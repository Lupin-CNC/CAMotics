set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${Cbang_INCLUDE_DIR}" 
    "${Camotics_SOURCE_DIR}/src")

add_subdirectory(gcode)
add_library(Gcode
    $<TARGET_OBJECTS:gcode-main>
    $<TARGET_OBJECTS:gcode-ast>
    $<TARGET_OBJECTS:gcode-interp>
    $<TARGET_OBJECTS:gcode-machine>
    $<TARGET_OBJECTS:gcode-parse>
    $<TARGET_OBJECTS:gcode-plan>
)
target_compile_definitions(gcode-main PRIVATE USING_CBANG)
target_compile_definitions(gcode-ast PRIVATE USING_CBANG)
target_compile_definitions(gcode-interp PRIVATE USING_CBANG)
target_compile_definitions(gcode-machine PRIVATE USING_CBANG)
target_compile_definitions(gcode-parse PRIVATE USING_CBANG)
target_compile_definitions(gcode-plan PRIVATE USING_CBANG)
target_compile_definitions(Gcode PRIVATE USING_CBANG)
add_executable(gcodetool "gcodetool.cpp" )
target_link_libraries(gcodetool PRIVATE Gcode )

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
    "camotics.cpp")
target_compile_definitions(CAMotics PRIVATE USING_CBANG)
target_link_libraries(CAMotics PRIVATE
    Gcode DXF
    Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL Qt5::Network Qt5::WebSockets
    ${CBANG_LIBRARIES} 
)

target_compile_definitions(camotics-main PRIVATE USING_CBANG)
target_compile_definitions(camotics-contour PRIVATE USING_CBANG)
target_compile_definitions(camotics-machine PRIVATE USING_CBANG)
target_compile_definitions(camotics-opt PRIVATE USING_CBANG)
target_compile_definitions(camotics-probe PRIVATE USING_CBANG)
target_compile_definitions(camotics-project PRIVATE USING_CBANG)
target_compile_definitions(camotics-qt PRIVATE USING_CBANG)
target_compile_definitions(camotics-render PRIVATE USING_CBANG)
target_compile_definitions(camotics-sim PRIVATE USING_CBANG)
target_compile_definitions(camotics-value PRIVATE USING_CBANG)
target_compile_definitions(camotics-view PRIVATE USING_CBANG)

target_link_libraries(camotics-qt PRIVATE 
    Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL Qt5::WebSockets )
target_link_libraries(camotics-view PRIVATE 
    Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL Qt5::WebSockets )

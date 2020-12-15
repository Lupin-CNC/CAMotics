add_subdirectory(ast)
add_subdirectory(interp)
add_subdirectory(machine)
add_subdirectory(parse)
add_subdirectory(plan)

set(headers
    Addresses.h
    Arc.h
    Axes.h
    Codes.h
    Controller.h
    ControllerImpl.h
    Helix.h
    ModalGroup.h
    Move.h
    MoveStream.h
    MoveType.h
    Parameter.h
    Plane.h
    Printer.h
    Processor.h
    Producer.h
    Tool.h
    ToolPath.h
    ToolShape.h
    ToolTable.h
    Units.h
    VarTypes.h
)
set(sources
    Arc.cpp
    Axes.cpp
    Codes.cpp
    ControllerImpl.cpp
    Helix.cpp
    ModalGroup.cpp
    Move.cpp
    MoveType.cpp
    Plane.cpp
    Printer.cpp
    Tool.cpp
    ToolPath.cpp
    ToolShape.cpp
    ToolTable.cpp
    Units.cpp
)
add_library(gcode-main OBJECT "${headers}" "${sources}")
target_compile_definitions(gcode-main PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/gcode)
  install(TARGETS gcode-main EXPORT CamoticsGcode-targets)
endif()

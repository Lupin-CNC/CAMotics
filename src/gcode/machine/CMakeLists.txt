set(headers
    GCodeMachine.h
    JSONMachine.h
    JSONMachineWriter.h
    MachineAdapter.h
    MachineEnum.h
    MachineInterface.h
    MachineLinearizer.h
    MachinePipeline.h
    MachineState.h
    MachineUnitAdapter.h
    MoveSink.h
    PathMode.h
    PortType.h
    Transform.h
    Transforms.h
    TransformStack.h
)
set(sources
    GCodeMachine.cpp
    JSONMachine.cpp
    MachineEnum.cpp
    MachineLinearizer.cpp
    MachinePipeline.cpp
    MachineState.cpp
    MachineUnitAdapter.cpp
    MoveSink.cpp
    PathMode.cpp
    PortType.cpp
    Transform.cpp
    Transforms.cpp
    TransformStack.cpp
)
add_library(gcode-machine OBJECT "${headers}" "${sources}")
target_compile_definitions(gcode-machine PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/gcode/machine)
  install(TARGETS gcode-machine EXPORT CamoticsGcode-targets)
endif()

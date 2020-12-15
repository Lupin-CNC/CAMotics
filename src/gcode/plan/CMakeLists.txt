set(headers
    DwellCommand.h
    EndCommand.h
    InputCommand.h
    LineCommand.h
    LinePlanner.h
    List.h
    OutputCommand.h
    PauseCommand.h
    PlannerCommand.h
    PlannerConfig.h
    Planner.h
    Runner.h
    SCurve.h
    SeekCommand.h
    SetCommand.h
)
set(sources
    DwellCommand.cpp
    InputCommand.cpp
    LineCommand.cpp
    LinePlanner.cpp
    OutputCommand.cpp
    PauseCommand.cpp
    PlannerCommand.cpp
    PlannerConfig.cpp
    Planner.cpp
    Runner.cpp
    SCurve.cpp
    SeekCommand.cpp
    SetCommand.cpp
)
add_library(gcode-plan OBJECT "${headers}" "${sources}")
target_compile_definitions(gcode-plan PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/gcode/plan)
  install(TARGETS gcode-plan EXPORT CamoticsGcode-targets)
endif()

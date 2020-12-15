set(headers
    DoLoop.h
    Evaluator.h
    GCodeInterpreter.h
    Interpreter.h
    Loop.h
    OCodeInterpreter.h
    ProducerStack.h
    ProgramProducer.h
    RepeatLoop.h
    SubroutineCall.h
    SubroutineLoader.h
)
set(sources
    DoLoop.cpp
    Evaluator.cpp
    GCodeInterpreter.cpp
    Interpreter.cpp
    Loop.cpp
    OCodeInterpreter.cpp
    ProducerStack.cpp
    ProgramProducer.cpp
    RepeatLoop.cpp
    SubroutineCall.cpp
    SubroutineLoader.cpp
)
add_library(gcode-interp OBJECT "${headers}" "${sources}")
target_compile_definitions(gcode-interp PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/gcode/interp)
  install(TARGETS gcode-interp EXPORT CamoticsGcode-targets)
endif()

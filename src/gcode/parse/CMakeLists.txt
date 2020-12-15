set(headers
    Parser.h
    Token.h
    Tokenizer.h
    TokenType.h
)
set(sources
    Parser.cpp
    Tokenizer.cpp
    TokenType.cpp
)
add_library(gcode-parse OBJECT "${headers}" "${sources}")
target_compile_definitions(gcode-parse PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/gcode/parse)
  install(TARGETS gcode-parse EXPORT CamoticsGcode-targets)
endif()

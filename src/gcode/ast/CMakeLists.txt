set(headers
    Assign.h
    BinaryOp.h
    Block.h
    Comment.h
    Entity.h
    FunctionCall.h
    NamedReference.h
    Number.h
    OCode.h
    Operator.h
    Program.h
    QuotedExpr.h
    Reference.h
    UnaryOp.h
    Word.h
)
set(sources
    Assign.cpp
    BinaryOp.cpp
    Block.cpp
    Comment.cpp
    FunctionCall.cpp
    NamedReference.cpp
    Number.cpp
    OCode.cpp
    Operator.cpp
    Program.cpp
    QuotedExpr.cpp
    Reference.cpp
    UnaryOp.cpp
    Word.cpp
)
add_library(gcode-ast OBJECT "${headers}" "${sources}")
target_compile_definitions(gcode-ast PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/gcode/ast)
  install(TARGETS gcode-ast EXPORT CamoticsGcode-targets)
endif()

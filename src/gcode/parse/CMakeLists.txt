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

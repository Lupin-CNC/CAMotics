set(headers AnnealState.h Opt.h Path.h)

set(sources AnnealState.cpp Opt.cpp Path.cpp)

add_library(camotics-opt OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-opt PRIVATE USING_CBANG)

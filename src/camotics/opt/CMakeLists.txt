set(headers AnnealState.h Opt.h Path.h)

set(sources AnnealState.cpp Opt.cpp Path.cpp)

add_library(camotics-opt OBJECT "${headers}" "${sources}")

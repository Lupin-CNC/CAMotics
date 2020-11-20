set(headers Probe.h ProbeGrid.h ProbePoint.h)

set(sources Probe.cpp ProbeGrid.cpp)

add_library(camotics-probe OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-probe PRIVATE USING_CBANG)

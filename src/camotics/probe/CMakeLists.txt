set(headers Probe.h ProbeGrid.h ProbePoint.h)

set(sources Probe.cpp ProbeGrid.cpp)

add_library(camotics-probe OBJECT "${headers}" "${sources}")

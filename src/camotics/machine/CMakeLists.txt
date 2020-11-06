set(headers MachineModel.h MachinePart.h)

set(sources MachineModel.cpp MachinePart.cpp)

add_library(camotics-machine OBJECT "${headers}" "${sources}")

set(headers MachineModel.h MachinePart.h)

set(sources MachineModel.cpp MachinePart.cpp)

add_library(camotics-machine OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-machine PRIVATE USING_CBANG)

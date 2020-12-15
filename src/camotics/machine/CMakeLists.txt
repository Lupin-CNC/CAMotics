set(headers 
    MachineModel.h 
    MachinePart.h
)
set(sources 
    MachineModel.cpp 
    MachinePart.cpp
)

add_library(camotics-machine OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-machine PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/machine)
  install(TARGETS camotics-machine EXPORT CamoticsCore-targets)
endif()

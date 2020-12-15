set(headers 
    Probe.h 
    ProbeGrid.h 
    ProbePoint.h
)
set(sources 
    Probe.cpp 
    ProbeGrid.cpp
)

add_library(camotics-probe OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-probe PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/probe)
  install(TARGETS camotics-probe EXPORT CamoticsCore-targets)
endif()

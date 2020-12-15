set(headers
    AABB.h
    AABBTree.h
    CompositeSweep.h
    ConicSweep.h
    CutSim.h
    CutWorkpiece.h
    Hit.h
    MoveLookup.h
    OctTree.h
    ReduceTask.h
    Simulation.h
    SimulationRun.h
    SpheroidSweep.h
    SurfaceTask.h
    Sweep.h
    ToolPathTask.h
    ToolSweep.h
    Workpiece.h
)
set(sources
    AABB.cpp
    AABBTree.cpp
    CompositeSweep.cpp
    ConicSweep.cpp
    CutSim.cpp
    CutWorkpiece.cpp
    OctTree.cpp
    ReduceTask.cpp
    Simulation.cpp
    SimulationRun.cpp
    SpheroidSweep.cpp
    SurfaceTask.cpp
    Sweep.cpp
    ToolPathTask.cpp
    ToolSweep.cpp
    Workpiece.cpp
)
add_library(camotics-sim OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-sim PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/sim)
  install(TARGETS camotics-sim EXPORT CamoticsCore-targets)
endif()

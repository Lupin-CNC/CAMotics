add_subdirectory(contour)
add_subdirectory(machine)
add_subdirectory(opt)
add_subdirectory(probe)
add_subdirectory(project)
add_subdirectory(render)
add_subdirectory(sim)
add_subdirectory(value)

add_subdirectory(view)
add_subdirectory(qt)

set(headers
    Application.h
    CommandLineApp.h
    ConcurrentTaskManager.h
    Grid.h
    SHA256.h
    Task.h
    TaskFilter.h
    TaskObserver.h)

set(sources Application.cpp CommandLineApp.cpp ConcurrentTaskManager.cpp
            Grid.cpp SHA256.cpp Task.cpp)

add_library(camotics-main OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-main PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics)
  install(TARGETS camotics-main EXPORT CamoticsCore-targets)
endif()

set(headers 
    RenderJob.h 
    RenderMode.h 
    Renderer.h
)
set(sources 
    RenderJob.cpp 
    RenderMode.cpp 
    Renderer.cpp
)

add_library(camotics-render OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-render PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/render)
  install(TARGETS camotics-render EXPORT CamoticsCore-targets)
endif()

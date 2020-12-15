set(headers 
    AnnealState.h 
    Opt.h 
    Path.h
)
set(sources 
    AnnealState.cpp 
    Opt.cpp 
    Path.cpp
)

add_library(camotics-opt OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-opt PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/opt)
  install(TARGETS camotics-opt EXPORT CamoticsCore-targets)
endif()

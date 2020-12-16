set(headers
    BinaryTriangle.h
    Facet.h
    Reader.h
    Sink.h
    Source.h
    Writer.h
)
set(sources
    Reader.cpp
    Sink.cpp
    Source.cpp
    Writer.cpp
)
add_library(camotics-stl OBJECT "${headers}" "${sources}")
target_include_directories(camotics-stl PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(camotics-stl PRIVATE USING_CBANG )
set_property(TARGET camotics-stl PROPERTY POSITION_INDEPENDENT_CODE 1 )

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/stl)
  install(TARGETS camotics-stl EXPORT CamoticsCore-targets)
endif()

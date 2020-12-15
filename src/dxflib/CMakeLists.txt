set(headers
    dl_attributes.h
    dl_codes.h 
    dl_creationadapter.h
    dl_creationinterface.h 
    dl_dxf.h 
    dl_entities.h
    dl_exception.h 
    dl_extrusion.h 
    dl_global.h
    dl_writer_ascii.h 
    dl_writer.h
)
set(sources
    dl_dxf.cpp 
    dl_writer_ascii.cpp
)
add_library(dxf-main OBJECT "${headers}" "${sources}")
target_compile_definitions(dxf-main PRIVATE USING_CBANG)

# if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
#  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dxflib)
#  install(TARGETS dxf-main EXPORT CamoticsDXF-targets)
# endif()

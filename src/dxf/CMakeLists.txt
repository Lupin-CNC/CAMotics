set(headers
    Arc.h
    Entity.h
    Line.h
    Point.h
    PolyLine.h
    Reader.h
    Spline.h
)
set(sources
    Reader.cpp
)
add_library(camotics-dxf OBJECT "${headers}" "${sources}")
target_include_directories(camotics-dxf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
target_compile_definitions(camotics-dxf PRIVATE USING_CBANG )
set_property(TARGET camotics-dxf PROPERTY POSITION_INDEPENDENT_CODE 1 )

set(headers 
    File.h 
    Files.h 
    Project.h 
    ResolutionMode.h 
    Workpiece.h 
    XMLHandler.h
)
set(sources 
    File.cpp 
    Files.cpp 
    Project.cpp 
    ResolutionMode.cpp 
    Workpiece.cpp
    XMLHandler.cpp
)
add_library(camotics-project OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-project PRIVATE USING_CBANG)

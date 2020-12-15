set(headers
    MemberFunctorObserver.h
    MemberFunctorValue.h
    Observer.h
    Value.h
    ValueGroup.h
    ValueSet.h
    VarValue.h
)
set(sources 
    ValueGroup.cpp 
    ValueSet.cpp
)
add_library(camotics-value OBJECT "${headers}" "${sources}")
target_compile_definitions(camotics-value PRIVATE USING_CBANG)

if("${CMAKE_PROJECT_NAME}" STREQUAL "${PROJECT_NAME}")
  install(FILES ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/camotics/value)
  install(TARGETS camotics-value EXPORT CamoticsCore-targets)
endif()

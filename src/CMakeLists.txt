set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${Cbang_INCLUDE_DIR}" 
    "${Camotics_SOURCE_DIR}/src")

add_subdirectory(camotics)

add_executable(
  camotics
  $<TARGET_OBJECTS:camotics-main>
  $<TARGET_OBJECTS:camotics-contour>
  $<TARGET_OBJECTS:camotics-machine>
  $<TARGET_OBJECTS:camotics-opt>
  $<TARGET_OBJECTS:camotics-probe>
  $<TARGET_OBJECTS:camotics-project>
  $<TARGET_OBJECTS:camotics-qt>
  $<TARGET_OBJECTS:camotics-render>
  $<TARGET_OBJECTS:camotics-sim>
  $<TARGET_OBJECTS:camotics-value>
  $<TARGET_OBJECTS:camotics-view>
  "camotics.cpp")

target_compile_definitions(camotics-main PRIVATE USING_CBANG)
target_compile_definitions(camotics-contour PRIVATE USING_CBANG)
target_compile_definitions(camotics-machine PRIVATE USING_CBANG)
target_compile_definitions(camotics-opt PRIVATE USING_CBANG)
target_compile_definitions(camotics-probe PRIVATE USING_CBANG)
target_compile_definitions(camotics-project PRIVATE USING_CBANG)
target_compile_definitions(camotics-qt PRIVATE USING_CBANG)
target_compile_definitions(camotics-render PRIVATE USING_CBANG)
target_compile_definitions(camotics-sim PRIVATE USING_CBANG)
target_compile_definitions(camotics-value PRIVATE USING_CBANG)
target_compile_definitions(camotics-view PRIVATE USING_CBANG)
target_compile_definitions(camotics PRIVATE USING_CBANG)

# target_link_libraries(camotics PRIVATE 
#    Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL
#    "${CBANG_LIBRARIES}")

target_link_libraries(camotics-qt PRIVATE
    Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL Qt5::WebSockets
    "${CBANG_LIBRARIES}")

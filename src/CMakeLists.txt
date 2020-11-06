set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}" "${camotics_SOURCE_DIR}/src")

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
target_link_libraries(camotics PRIVATE "${CBANG_LIBRARIES}")

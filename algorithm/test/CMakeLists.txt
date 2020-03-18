#test dirctory CMakeLists.txt
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(list_test list_test.cpp)
target_link_libraries(list_test algorithm tools)

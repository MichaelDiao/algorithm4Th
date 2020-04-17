#test dirctory CMakeLists.txt
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(list_test list_test.cpp)
target_link_libraries(list_test algorithm tools)

add_executable(linklist LinkList.cpp)
target_link_libraries(linklist algorithm tools)

add_executable(kmp_test kmp_test.cpp)
target_link_libraries(kmp_test algorithm tools)

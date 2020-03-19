#tools dirctory CMakeLists.txt
# SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

AUX_SOURCE_DIRECTORY(. TOOLS_DIR_SRC)
# shared library
add_library(tools SHARED ${TOOLS_DIR_SRC})

# static library
add_library(tools_static STATIC ${TOOLS_DIR_SRC})
set(tools_static PROPERTIES OUTPUT_NAME "tools")
set_target_properties(tools_static PROPERTIES CLEAN_DIRECT_OUTPUT 1 )
#CLEAN_DIRECT_OUTPUT 表示在生成具有相同名字的OUTPUT_NAME的同时，是否清理上次生成的内容，1为是
set_target_properties(tools PROPERTIES CLEAN_DIRECT_OUTPUT 1 )
set_target_properties(tools PROPERTIES VERSION 1.0 SOVERSION 1)


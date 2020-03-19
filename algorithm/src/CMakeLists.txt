
aux_source_directory(. DIR_SRC)

# shared library
add_library(algorithm SHARED ${DIR_SRC})

# static library
add_library(algorithm_static STATIC ${DIR_SRC})
SET(algorithm_static PROPERTIES OUTPUT_NAME "algorithm")
#CLEAN_DIRECT_OUTPUT 表示在生成具有相同名字的OUTPUT_NAME的同时，是否清理上次生成的内容，1为是
SET_TARGET_PROPERTIES(algorithm PROPERTIES CLEAN_DIRECT_OUTPUT 1 )
SET_TARGET_PROPERTIES(algorithm PROPERTIES VERSION 1.0 SOVERSION 1)
SET_TARGET_PROPERTIES(algorithm_static PROPERTIES CLEAN_DIRECT_OUTPUT 1 )

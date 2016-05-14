PROJECT(modern_c++)

SET(CMAKE_CXX_FLAGS "-std=c++14")

SET(SRC_DIR /Users/brucesz/git/test/modern_c++/src)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

ADD_EXECUTABLE(biggest_int ${SRC_DIR}/biggest_int.cc)
ADD_EXECUTABLE(vector_bool_magic ${SRC_DIR}/vector_bool_magic.cc)
ADD_EXECUTABLE(magical_auto ${SRC_DIR}/magical_auto.cc)
ADD_EXECUTABLE(magical_decltype ${SRC_DIR}/magical_decltype.cc)

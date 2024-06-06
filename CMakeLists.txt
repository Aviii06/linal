cmake_minimum_required(VERSION 3.28)
project(linal)

set(CMAKE_CXX_STANDARD 17)

set(LINAL_HEADERS
        src/mixins/OperationMixin.h
        src/linal.h
        src/vectors/Vec.h
        src/mixins/StdoutMixin.h)

set(LINAL_SOURCES src/mixins/VectorOperationMixin.cpp)


add_library(linal STATIC ${LINAL_SOURCES} ${LINAL_HEADERS})
target_include_directories(linal PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

add_subdirectory(examples)


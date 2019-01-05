cmake_minimum_required(VERSION 3.8)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR C:/Projects/MinGW/include/)
set(Boost_LIBRARY_DIR C:/Projects/MinGW/lib/)
find_package(Boost COMPONENTS regex REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES start/Main.cpp
        frame/include/matrix/Matrix.h frame/src/matrix/Matrix.cpp
        frame/include/matrix/NumericMatrix.h frame/src/matrix/NumericMatrix.cpp
        frame/include/matrix/BoolMatrix.h frame/src/matrix/BoolMatrix.cpp frame/include/MyAux.h frame/src/MyAux.cpp)

add_executable(lab5 ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.28)

project(ch5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(opencvtest opencvtest.cpp)

target_link_libraries(opencvtest ${OpenCV_LIBS})
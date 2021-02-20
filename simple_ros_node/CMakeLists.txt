cmake_minimum_required(VERSION 2.8.3)
project(simple_ros_node)

## Compile as C++11, supported in ROS kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
set(catkin_deps
        roscpp
        std_msgs
        )

find_package(catkin REQUIRED COMPONENTS
        ${catkin_deps}
        )

message(STATUS "CMAKE SOURCE DIR:" ${CMAKE_MODULE_PATH} )

catkin_package(
        INCLUDE_DIRS include
        CATKIN_DEPENDS ${catkin_deps}
)

## Build ##

## Specify additional locations of header files
## your package locations should be listed before other locations
include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)

## declare a C++ library
add_library(${PROJECT_NAME}_lib1
        src/lib1.cpp
        )

## build your executable project
add_executable(${PROJECT_NAME}
        src/simple_ros_node.cpp
        src/example_core.cpp
        )

## link libraries used in the project above
target_link_libraries(${PROJECT_NAME}
        ${catkin_LIBRARIES}
        ${PROJECT_NAME}_lib1
        )

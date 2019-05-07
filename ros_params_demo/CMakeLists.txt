cmake_minimum_required(VERSION 2.8.3)
project(ros_params_demo)

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

## build your executable project
add_executable(${PROJECT_NAME}
        src/simple_ros_node.cpp
        src/ros_params_demo.cpp
        )

## link libraries used in the project above
target_link_libraries(${PROJECT_NAME}
        ${catkin_LIBRARIES}
        )

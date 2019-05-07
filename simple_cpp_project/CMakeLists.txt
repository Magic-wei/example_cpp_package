cmake_minimum_required(VERSION 3.5)

# project name
project(simple_cpp_project)

# enable c++11 feature 
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 ${CMAKE_CXX_FLAGS}")

# declare the include directories 
include_directories(
        include
        )

#######################################################
####     How to add a library for a project 
#######################################################

################## add lib1 ########################################
add_library(${PROJECT_NAME}_lib1 SHARED
        src/lib1.cpp
        )
# link other thirdparty libraries for your ${PROJECT_NAME}_lib1
target_link_libraries(${PROJECT_NAME}_lib1
        )

#######################################################
#####   How to add an executable example that links libs 
#######################################################

##################    example 1   #########################################
####    How to add an executable example that links lib1 lib2 and thirdparty libraries 
add_executable(${PROJECT_NAME}_main
        src/main.cpp)

# link library1 for example 1
target_link_libraries(${PROJECT_NAME}_main
        ${PROJECT_NAME}_lib1)



//
// Created by wangwei on 18-7-24.
//

// ROS Includes
#include <ros/ros.h>

// User defined includes
#include "example_core.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "simple_ros_node");
    example_core::example_core test;
    test.run();
    return 0;
}



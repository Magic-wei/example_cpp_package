// ROS Includes
#include <ros/ros.h>

// User defined includes
#include "ros_params_demo.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "ros_params_demo");
    rosparamsDemo::rosparamsDemo test;
    test.run();
    return 0;
}



//
// Created by wangwei on 18-7-24.
//

#ifndef SIMPLE_ROS_NODE_EXAMPLE_CORE_H
#define SIMPLE_ROS_NODE_EXAMPLE_CORE_H

#include "lib1.h"

#include"ros/ros.h"
#include"std_msgs/Float32.h"
#include"std_msgs/String.h"
#include<string>
#include<vector>
#include<iostream>

namespace example_core {

class example_core
{
public:
    example_core();
    void callbackState(const std_msgs::String msg);
    void callbackSensorData(const std_msgs::Float32 msg);

    lib1::lib1 cmdtest;

    ros::NodeHandle n;
    ros::Subscriber sensor_sub ,state_sub;
    ros::Publisher vel_pub ,str_pub;

    std::string id_;
    bool is_sensor_update;
    bool is_state_update;
    std_msgs::Float32 sensor_data;
    std_msgs::String state;
    std_msgs::Float32 cmd2;
    std_msgs::Float32 cmd1;

    void run();

};
}
#endif /* SIMPLE_ROS_NODE_EXAMPLE_CORE_H */

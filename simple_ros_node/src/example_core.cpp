//
// Created by wangwei on 18-7-24.
//

#include "example_core.h"
namespace example_core {

example_core::example_core()
:is_sensor_update(false)
,is_state_update(false)
,id_("example_core")
,cmdtest(1.2)
{
    /** We subscribe two topics and
     *  publish two topics in this ros node.
     */
    state_sub = n.subscribe("state1", 10, &example_core::callbackState, this);
    sensor_sub = n.subscribe("sensor1", 10, &example_core::callbackSensorData, this);
    str_pub = n.advertise<std_msgs::Float32>("cmd1",10);
    vel_pub = n.advertise<std_msgs::Float32>("cmd2",10);
    cmd1.data = 0.0;
    cmd2.data = 0.0;
    sensor_data.data = 0.0;
    state.data = "init";
}
void example_core::callbackSensorData(const std_msgs::Float32 msg) {
    this->sensor_data = msg;
    is_sensor_update = true;
}
void example_core::callbackState(const std_msgs::String msg) {
    this->state = msg;
    is_state_update = true;
}

void example_core::run() {
    ROS_INFO("simple-ros-node start ------");
    ros::Rate loop_rate(10); // control rate: 10 Hz
    while(ros::ok())
    {
        ros::spinOnce();
        double time_cost = ros::Time::now().toSec();

    cmdtest.generateCmd(this->sensor_data.data, this->state.data);
        this->cmd1.data = cmdtest.getCmd1();
        this->cmd2.data = cmdtest.getCmd2();
        ROS_INFO("%s Subscribe:{ state: %s ,sensor_data: %.3f }; Publish:{ cmd1: %.2f , cmd2: %.2f }.",
                 id_.c_str(), state.data.c_str(), sensor_data.data, cmd1.data, cmd2.data);

        str_pub.publish(cmd1);
        vel_pub.publish(cmd2);

        time_cost = (ros::Time::now().toSec() - time_cost)*1000; // convert unit from sec to ms

        ROS_WARN("time_cost: %.2f ms",time_cost);

        is_sensor_update = false;
        is_state_update = false;
    }
}
}


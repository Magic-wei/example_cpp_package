#ifndef ROS_PARAMS_DEMO_ROS_PARAMS_DEMO_H_
#define ROS_PARAMS_DEMO_ROS_PARAMS_DEMO_H_

#include"ros/ros.h"
#include"std_msgs/Float32.h"
#include"std_msgs/String.h"
#include<string>
#include<vector>
#include<iostream>

namespace rosparamsDemo {

class rosparamsDemo {
public:
    rosparamsDemo();
	void callbackState(const std_msgs::String msg);
	void callbackSensorData(const std_msgs::Float32 msg);
    void initParameters();
    void printParameters() const;
	void run();

	ros::NodeHandle n;
	ros::NodeHandle private_n_;
	ros::Subscriber sensor_sub ,state_sub;
    ros::Publisher vel_pub ,str_pub;

	// rosparams yaml
	std::string state_topic_;
	std::string sensor_topic_;
	std::string cmd1_topic_;
	std::string cmd2_topic_;
	std::string program_id_;
	int rate;
	double float_var;
	bool Boolean_var;
	std::vector<double> list_vars;
	std::map<std::string, int> dictionary_vars;


};
}
#endif /* ROS_PARAMS_DEMO_ROS_PARAMS_DEMO_H_ */

#include "ros_params_demo.h"
namespace rosparamsDemo {

rosparamsDemo::rosparamsDemo(): private_n_(ros::NodeHandle("~")) // private nodeHandle
{
    initParameters();
    printParameters();
	state_sub = n.subscribe(this->state_topic_, 10, &rosparamsDemo::callbackState, this);
	sensor_sub = n.subscribe(this->sensor_topic_, 10, &rosparamsDemo::callbackSensorData, this);
	str_pub = n.advertise<std_msgs::Float32>(this->cmd1_topic_,10);
	vel_pub = n.advertise<std_msgs::Float32>(this->cmd2_topic_,10);
}
void rosparamsDemo::initParameters(){
    auto &pnh = this->private_n_;
    this->state_topic_ = pnh.param<std::string>("state_topic_", "state1");
    this->sensor_topic_ = pnh.param<std::string>("sensor_topic_", "sensor1");
    this->cmd1_topic_ = pnh.param<std::string>("state_topic_", "cmd1");
    this->cmd2_topic_ = pnh.param<std::string>("sensor_topic_", "cmd2");
    this->program_id_ = pnh.param<std::string>("sensor_topic_", "ros_params_demo");
    this->rate = pnh.param("publish_rate", 10);
    this->float_var = pnh.param("float_data", 10.0);
    this->Boolean_var = pnh.param("Boolean_var", false);
    this->list_vars = pnh.param<std::vector<double>>("list_vars", {0.1,10});
    this->dictionary_vars = pnh.param<std::map<std::string,int>>("dictionary_vars", { {"a",27},{"b",12},{"c",2} });
}
void rosparamsDemo::printParameters() const {
    ROS_INFO_STREAM("Using state_topic_ = " << this->state_topic_);
    ROS_INFO_STREAM("Using sensor_topic_ = " << this->sensor_topic_);
    ROS_INFO_STREAM("Using cmd1_topic_ = " << this->cmd1_topic_);
    ROS_INFO_STREAM("Using cmd2_topic_ = " << this->cmd2_topic_);
    ROS_INFO_STREAM("Using program_id_ = " << this->program_id_);
    ROS_INFO_STREAM("Using rate = " << this->rate);
    ROS_INFO_STREAM("Using float_var = " << this->float_var);
    ROS_INFO_STREAM("Using Boolean_var = " << this->Boolean_var);
    std::string str = "Using list_vars = [ ";
    for (const auto &n:list_vars) {
        str += std::to_string(n) + " ";
    }
    str += "]";
    ROS_INFO_STREAM(str);
    str = "Using Boolean_var = { ";
    for (const auto &p:dictionary_vars) {
        str += p.first + ":" + std::to_string(p.second) + " ";
    }
    str += "}";
    ROS_INFO_STREAM(str);
}
void rosparamsDemo::callbackSensorData(const std_msgs::Float32 msg) {
    ROS_INFO("get msg from topic %s: %f", sensor_topic_.c_str(), msg.data);
}
void rosparamsDemo::callbackState(const std_msgs::String msg) {
    ROS_INFO("get msg from topic %s: %f", state_topic_.c_str(), msg.data);
}

void rosparamsDemo::run() {
    ROS_INFO("ros_params_demo start ------");
    ROS_INFO("%s Subscribe:{ state_topic: %s ,sensor_topic: %s }; Publish:{ cmd1_topic: %s , cmd2_topic: %s }.",
             program_id_.c_str(), state_topic_.c_str(), sensor_topic_.c_str(), cmd1_topic_.c_str(), cmd2_topic_.c_str());
	ros::Rate loop_rate(this->rate);

    // Set and get some params
    n.setParam("/global_param", 5);
    n.setParam("relative_param", "my_string");
    n.setParam("bool_param", false);

    int global_param;
    std::string my_string;
    bool bool_param;
    ros::param::get("/global_param", global_param);
    ros::param::get("relative_param", my_string);
    ros::param::get("bool_param", bool_param);

    ROS_INFO("global_param is %d, relative_param is %s, bool_param is %d", global_param, my_string.c_str(), bool_param);

    // change values of these parameters
    ros::param::set("/worksapce/global_param", 15);
    ros::param::set("/worksapce/relative_param", "your_string");
    ros::param::set("/worksapce/bool_param", true);

    n.getParam("/worksapce/global_param", global_param);
    n.getParam("/worksapce/relative_param", my_string);
    n.getParam("/worksapce/bool_param", bool_param);

    ROS_INFO("Changing: global_param is %d, relative_param is %s, bool_param is %d", global_param, my_string.c_str(), bool_param);

    // Construct a map of strings
    ROS_INFO("Construct a map of strings:");
    std::map<std::string,std::string> map_s, map_s2;
    map_s["a"] = "foo";
    map_s["b"] = "bar";
    map_s["c"] = "baz";

    // Set and get a map of strings
    n.setParam("my_string_map", map_s);
    n.getParam("my_string_map", map_s2);
    for (const auto &pair : map_s2) {
        ROS_INFO("map_s2[%s] = %s",pair.first.c_str(), pair.second.c_str());
    }

    // Sum a list of doubles from the parameter server
    std::vector<double> my_double_list1 = {1.0, 3.1, 53.8};
    std::vector<double> my_double_list;
    n.setParam("my_double_list",my_double_list1);
    double sum = 0;
    if(n.getParam("my_double_list", my_double_list)){
        for(unsigned i=0; i < my_double_list.size(); i++) {
            sum += my_double_list[i];
        }
    }else{
        ROS_ERROR("No found my_double_list!");
    }

	while(ros::ok()) {
		ros::spinOnce();
	}
}
}


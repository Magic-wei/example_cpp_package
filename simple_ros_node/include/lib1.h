//
// Created by wangwei on 18-7-24.
//

#ifndef SIMPLE_ROS_NODE_LIB1_H
#define SIMPLE_ROS_NODE_LIB1_H

#include <cmath>
#include <string>

namespace lib1 {

class lib1 {
public:
    lib1();
    explicit lib1(float K);
    ~lib1();

    void generateCmd(float sensor, std::string state);
    float getCmd1();
    float getCmd2();

private:
    float cmd1;
    float cmd2;
    float k;
};

}
#endif /* SIMPLE_ROS_NODE_LIB1_H */

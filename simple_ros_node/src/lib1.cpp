//
// Created by wangwei on 18-7-24.
//

#include "lib1.h"

namespace lib1 {

lib1::lib1():k(1.0),cmd1(0.0),cmd2(0.0) { }
lib1::lib1(float K):k(K),cmd1(0.0),cmd2(0.0) { }

lib1::~lib1() = default;

void lib1::generateCmd(float sensor, std::string state){
    if("forward" == state ){
        this->cmd1 = k * sensor;
        this->cmd2 = std::sin(sensor);
    }else if( "reverse" == state ){
        this->cmd1 = -k * sensor;
        this->cmd2 = std::cos(sensor);
    }
}

float lib1::getCmd1() {
    return this->cmd1;
}

float lib1::getCmd2() {
    return this->cmd2;
}

}

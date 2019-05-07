//
// Created by wangwei on 18-7-26.
//

#ifndef SIMPLE_CPP_PROJECT_LIB1_H
#define SIMPLE_CPP_PROJECT_LIB1_H

#include <iostream>

namespace GWZPrograms {

class lib1 {
public:
    lib1();
    ~lib1();
    void hello();
    double sum(double a, double b);
    bool getFlag();
    int getCount();
    double getResult();
private:
    bool flag;
    int count; // record how many times the functions in the class lib1 are used
    double sum_result;
};

}

#endif //SIMPLE_CPP_PROJECT_LIB1_H

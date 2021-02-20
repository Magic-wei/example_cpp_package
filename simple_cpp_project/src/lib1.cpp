//
// Created by wangwei on 18-7-26.
//

#include "lib1.h"

using std::cout;
using std::endl;

namespace simple_cpp_project {

lib1::lib1() {
    this->flag = false;
    this->count = 0;
    this->sum_result = 0.0;
    hello();
}

lib1::~lib1() {
    cout << "this is the end of lib1." << endl;
    cout << "The functions in the class lib1 are used " << this->count << " times" << endl;
    cout << "sum_result = " << this->sum_result << endl;
}

int lib1::getCount() {
    this->count++;
    return this->count;
}

bool lib1::getFlag() {
    this->count++;
    return this->flag;
}

double lib1::getResult() {
    this->count++;
    return this->sum_result;
}

void lib1::hello() {
    cout << "say hello from lib1." << endl;
    this->count++;
}

double lib1::sum(double a, double b) {
    this->count++;
    this->sum_result = a + b;
    return this->sum_result;
}

}
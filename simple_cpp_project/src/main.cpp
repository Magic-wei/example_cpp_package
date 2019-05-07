/*
 *  simple_cpp_project
 *
 *  Created by wangwei on 18-7-26.
 */

#include "lib1.h"
#include <iostream>

using namespace std;

int main() {

    GWZPrograms::lib1 test;

    double result = test.sum(1.0, 5.3);

    cout << "the end flag is " << test.getFlag() << endl;
    cout << "the count is " << test.getCount() << endl;
    cout << "the last sum result is " << test.getResult() << endl;

    cout << "- End of main -" << endl;

    return 0;
}

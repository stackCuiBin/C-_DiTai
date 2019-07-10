/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 10 Jul 2019 11:00:18 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include "Operator.h"

using namespace std;

int main(int argc, const char* argv[])
{
	Operator<int> op1;

	cout << op1.add(1, 2) << endl;
	cout << op1.minus(2, 3) << endl;

    return 0;
}

/*************************************************************************
 ******* File Name: func_default_para.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 20 May 2019 11:37:36 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

int mul(int x = 0);

int main(int argc, char** argv)
{
	cout << "mul() = " << mul() << endl;
	cout << "mul(-1) = " << mul(-1) << endl;
	cout << "mul(2) = " << mul(2) << endl;

	return 0;
}

int mul(int x)
{
	return x * x;
}

/*
 * result:
 * mul() = 0
 * mul(-1) = 1
 * mul(2) = 4
 */

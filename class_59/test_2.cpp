/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 10 Jul 2019 11:55:19 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

template
<typename T>
bool Equal(T a, T b)
{
	cout << "bool Equal(T a, T b)" << endl;

	return a == b;
}

template
<>
bool Equal<double>(double a, double b)
{
	const double delta = 0.00001;
	double r = a - b;

	cout << "bool Equal<double>(double a, double b)" << endl;

	return (-delta < r) && (r < delta);
}

bool Equal(double a, double b)
{
	const double delta = 0.00001;
	double r = a - b;

	cout << "bool Equal(double a, double b)" << endl;

	return (-delta < r) && (r < delta);
}

int main(int argc, const char* argv[])
{
	cout << Equal(1, 1) << endl << endl;
	cout << Equal<>(0.001, 0.001) << endl << endl;
	cout << Equal(0.001, 0.001) << endl;

    return 0;
}

/*
 * result:
 * bool Equal(T a, T b)
 * 1
 *
 * bool Equal<double>(double a, double b)
 * 1
 *
 * bool Equal(double a, double b)
 * 1
 */

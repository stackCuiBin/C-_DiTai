/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 14 Jul 2019 05:57:06 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

double divide(double a, double b)
{
	const double delta = 0.00001;
	double ret = 0;

	if(!((-delta < b) && (b < delta)))
	{
		ret = a/b;
	}
	else
	{
		throw 0;
	}

	return ret;
}

int main(int argc, const char* argv[])
{
	try
	{
		double r = divide(1, 0);

		cout << "r = " << r << endl;
	}
	catch(...)
	{
		cout << "Divide by zero..." << endl;
	}

    return 0;
}

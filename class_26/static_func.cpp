/*************************************************************************
 ******* File Name: static_func.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 05 Jun 2019 11:21:27 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Demo
{
private:
	int i;
public:
	int getI();
	static void StaticFunc(const char* s);
	static void StaticSetI(Demo& d, int v);
};

int Demo::getI()
{
	return i;
}

void Demo::StaticFunc(const char* s)
{
	cout << "StaticFunc: " << s << endl;
}

void Demo::StaticSetI(Demo& d, int v)
{
	d.i = v;
}

int main(int argc, char** argv)
{
	Demo::StaticFunc("main begin...");

	Demo d;
	Demo::StaticSetI(d, 10);
	cout << "d.i = " << d.getI() << endl;

	Demo::StaticFunc("main end...");

    return 0;
}

/*
 * result:
 * StaticFunc: main begin...
 * d.i = 10
 * StaticFunc: main end...
 */

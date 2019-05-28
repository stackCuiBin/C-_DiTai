/*************************************************************************
 ******* File Name: constructor_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 27 May 2019 08:24:29 AM PDT
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
private:
	int value;

public:
	Test()
	{
		cout << "Test()" << endl;
		value = 0;
	}
	Test(int v)
	{
		cout << "Test(int v), v = " << v << endl;
		value = v;
	}
	int getValue()
	{
		return value;
	}
};

int main(int argc, char** argv)
{
	Test ta[3] = {Test(), Test(1), Test(2)};	// 手动调用构造函数

	for(int i=0; i<3; i++)
	{
		cout << "ta[" << i <<"].getValue() = " << ta[i].getValue() << endl;
	}

	Test t = Test(100);		// 手动调用构造函数
	cout << "t.getValue() = " << t.getValue() << endl;

    return 0;
}

/*
 * result:
 * Test()
 * Test(int v), v = 1
 * Test(int v), v = 2
 * ta[0].getValue() = 0
 * ta[1].getValue() = 1
 * ta[2].getValue() = 2
 * Test(int v), v = 100
 * t.getValue() = 100
 */

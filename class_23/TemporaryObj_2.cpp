/*************************************************************************
 ******* File Name: TemporaryObj_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 30 May 2019 08:42:09 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
private:
	int mi;
	void init(int v)
	{
		mi = v;
	}
public:
	Test(int val)
	{
		cout << "Test(int val)" << endl;
		init(val);
	}
	Test()
	{
		cout << "Test()" << endl;
		//Test(0);	//从运行结果来看产生临时对象，生命周期只在这一行
		init(0);
	}
	void print()
	{
		cout << "mi = " << mi << endl;;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
};

int main(int argc, char** argv)
{
	cout << "main begin" << endl;

	Test().print();
	Test(10).print();

	cout << "main end" << endl;
    return 0;
}

/*
 * result:
 * main begin
 * Test()
 * mi = 0
 * ~Test()
 * Test(int val)
 * mi = 10
 * ~Test()
 * main end
 */

/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 15 Jul 2019 10:46:04 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

void demo()
{
	try
	{
		try
		{
			throw 0;
		}
		catch(int i)
		{
			cout << "Inner: catch(int i)" << endl;
			throw i;
		}
		catch(...)
		{
			cout << "Inner: catch(...)" << endl;
			throw;
		}
	}
	catch(...)
	{
		cout << "outer: catch(...)" << endl;
	}
}

/*
 * 假设：当前的函数是第三方库中的函数，因此，我们无法修改源码
 *
 * 函数名：void fucn(int i)
 * 抛出的异常的类型：
 * 	int
 * 		-1 ==> 参数异常
 * 		-2 ==> 运行异常
 * 		-3 ==> 超时异常
 */
void func(int i)
{
	if(i < 0)
	{
		throw -1;
	}

	if(i > 100)
	{
		throw -2;
	}

	if(i == 11)
	{
		throw -3;
	}

	cout << "Run Func..." << endl;
}

void MyFunc(int i)
{
	try
	{
		func(i);
	}
	catch(int i)
	{
		switch(i)
		{
			case -1:
				throw "Invalid Parameter";
				break;
			case -2:
				throw "Runtime Exception";
				break;
			case -3:
				throw "Timeout Exception";
				break;
		}
	}
}

int main(int argc, const char* argv[])
{
	demo();

	try
	{
		MyFunc(11);
	}
	catch(const char* cs)
	{
		cout << "Exception info : " << cs << endl;
	}

    return 0;
}

/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 15 Jul 2019 11:08:46 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Base
{
};

class Exception : public Base
{
	int m_id;
	string m_desc;

public:
	Exception(int id, string desc)
	{
		m_id = id;
		m_desc = desc;
	}

	int id() const
	{
		return m_id;
	}

	string description() const
	{
		return m_desc;
	}
};

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
				throw Exception(-1, "Invalid Parameter");
				break;
			case -2:
				throw Exception(-2, "Runtime Exception");
				break;
			case -3:
				throw Exception(-3, "Timeout Exception");
				break;
		}
	}
}

int main(int argc, const char* argv[])
{
	try
	{
		MyFunc(11);
	}
	catch(const Exception& e)
	{
		cout << "Exception info:" << endl;
		cout << "	ID: " << e.id() << endl;
		cout << "	Description: " << e.description() << endl;
	}
	catch(const Base& b)
	{
		cout << "catch(const Base& b)" << endl;
	}

    return 0;
}

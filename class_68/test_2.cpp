/*************************************************************************
 ******* File Name: test_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 17 Jul 2019 10:33:48 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test_1
{
public:
	static const int TS = 0;
};

class Test_2
{
public:
	struct TS
	{
		int value;
	};
};

int a = 0;

template
< class T >
void test_class()
{
	typename T::TS * a;		// 1，通过泛指类型T内部的数据类型TS定义指针变量。(推荐理解方式)
							// 2，使用泛指类型T内部的静态成员变量TS与全局变量a相乘。
}

int main(int argc, const char* argv[])
{
	test_class<Test_1>();
	test_class<Test_2>();

    return 0;
}

/*
 * result:
 *
 * 1,当test_class()中为 typename T::TS * a时
 * test_class<Test_1>();
 * 编译出错
 *
 * 2,当test_class()中为T::TS * a时
 * test_class<Test_2>();
 * 编译出错
 *
 */

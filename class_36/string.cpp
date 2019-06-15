/*************************************************************************
 ******* File Name: string.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 15 Jun 2019 02:17:30 PM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string s = "12345";
	const char* p = s.c_str();	// 混合C语言和C++写法

	cout << p << endl;

	s.append("abcdef");	// s 的地址可能会发生变化

	cout << p << endl;	// p 可能会变成野指针

    return 0;
}


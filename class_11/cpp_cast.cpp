/*************************************************************************
 ******* File Name: cpp_cast.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 22 May 2019 10:46:47 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

void static_cast_demo()
{
	int i = 0x1234;
	char c = 'c';
	int* pi = &i;
	char* pc = &c;

	c = static_cast<char>(i);
	//pc = static_cast<char*>(pi);	// error
}

void const_cast_demo()
{
	const int& j = 1;
	int& k = const_cast<int&>(j);

	const int x = 2;
	int& y = const_cast<int&>(x);

	//int z = const_cast<int>(x);		// error 

	k = 5;

	cout << "k = " << k << endl;
	cout << "j = " << j << endl;

	y = 8;

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "&x = " << &x << endl;
	cout << "&y = " << &y << endl;
}

void reinterpret_cast_demo()
{
	int i = 0;
	char c = 'c';
	int* pi = &i;
	char* pc = &c;

	pc = reinterpret_cast<char*>(pi);
	pi = reinterpret_cast<int*>(pc);
	pi = reinterpret_cast<int*>(i);
	//c = reinterpret_cast<char>(i);	// error
}

void dynamic_cast_demo()
{
	int i = 0;
	int* pi = &i;
	//char* pc = dynamic_cast<char*>(pi);	// error
}

int main(int argc, char** argv)
{
	static_cast_demo();
	const_cast_demo();
	//reinterpret_cast_demo();
	//dynamic_cast_demo();

	return 0;
}

/*
 * result:
 * k = 5
 * j = 5
 * x = 2
 * y = 8
 * &x = 0x7fff13359a08
 * &y = 0x7fff13359a08
 *
 * note:
 * x和y的值不同，x的值在符号表中，编译期间就已确定，详细看const讲解
 */

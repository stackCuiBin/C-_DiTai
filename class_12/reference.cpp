/*************************************************************************
 ******* File Name: reference.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 23 May 2019 11:38:24 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

int a = 1;

struct SV
{
	int& x;
	int& y;
	int& z;
};

int main(int argc, char** argv)
{
	int b = 2;
	int* pc = new int(3);
	SV sv = {a, b, *pc};
	//int& array[] = {a, b, *pc};	// conpile error

	cout << "&sv.x = " << &sv.x << endl;
	cout << "&sv.y = " << &sv.y << endl;
	cout << "&sv.z = " << &sv.z << endl;

	return 0;
}

/*
 * result:
 * &sv.x = 0x601078
 * &sv.y = 0x7ffc0b1842f4
 * &sv.z = 0xe11c20
 * 
 * different addr
 * C++继承了C数组地址连续的特性，如果为引用数组，&array[1] - &array[0] = ? Expected ==> 8 (my 64 ubuntu)
 * 从上述打印的地址看出，明显差值不为8.
 * 
 * C++不支持引用数组！！！
 */

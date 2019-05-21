/*************************************************************************
 ******* File Name: OverLoad_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 21 May 2019 11:31:58 PM CST
 ************************************************************************/

#include <iostream>

#ifdef __cplusplus
extern "C"
{
#endif

#include "add.h"

#ifdef __cplusplus
}
#endif

using namespace std;

int main(int argc, char** argv)
{
	int c = add(1, 2);

	cout << "c = " << c << endl;

	return 0;
}

/*
 * note
 * first cmd:  gcc -o add.o -c add.c
 * second cmd: g++ OverLoad_2.cpp add.0
 *
 * in addition
 * cmd: 'nm add.o'
 * can check if there is an add function in the add.o library
 */

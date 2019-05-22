/*************************************************************************
 ******* File Name: type_convert.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 22 May 2019 10:18:47 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

#define C_type_cast

#ifdef C_type_cast

/* Typical error in C language */

typedef void(PF)(int);

struct Point
{
	int x;
	int y;
};

int main(int argc, char** argv)
{
	int v = 0x1234;
	PF* pf = (PF*)v;
	char c = char(v);
	Point* p = (Point*)v;

	pf(10);

	cout << "p->x = " << p->x << endl;
	cout << "p->y = " << p->y << endl;

	return 0;
}

/*
 * result:
 * Segmentation fault (core dumped)
 */

#endif

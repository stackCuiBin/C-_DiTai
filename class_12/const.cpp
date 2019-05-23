/*************************************************************************
 ******* File Name: const.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 23 May 2019 10:07:47 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	const int x = 1;	// The compiler allocated an address space for the x variable, but it was not used. 
	const int& rx = x;	// using the address space of x

	int& nrx = const_cast<int&>(rx);
	nrx = 5;

	cout << "x = " << x << endl;
	cout << "rx = " << rx << endl;
	cout << "nrx = " << nrx << endl;
	cout << "&x = " << &x << endl;
	cout << "&rx = " << &rx << endl;
	cout << "&nrx = " << &nrx << endl;
	cout << endl << endl;

	volatile const int y = 2;
	int* p = const_cast<int*>(&y);
	*p = 6;

	cout << "y = " << y << endl;
	cout << "p = " << p << endl;
	cout << endl << endl;

	const int z = y;
	p = const_cast<int*>(&z);
	*p = 7;

	cout << "z = " << z << endl;
	cout << "p = " << p << endl;
	cout << endl << endl;

	char c = 'c';
	char& rc = c;
	const int& trc = c;	// new read-only variable
	rc = 'a';

	cout << "c = " << c << endl;
	cout << "rc = " << rc << endl;
	cout << "trc = " << (char)trc << endl;
	cout << "&c = " << static_cast<void*>(&c) << endl;
	cout << "&rc = " << (void*)&rc << endl;
	cout << "&trc = " << &trc << endl;
	return 0;
}

/*
 * result:
 * x = 1
 * rx = 5
 * nrx = 5
 * &x = 0x7ffd07411210
 * &rx = 0x7ffd07411210
 * &nrx = 0x7ffd07411210
 * same addr
 *
 * y = 6
 * p = 0x7ffd07411214
 * legal addr
 *
 * z = 7
 * p = 0x7ffd07411218
 * legal addr
 *
 * c = a
 * rc = a
 * trc = c
 * &c = 0x7ffd0741120f
 * &rc = 0x7ffd0741120f
 * &trc = 0x7ffd0741121c
 * different addr, trc is new read-only variable
 * /

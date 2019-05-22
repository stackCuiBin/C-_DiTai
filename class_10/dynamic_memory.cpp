/*************************************************************************
 ******* File Name: dynamic_memory.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 22 May 2019 09:11:47 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

#define test_dynamic_memory
//#define test_namespace 

#ifdef test_dynamic_memory
int main(int argc, char** argv)
{
	int* p = new int;

	*p = 5;
	*p = *p + 10;

	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;

	delete p;

	p = new int[10];	// Actually it might be more than 40 bytes.

	for(int i=0; i<10; i++)
	{
		p[i] = i + 1;
		cout << "p[" << i << "] = " << p[i] << endl;
	}

	delete[] p;

	return 0;
}

/*
 * result:
 * p = 0x12cfc20
 * *p = 15
 * p[0] = 1
 * p[1] = 2
 * p[2] = 3
 * p[3] = 4
 * p[4] = 5
 * p[5] = 6
 * p[6] = 7
 * p[7] = 8
 * p[8] = 9
 * p[9] = 10
 */

#endif

#ifdef test_namespace 

namespace First
{
	int i = 0;
}

namespace Second
{
	int i = 1;

	namespace Internal
	{
		struct P
		{
			int x;
			int y;
		};
	}
}

int main(int argc, char** argv)
{
	using namespace First;
	using Second::Internal::P;

	cout << "First::i = " << i << endl;
	cout << "Second::i = " << Second::i << endl;

	P p = {2, 3};

	cout << "p.x = " << p.x << endl;
	cout << "p.y = " << p.y << endl;

	return 0;
}

/*
 * result:
 * First::i = 0
 * Second::i = 1
 * p.x = 2
 * p.y = 3
 */

#endif 

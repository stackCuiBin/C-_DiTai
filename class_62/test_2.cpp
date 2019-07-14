/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 14 Jul 2019 10:54:23 AM CST
 ************************************************************************/

#include <iostream>
#include "Singleton.h"

using namespace std;

class Sobject
{
	friend class Singleton<Sobject>;

	Sobject(const Sobject&);
	Sobject& operator = (const Sobject&);

	Sobject()
	{
	};

public:

	void print()
	{
		cout << "this = " << this << endl;
	}
};

int main(int argc, const char* argv[])
{
	Sobject* s = Singleton<Sobject>::GetInstance();
	Sobject* s1 = Singleton<Sobject>::GetInstance();
	Sobject* s2 = Singleton<Sobject>::GetInstance();

	s->print();
	s1->print();
	s2->print();

    return 0;
}

/*
 * result:
 *
 * this = 0x10c8c20
 * this = 0x10c8c20
 * this = 0x10c8c20
 */

/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 14 Jul 2019 10:54:23 AM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Sobject
{
	static Sobject* c_instance;

	Sobject(const Sobject&);
	Sobject& operator = (const Sobject&);

	Sobject()
	{
	};
public:
	static Sobject* GetInstance();

	void print()
	{
		cout << "this = " << this << endl;
	}
};

Sobject* Sobject::c_instance = NULL;

Sobject* Sobject::GetInstance()
{
	if( c_instance == NULL)
	{
		c_instance = new Sobject();
	}

	return c_instance;
}

int main(int argc, const char* argv[])
{
	Sobject* s = Sobject::GetInstance();
	Sobject* s1 = Sobject::GetInstance();
	Sobject* s2 = Sobject::GetInstance();

	s->print();
	s1->print();
	s2->print();

    return 0;
}

/*
 * result:
 *
 * this = 0xc03c20
 * this = 0xc03c20
 * this = 0xc03c20
 */

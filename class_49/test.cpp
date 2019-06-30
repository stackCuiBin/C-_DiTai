/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 30 Jun 2019 11:24:34 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
public:
	virtual void print()
	{
		cout << "I'm Parent." << endl;
	}
};

class Child : public Parent
{
public:
	/* 也是virtual，省略了 */
	void print()
	{
		cout << "I'm Child." << endl;
	}
};

void how_to_print(Parent* p)
{
	p->print();
}

int main(int argc, const char* argv[])
{
	Parent p;
	Child c;

	how_to_print(&p);	// I'm Parent
	how_to_print(&c);	// I'm Child

    return 0;
}

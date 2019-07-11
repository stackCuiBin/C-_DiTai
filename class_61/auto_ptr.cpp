/*************************************************************************
 ******* File Name: auto_ptr.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Thu 11 Jul 2019 10:49:52 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Test
{
	string m_name;
public:
	Test(const char* name)
	{
		cout << "hello, " << name << "." << endl;

		m_name = name;
	}

	void print()
	{
		cout << "I'm " << m_name << "." << endl;
	}

	~Test()
	{
		cout << "Goodbye, " << m_name << "." << endl;
	}
};

int main(int argc, const char* argv[])
{
	auto_ptr<Test> pt(new Test("chitang"));

	cout << "pt = " << pt.get() << endl;
	pt->print();
	cout << endl;

	auto_ptr<Test> pt1(pt);

	cout << "pt = " << pt.get() << endl;
	cout << "pt1 = " << pt1.get() << endl;

	pt1->print();

    return 0;
}

/*
 * result
 *
 * hello, chitang.
 * pt = 0x1fffc20
 * I'm chitang.
 *
 * pt = 0
 * pt1 = 0x1fffc20
 * I'm chitang.
 * Goodbye, chitang.
 *
 */

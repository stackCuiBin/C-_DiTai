/*************************************************************************
 ******* File Name: diffInherit.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 26 Jun 2019 11:46:16 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
private:
	int m_a;
protected:
	int m_b;
public:
	int m_c;

	void set(int a, int b, int c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}
};

class Child_A : public Parent
{
public:
	void print()
	{
		//cout << "m_a = " << m_a << endl;	// error, m_a is private
		cout << "m_b = " << m_b << endl;
		cout << "m_c = " << m_c << endl;
	}
};

class Child_B : protected Parent
{
public:
	void print()
	{
		//cout << "m_a = " << m_a << endl;	// error, m_a is private
		cout << "m_b = " << m_b << endl;
		cout << "m_c = " << m_c << endl;
	}
};

class Child_C : private Parent
{
public:
	void print()
	{
		//cout << "m_a = " << m_a << endl;	// error, m_a is private
		cout << "m_b = " << m_b << endl;
		cout << "m_c = " << m_c << endl;
	}
};

int main(int argc, char** argv)
{
	Child_A a;
	Child_B b;
	Child_C c;

	a.m_c = 100;
	// b.m_c = 100;	// Child_B保护继承自Parent，所以所有的public成员变成了protected成员，外界无法访问
	// c.m_c = 100;	// Child_C私有继承自Parent，所以所有的成员变成了private成员，外界无法访问

	a.set(1, 2, 3);
	// b.set(1, 2, 3);	// set() is protected
	// c.set(1, 2, 3);	// set() is private

	a.print();
	b.print();
	c.print();

    return 0;
}

/*************************************************************************
 ******* File Name: smart_pointer.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 15 Jun 2019 04:18:10 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int i;
public:
	Test(int i)
	{
		cout << "Test(int i)" << endl;
		this->i = i;
	}

	int value()
	{
		return i;
	}

	~Test()
	{
		cout << "~Test()" << endl;
	}
};

class Pointer
{
	Test* mp;
public:
	Pointer(Test* p = NULL)
	{
		mp = p;
	}

	Pointer(const Pointer& obj)
	{
		mp = obj.mp;
		const_cast<Pointer&>(obj).mp = NULL;
	}

	Pointer& operator = (const Pointer& obj)
	{
		if(this != &obj)
		{
			delete mp;
			mp = obj.mp;
			const_cast<Pointer&>(obj).mp = NULL;
		}

		return *this;
	}

	Test* operator -> ()
	{
		return mp;
	}

	Test& operator * ()
	{
		return *mp;
	}

	bool isNull()
	{
		return (mp == NULL);
	}

	~Pointer()
	{
		delete mp;
	}
};

int main(int argc, char** argv)
{
	Pointer p1 = new Test(0);

	cout << p1->value() << endl;

	Pointer p2 = p1;

	cout << p1.isNull() << endl;

	//cout << p2.operator->()->value() << endl;
	cout << p2->value() << endl;

    return 0;
}

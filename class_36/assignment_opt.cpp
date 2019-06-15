/*************************************************************************
 ******* File Name: assignment_opt.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 15 Jun 2019 01:28:48 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

#define MODIFY

class Test
{
	int* m_pointer;
public:
	Test()
	{
		m_pointer = NULL;
	}
	Test(int i)
	{
		m_pointer = new int(i);
	}
#ifdef MODIFY
	Test(const Test& obj)
	{
		m_pointer = new int(*obj.m_pointer);
	}
	Test& operator = (const Test& obj)
	{
		if(this != &obj)
		{
			delete m_pointer;
			m_pointer = new int(*obj.m_pointer);
		}

		return *this;
	}
#endif
	void print()
	{
		cout << "m_point = " << hex << m_pointer << endl;
	}
	~Test()
	{
		delete m_pointer;
	}

};

int main(int argc, char** argv)
{
	Test t1 = 1;
	Test t2;

	t2 = t1;	// not define modify: 浅拷贝，地址一样，重复释放

	t1.print();
	t2.print();

    return 0;
}

/*
 * result:
 * m_point = 0xba0c20
 * m_point = 0xba0c20
 * Aborted (core dumped)
 */

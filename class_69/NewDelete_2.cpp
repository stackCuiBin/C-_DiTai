/*************************************************************************
 ******* File Name: NewDelete_2.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 20 Jul 2019 01:36:58 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

class Test
{
	int m_value;
public:
	Test()
	{
		m_value = 0;
	}
	~Test()
	{
	}

	void* operator new (unsigned long size)
	{
		cout << "operator new : " << size << endl;

		return malloc(size);
	}

	void operator delete (void* p)
	{
		cout << "operator delete : " << p << endl;

		free(p);
	}

	void* operator new[] (unsigned long size)
	{
		cout << "operator new[] : " << size << endl;

		return malloc(size);
	}

	void operator delete[] (void* p)
	{
		cout << "operator delete[] : " << p << endl;

		free(p);
	}

};

int main(int argc, const char* argv[])
{
	Test* pt = new Test;

	delete pt;

	pt = new Test[1];

	delete[] pt;

	pt = new Test[5];

	delete[] pt;

    return 0;
}

/*
 * result:
 *
 * operator new : 4
 * operator delete : 0x1ae6030
 * operator new[] : 12
 * operator delete[] : 0x1ae6030
 * operator new[] : 28
 * operator delete[] : 0x1ae6050
 *
 * 可以看出来数组和非数组的空间大小差别
 */

/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 10 Jul 2019 11:17:39 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

template 
< typename T1, typename T2>
class Test
{
public:
	void add(T1 a, T2 b)
	{
		cout << "void add(T1 a, T2 b)" << endl;
		cout << a + b << endl;
	}
};

template
< typename T1, typename T2>
class Test<T1*, T2*>		// 关于指针的特化实现
{
public:
	void add(T1* a, T2* b)
	{
		cout << "void add(T1* a, T2* b)" << endl;
		cout << *a + *b << endl;
	}
};

template
<typename T>
class Test<T, T>	// 当Test类模板的两个参数完全相同时，使用这个实现
{
public:
	void add(T a, T b)
	{
		cout << "void add(T a, T b)" << endl;
		cout << a + b << endl;
	}

	void print()
	{
		cout << "class Test<T, T>" <<endl;
	}
};

template
< >
class Test<void*, void*>	// 当T1 == void* 并且 T2 == void*时
{
public:
	void add(void* a, void* b)
	{
		cout << "void add(void* a, void* b)" << endl;
		cout << "Error to add void* param..." << endl;
	}
};

int main(int argc, const char* argv[])
{
	Test<int, float> t1;
	Test<long, long> t2;
	Test<void*, void*> t3;

	t1.add(1, 2.5);
	cout << endl;

	t2.add(2, 2);
	t2.print();
	cout << endl;

	t3.add(NULL, NULL);
	cout << endl;

	Test<int*, double*> t4;
	int a = 1;
	double d = 0.1;
	t4.add(&a, &d);

    return 0;
}

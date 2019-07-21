/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 21 Jul 2019 04:36:53 PM CST
 ************************************************************************/

#include <iostream>
#include <new>
#include <exception>
#include <cstdlib>

using namespace std;

class Test
{
	int m_value;
public:
	Test()
	{
		cout << "Test()" <<endl;

		m_value = 0;
	}

	~Test()
	{
		cout << "~Test()" << endl;
	}

	void* operator new(long unsigned int size) throw()
	{
		cout << "void* operator new : " << size << endl;

		//return malloc(size);
		return NULL;
	}

	void operator delete(void* p)
	{
		cout << "void operator delete" << endl;

		free(p);
	}

	void* operator new[] (long unsigned int size) throw()
	{
		cout << "void* operator new[] : " << size << endl;

		//return malloc(size);
		return NULL;
	}

	void operator delete[] (void* p)
	{
		cout << "void operator delete[]" << endl;

		free(p);
	}
};

void my_new_handler()
{
	cout << "my_new_handler()" << endl;

	exit(1);
}

void ex_func_1()
{
	cout << "ex_func_1..." << endl;

	new_handler func = set_new_handler(my_new_handler);

	try
	{
		cout << "func = " << func << endl;
		if(func)
			func();
	}
	catch(const bad_alloc&)
	{
		cout << "catch(const bad_alloc&)" << endl;
	}
}


/* 发生段错误
 * g++ 编译器：
 * new返回空指针，但还是调用构造函数，并在构造函数中有赋值操作，导致段错误
 *
 * vs编译器
 * new返回空指针后，不执行构造函数
 */
void ex_func_2()
{
	cout << "ex_func_2" << endl;

	Test* pt = new Test();

	cout << "pt = " << pt << endl;

	delete pt;

	pt = new Test[5];

	cout << "pt = " << pt << endl;

	delete[] pt;
}

void ex_func_3()
{
	cout << "ex_func_3" << endl;

	/* new(nothrow)申请堆内存失败不抛出异常，只返回NULL指针 */
	int* p = new(nothrow) int[10];
	cout << "p = " << p << endl;
	// ...
	delete[] p;

	int bb[2] = {0};

	struct ST
	{
		int x;
		int y;
	};

	ST* pt = new(bb) ST();

	pt->x = 1;
	pt->y = 2;

	cout << bb[0] << endl;
	cout << bb[1] << endl;

	pt->~ST();

}

int main(int argc, const char* argv[])
{
	ex_func_1();

	ex_func_2();

	ex_func_3();

    return 0;
}

/*
 * result:
 * ex_func_1...
 * func = 0
 * ex_func_2
 * void* operator new : 4
 * pt = 0
 * void* operator new[] : 28
 * pt = 0
 * ex_func_3
 * p = 0x151a030
 * 1
 * 2
 *
 */

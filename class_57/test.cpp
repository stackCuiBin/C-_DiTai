/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 08 Jul 2019 10:36:00 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	//Test(const Test&);	// 因为是私有，在Swap二次编译时，T t = a;拷贝构造将会报错
public:
	Test()
	{}
};

template <typename T>
void Swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

typedef void(FuncI)(int&, int&);
typedef void(FuncD)(double&, double&);
typedef void(FuncT)(Test&, Test&);

int main(int argc, const char* argv[])
{
	FuncI *pi = Swap;	// 编译器自动推导 T为int
	FuncD *pd = Swap;	// 编译器自动推导 T为double
	FuncT *pt = Swap;	// 编译器自动推导 T为Test

	cout << "pi = " << reinterpret_cast<void*>(pi) << endl;
	cout << "pd = " << reinterpret_cast<void*>(pd) << endl;
	cout << "pt = " << reinterpret_cast<void*>(pt) << endl;

    return 0;
}

/*
 * result
 * pi = 0x400a11
 * pd = 0x400a3e
 * pt = 0x400a77
 */

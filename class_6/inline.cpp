/*************************************************************************
 ******* File Name: inline.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Mon 20 May 2019 09:59:57 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

//#define inline_simple
#define inline_complex

#ifdef inline_simple

#define FUNC(a, b)  ((a) < (b) ? (a) : (b))

inline int func(int a, int b)
{
	return a < b ? a : b;
}

int main(int argc, char** argv)
{
	int a = 1;
	int b = 3;
	//int c = FUNC(++a, b);
	int c = func(++a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	return 0;
}

/*
 * result:
 * 1) FUNC
 * a = 3
 * b = 3
 * c = 3
 *
 * 2) func
 * a = 2
 * b = 3
 * c = 2
 */

#endif

#ifdef inline_complex 

__attribute__((always_inline))
//inline
int add_inline(int n);

int main(int argc, char** argv)
{
	int r = add_inline(10);

	cout << "r = " << r << endl;

	return 0;
}

inline int add_inline(int n)
{
	int ret = 0;

	for(int i=0; i<n; i++)
	{
		ret += i;
	}

	return ret;
}

/*
 * result:
 * 1) using inline, assembly code is as follows:
 * 0000000000400896 <main>:
 *  push   %rbp
 *  mov    %rsp,%rbp
 *  sub    $0x20,%rsp
 *  mov    %edi,-0x14(%rbp)
 *  mov    %rsi,-0x20(%rbp)
 *  mov    $0xa,%edi
 *  callq  400938 <_Z10add_inlinei>
 * Although inline is used, add_inline is still called
 *
 * 2) using attribute__((always_inline)), assembly code is as follows:
 *  push   %rbp
 *  mov    %rsp,%rbp
 *  sub    $0x20,%rsp
 *  mov    %edi,-0x14(%rbp)
 *  mov    %rsi,-0x20(%rbp)
 *  movl   $0xa,-0xc(%rbp)
 *  movl   $0x0,-0x8(%rbp)
 *  movl   $0x0,-0x4(%rbp)
 *  mov    -0xc(%rbp),%eax
 * add_inline not called
 */

#endif 

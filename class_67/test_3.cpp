/*************************************************************************
 ******* File Name: test_3.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Tue 16 Jul 2019 11:29:17 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;

		//throw 0;
	}

	virtual ~Test()
	{
		cout << "~Test()" << endl;
	}
};

int main(int argc, const char* argv[])
{
	Test* p = reinterpret_cast<Test*>(1);

	try
	{
		/* 抛出异常时，没有发生内存泄漏，说明对象创建不成功，没有内存浪费 */
		p = new Test();
	}
	catch(...)
	{
		cout << "Expection" << endl;
	}

	cout << "p = " << p << endl;

    return 0;
}

/*
 * result:
 * 使用valgrind检测有没有内存泄漏
 * valgrind --tool=memcheck --leak-check=full ./a.out 
 *
 * 构造函数中抛出异常时，从输出看没有内存泄露
 * ==11043== Memcheck, a memory error detector
 * ==11043== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
 * ==11043== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
 * ==11043== Command: ./a.out
 * ==11043== 
 * Test()
 * Expection
 * p = 0x1
 * ==11043== 
 * ==11043== HEAP SUMMARY:
 * ==11043==     in use at exit: 72,704 bytes in 1 blocks
 * ==11043==   total heap usage: 4 allocs, 3 frees, 73,868 bytes allocated
 * ==11043== 
 * ==11043== LEAK SUMMARY:
 * ==11043==    definitely lost: 0 bytes in 0 blocks
 * ==11043==    indirectly lost: 0 bytes in 0 blocks
 * ==11043==      possibly lost: 0 bytes in 0 blocks
 * ==11043==    still reachable: 72,704 bytes in 1 blocks
 * ==11043==         suppressed: 0 bytes in 0 blocks
 * ==11043== Reachable blocks (those to which a pointer was found) are not shown.
 * ==11043== To see them, rerun with: --leak-check=full --show-leak-kinds=all
 * ==11043== 
 * ==11043== For counts of detected and suppressed errors, rerun with: -v
 * ==11043== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 *
 * 构造函数中不抛出异常时，从输出看肯定有内存泄漏
 * ==11060== Memcheck, a memory error detector
 * ==11060== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
 * ==11060== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
 * ==11060== Command: ./a.out
 * ==11060== 
 * Test()
 * p = 0x5ab6c80
 * ==11060== 
 * ==11060== HEAP SUMMARY:
 * ==11060==     in use at exit: 72,712 bytes in 2 blocks
 * ==11060==   total heap usage: 3 allocs, 1 frees, 73,736 bytes allocated
 * ==11060== 
 * ==11060== 8 bytes in 1 blocks are definitely lost in loss record 1 of 2
 * ==11060==    at 0x4C2E0EF: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
 * ==11060==    by 0x400B49: main (in /home/cuibin/work/DiTai/CppLearn/CPP_DiTai/class_67/a.out)
 * ==11060== 
 * ==11060== LEAK SUMMARY:
 * ==11060==    definitely lost: 8 bytes in 1 blocks
 * ==11060==    indirectly lost: 0 bytes in 0 blocks
 * ==11060==      possibly lost: 0 bytes in 0 blocks
 * ==11060==    still reachable: 72,704 bytes in 1 blocks
 * ==11060==         suppressed: 0 bytes in 0 blocks
 * ==11060== Reachable blocks (those to which a pointer was found) are not shown.
 * ==11060== To see them, rerun with: --leak-check=full --show-leak-kinds=all
 * ==11060== 
 * ==11060== For counts of detected and suppressed errors, rerun with: -v
 * ==11060== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
 */

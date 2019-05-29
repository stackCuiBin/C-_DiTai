/*************************************************************************
 ******* File Name: ObjConstructionOrder.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Wed 29 May 2019 09:58:08 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
private:
	int mi;
public:
	Test(int v)
	{
		mi = v;
		cout << "Test(int v) mi = " << mi << endl;
	}
	Test(const Test& obj)
	{
		mi = obj.mi;
		cout << "Test(const Test& obj) mi = " << mi << endl;
	}
	int getMI()
	{
		return mi;
	}
	~Test()
	{
		cout << "del Test" << endl;
	}
};

int main(int argc, char** argv)
{

	int i = 0;
	Test a1 = i;

	while(i < 3)
		Test a2 = ++i;	// 为什么可以重复构造？？？因为从添加的析构函数打印可以看出来，
						// 每执行完这一句，a2就被销毁了，然后再重新定义
	
	//cout << "a2.mi = " << a2.getMI() << endl;	// error: 显示a2未定义，因为a2在上一句已经被销毁了
												// 猜测上面的while语句有一个局部作用域，导致在域外不能使用a2

	if(i < 4){
		Test a = a1;
	}else{
		Test a(100);
	}
	
    return 0;
}

/*
 * result:
 * Test(int v) mi = 0
 * Test(int v) mi = 1
 * del Test
 * Test(int v) mi = 2
 * del Test
 * Test(int v) mi = 3
 * del Test
 * Test(const Test& obj) mi = 0
 * del Test
 * del Test
 */

/*************************************************************************
 ******* File Name: operator_overload_3.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sat 08 Jun 2019 05:53:46 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Complex
{
private:
	int a;
	int b;
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}

	int getA()
	{
		return a;
	}

	int getB()
	{
		return b;
	}

	Complex operator + (const Complex& p)
	{
		Complex ret;
		
		cout << "Complex operator + (const Complex&p)" << endl;
		
		ret.a = this->a + p.a;
		ret.b = this->b + p.b;

		return ret;
				
	}

	friend Complex operator + (const Complex& p1, const Complex& p2);
};

Complex operator + (const Complex& p1, const Complex& p2)
{
	Complex ret;

	cout << "Complex operator + (const Complex& p1, const Complex& p2)" << endl;

	ret.a = p1.a + p2.a;
	ret.b = p1.b + p2.b;

	return ret;
}

int main(int argc, char** argv)
{
	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c3 = c1 + c2; // operator + (c1, c2);

	cout << "c3.a = " << c3.getA() << endl;
	cout << "c3.b = " << c3.getB() << endl;

    return 0;
}

/*
 * result:
 * Complex operator + (const Complex&p)
 * c3.a = 4
 * c3.b = 6
 */

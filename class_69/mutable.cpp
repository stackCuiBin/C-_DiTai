/*************************************************************************
 ******* File Name: test.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 19 Jul 2019 10:41:13 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int m_value;
	mutable int m_count;
public:
	Test(int value = 0)
	{
		m_value = value;
		m_count = 0;
	}

	int getValue() const
	{
		m_count++;

		return m_value;
	}

	void setValue(int value)
	{
		m_count++;

		m_value = value;
	}

	int getCount() const
	{
		return m_count;
	}
};

int main(int argc, const char* argv[])
{
	Test t;

	t.setValue(100);

	cout << "t.m_value = " << t.getValue() << endl;
	cout << "t.m_count = " << t.getCount() << endl;

	const Test tc(200);

	cout << "tc.m_value = " << tc.getValue() << endl;
	cout << "tc.m_count = " << tc.getCount() << endl;



    return 0;
}

/*************************************************************************
 ******* File Name: NoMutable.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 19 Jul 2019 11:07:04 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	int m_value;
	int * const p_count;
public:
	Test(int value = 0) : p_count(new int(0))
	{
		m_value = value;
	}

	int getValue() const
	{
		*p_count += 1;;

		return m_value;
	}

	void setValue(int value)
	{
		*p_count += 1;;

		m_value = value;
	}

	int getCount() const
	{
		return *p_count;
	}
};

int main(int argc, const char* argv[])
{
	Test t;

	t.setValue(100);

	cout << "t.m_value = " << t.getValue() << endl;
	cout << "t.(*p_count) = " << t.getCount() << endl;

	const Test tc(200);

	cout << "tc.m_value = " << tc.getValue() << endl;
	cout << "tc.(*p_count) = " << tc.getCount() << endl;

    return 0;
}

/*
 * result:
 *
 * t.m_value = 100
 * t.(*p_count) = 2
 * tc.m_value = 200
 * tc.(*p_count) = 1
 *
 */

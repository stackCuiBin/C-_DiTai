/*************************************************************************
 ******* File Name: NewDelete.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 19 Jul 2019 11:40:45 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Test
{
	static const unsigned int COUNT = 4;
	static char c_buffer[];
	static char map[];

	int m_value;

public:
	void* operator new(long unsigned int size)
	{
		void* ret = NULL;

		for(int i = 0; i < COUNT; i++)
		{
			if(map[i] == 0)
			{
				map[i] = 1;

				ret = c_buffer + i * sizeof(Test);

				cout << "succeed to allocate mem: " << ret << endl;
				break;
			}
		}

		return ret;
	}

	void operator delete(void* p)
	{
		if(p != NULL)
		{
			char* mem = reinterpret_cast<char*>(p);
			int index = (mem - c_buffer) / sizeof(Test);
			int flag = (mem - c_buffer) % sizeof(Test);

			// cout << "mem = " << mem << endl;			// output NULL, because cout treat mem as a string
			// cout << "mem = " << (void*)mem << endl;	// output thr real addr
			//
			if((flag == 0) && (0 <= index) && (index < COUNT))
			{
				map[index] = 0;

				cout << "succeed to delete: " << p << endl;
			}
		}
	}
};

char Test::c_buffer[sizeof(Test) * Test::COUNT] = {0};
char Test::map[COUNT] = {0};

int main(int argc, const char* argv[])
{
	cout << "===== Test Signal Object =====" << endl;
	Test* pt = new Test;

	delete pt;

	cout << endl << "===== Test Object Array =====" << endl;

	Test* pa[5] = {0};

	for(int i = 0; i < 5; i++)
	{
		pa[i] = new Test;

		cout << "pa[" << i << "] = " << pa[i] << endl;
	}
	for(int i = 0; i < 5; i++)
	{
		cout << "delete " << pa[i] << endl;

		delete pa[i];
	}

    return 0;
}

/*
 * result:
 *
 * ===== Test Signal Object =====
 * succeed to allocate mem: 0x6021a0
 * succeed to delete: 0x6021a0
 *
 * ===== Test Object Array =====
 * succeed to allocate mem: 0x6021a0
 * pa[0] = 0x6021a0
 * succeed to allocate mem: 0x6021a4
 * pa[1] = 0x6021a4
 * succeed to allocate mem: 0x6021a8
 * pa[2] = 0x6021a8
 * succeed to allocate mem: 0x6021ac
 * pa[3] = 0x6021ac
 * pa[4] = 0
 * delete 0x6021a0
 * succeed to delete: 0x6021a0
 * delete 0x6021a4
 * succeed to delete: 0x6021a4
 * delete 0x6021a8
 * succeed to delete: 0x6021a8
 * delete 0x6021ac
 * succeed to delete: 0x6021ac
 * delete 0
 *
 */

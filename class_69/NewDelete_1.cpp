/*************************************************************************
 ******* File Name: NewDelete.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 19 Jul 2019 11:40:45 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

class Test
{
	static unsigned int c_count;
	static char* c_buffer;
	static char* c_map;

	int m_value;

public:
	static bool setSourceMemory(char* memory, unsigned int size)
	{
		bool ret = false;
		
		c_count = size / sizeof(Test);

		ret = (c_count && (c_map = reinterpret_cast<char*>(calloc(c_count, sizeof(char)))));

		if(ret)
		{
			c_buffer = memory;
		}
		else
		{
			free(c_map);

			c_buffer = NULL;
			c_map = NULL;
			c_count = 0;
		}

		return ret;
	}

	void* operator new(long unsigned int size)
	{

		void* ret = NULL;

		if(c_count > 0)
		{
			for(int i = 0; i < c_count; i++)
			{
				if(c_map[i] == 0)
				{
					c_map[i] = 1;

					ret = c_buffer + i * sizeof(Test);

					cout << "succeed to allocate mem: " << ret << endl;
					break;
				}
			}
		}
		else
		{
			ret = malloc(size);
		}

		return ret;
	}

	void operator delete(void* p)
	{
		if(p != NULL)
		{
			if(c_count > 0)
			{
				char* mem = reinterpret_cast<char*>(p);
				int index = (mem - c_buffer) / sizeof(Test);
				int flag = (mem - c_buffer) % sizeof(Test);

				if((flag == 0) && (0 <= index) && (index < c_count))
				{
					c_map[index] = 0;

					cout << "succeed to delete: " << p << endl;
				}
			}
			else
			{
				free(p);
			}
		}
	}
};

unsigned int Test::c_count = 0;
char* Test::c_buffer = NULL;
char* Test::c_map = NULL;

int main(int argc, const char* argv[])
{
	char buffer[4 * sizeof(Test)] = {0};
	Test::setSourceMemory(buffer, sizeof(buffer));

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

	// free c_map
	
    return 0;
}

/*
 * result:
 * 
 * 1,没有使用buffer[]分配空间时
 * ===== Test Signal Object =====
 *
 * ===== Test Object Array =====
 * pa[0] = 0x24e6030
 * pa[1] = 0x24e6050
 * pa[2] = 0x24e6070
 * pa[3] = 0x24e6090
 * pa[4] = 0x24e60b0
 * delete 0x24e6030
 * delete 0x24e6050
 * delete 0x24e6070
 * delete 0x24e6090
 * delete 0x24e60b0
 *
 * 2，使用buffer[]分配空间时
 * ===== Test Signal Object =====
 * succeed to allocate mem: 0x7fff3343a800
 * succeed to delete: 0x7fff3343a800
 *
 * ===== Test Object Array =====
 * succeed to allocate mem: 0x7fff3343a800
 * pa[0] = 0x7fff3343a800
 * succeed to allocate mem: 0x7fff3343a804
 * pa[1] = 0x7fff3343a804
 * succeed to allocate mem: 0x7fff3343a808
 * pa[2] = 0x7fff3343a808
 * succeed to allocate mem: 0x7fff3343a80c
 * pa[3] = 0x7fff3343a80c
 * pa[4] = 0
 * delete 0x7fff3343a800
 * succeed to delete: 0x7fff3343a800
 * delete 0x7fff3343a804
 * succeed to delete: 0x7fff3343a804
 * delete 0x7fff3343a808
 * succeed to delete: 0x7fff3343a808
 * delete 0x7fff3343a80c
 * succeed to delete: 0x7fff3343a80c
 * delete 0
 *
 */

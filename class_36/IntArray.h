/*************************************************************************
 ******* File Name: IntArray.h
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 07 Jun 2019 06:50:02 PM CST
 ************************************************************************/

#ifndef _INTARRAY_H_
#define _INTARRAY_H_

class IntArray
{
private:
	int m_length;
	int* m_pointer;

	IntArray(int len);
	bool construct();

public:
	static IntArray* NewInstance(int len);
	int length();
	bool get(int index, int& value);
	bool set(int index, int value);
	
	int& operator [] (int index);
	IntArray& operator = (const IntArray& obj);
	IntArray& self();
	~IntArray();
};

#endif

/*************************************************************************
 ******* File Name: TwoPhaseCons.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Fri 07 Jun 2019 12:08:05 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class TwoPhaseCons
{
private:
	TwoPhaseCons()
	{
	}
	bool construct()
	{
		return true;
	}
public:
	static TwoPhaseCons* NewInstance()
	{
		TwoPhaseCons* ret = new TwoPhaseCons();

		if( !(ret && ret->construct()) )
		{
			delete ret;
			ret = NULL;
		}

		return ret;
	}
};

int main(int argc, char** argv)
{
	TwoPhaseCons* obj = TwoPhaseCons::NewInstance();

	cout << "obj = " << obj << endl;

    return 0;
}

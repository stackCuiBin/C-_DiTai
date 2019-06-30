/*************************************************************************
 ******* File Name: demo.cpp
 ******* Author: bb.cui
 ******* Mail: bb.cui@foxmail.com 
 ******* Created Time: Sun 30 Jun 2019 11:57:38 PM CST
 ************************************************************************/

#include <iostream>

using namespace std;

class Boss
{
public:
	int fight()
	{
		int ret = 10;

		cout << "Boss::fight() : " << ret << endl;

		return ret;
	}
};

class Master
{
public:
	virtual int EightSwordKill()
	{
		int ret = 8;

		cout << "Master::EightSwordKill() : " << ret << endl;

		return ret;
	}
};

class NewMaster : public Master
{
public:
	int EightSwordKill()
	{
		int ret = Master::EightSwordKill() * 2;

		cout << "NewMaster::EightSwordKill() : " << ret << endl;

		return ret;
	}
};

void field_pk(Master* master, Boss* boss)
{
	int k = master->EightSwordKill();
	int b = boss->fight();

	if(k < b)
	{
		cout << "Master is killed ..." << endl;
	}
	else
	{
		cout << "Boss is killed ..." << endl;
	}
}

int main(int argc, const char* argv[])
{
	Master master;
	Boss boss;

	cout << "master vs boss" << endl;

	field_pk(&master, &boss);

	cout << endl;

	NewMaster newmaster;

	cout << "newmaster vs boss" << endl;

	field_pk(&newmaster, &boss);

    return 0;
}

/*
 * result:
 * master vs boss
 * Master::EightSwordKill() : 8
 * Boss::fight() : 10
 * Master is killed ...
 *
 * newmaster vs boss
 * Master::EightSwordKill() : 8
 * NewMaster::EightSwordKill() : 16
 * Boss::fight() : 10
 * Boss is killed ...
 */

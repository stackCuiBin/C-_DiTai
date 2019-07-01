#ifndef _DEMO_H_
#define _DEMO_H_

typedef void Demo;
typedef void Derived;

Demo* Demo_Create(int i, int j);
int getmI(Demo* pThis);
int getmJ(Demo* pThis);
int Demo_Add(Demo* pThis, int value);
void Demo_Free(Demo* pThis);

Derived* Derived_Create(int i, int j, int k);
int getmK(Derived* pThis);
int Derived_Add(Derived* pThis, int value);

#endif

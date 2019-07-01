#ifndef _DEMO_H_
#define _DEMO_H_

typedef void Demo;

Demo* Demo_Create(int i, int j);
int getmI(Demo* pThis);
int getmJ(Demo* pThis);
int add(Demo* pThis, int value);
void Demo_Free(Demo* pThis);

#endif

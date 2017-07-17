#include <iostream>
#include <Windows.h>
#include "MemPool.h"

using namespace std;

char* a[800000];

int main()
{
	MemPool m(100*1024*1024,128);

	m.MemPool_info_dump();

	//m.FreeLinkList_dump();

	DWORD count = GetTickCount();

	for (int i = 0; i < 800000; i++)
	{
		a[i] = (char*)m.AllocMem(64);
		m.ReleaseMem(a[i]);
	}

	cout << "Interval = " << GetTickCount() - count << " ms" << endl;

	DWORD count2 = GetTickCount();
	for (int i = 0; i < 800000; i++)
	{
		a[i] = (char*)malloc(64);
		free(a[i]);
	}
	cout << "Interval2 = " << GetTickCount() - count << " ms" << endl;
	return 0;
}
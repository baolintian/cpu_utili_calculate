// CpuUsageCpp.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <windows.h>
#include <cmath>
#include "CpuUsage.h"

DWORD WINAPI WatchItThreadProc(LPVOID lpParam);

CpuUsage usage;

int main(int argc, char* argv[])
{
	//SetThreadAffinityMask(GetCurrentThread(), 1);
	CreateThread(NULL, 0, WatchItThreadProc, NULL, 0, NULL);
	/*
	test code here.
	*/
	int x = 0;
	while (true) {
		x++;
	}
	printf("%d\n", x);
	return 0;
}


DWORD WINAPI WatchItThreadProc(LPVOID lpParam)
{
	//totTime determines the test time.
	int totTime = 0;
	while (true)
	{
		double cpuUsage = usage.GetUsage();
		if (fabs(cpuUsage + 1) > 0.0001) {
			
			printf("Thread id %d: %lf%% cpu usage\n", ::GetCurrentThreadId(), cpuUsage);
		}
		Sleep(500);
		totTime++;
		if (totTime == 1000) {
			return 0;
		}
	}
}

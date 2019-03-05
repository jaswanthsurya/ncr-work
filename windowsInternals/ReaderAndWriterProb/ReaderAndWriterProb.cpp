#include<Windows.h>
#include<iostream>
#include<tchar.h>
#include<queue>
using namespace std;
queue <int> Tqueue;
int glob;
SRWLOCK  Rlock, Wlock;
CONDITION_VARIABLE QueueEmpty, QueueFull;
//reader threads call back functions.......................................................
DWORD WINAPI read(LPVOID Str)
{
	AcquireSRWLockExclusive(&Rlock);
	if (Tqueue.empty())
	{
		SleepConditionVariableSRW(&QueueEmpty, &Rlock, INFINITE,0);
		WakeConditionVariable(&QueueFull);
	}
	else
	{
		cout << "Reader consumed : " << Tqueue.front() << endl;
		Tqueue.pop();
		WakeConditionVariable(&QueueFull);
	}
	ReleaseSRWLockExclusive(&Rlock);
	return 0;
}
//writer calback functions........................................................
DWORD WINAPI write(LPVOID Str)
{
	AcquireSRWLockExclusive(&Wlock);
	if (Tqueue.size()==5)
	{
		SleepConditionVariableSRW(&QueueFull, &Wlock, INFINITE, 0);
		WakeAllConditionVariable(&QueueEmpty);
	}
	else
	{
		Tqueue.push(++glob);
		cout << "writer produced :" << glob << endl;
		WakeAllConditionVariable(&QueueEmpty);
	}
	ReleaseSRWLockExclusive(&Wlock);
	return 0;
}
int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE Thread[6];
	LPWSTR Str=NULL;
	InitializeSRWLock(&Rlock);
	InitializeSRWLock(&Wlock);
	InitializeConditionVariable(&QueueEmpty);
	InitializeConditionVariable(&QueueFull);
	while (1)
	{
		glob = 0;
		for (int i = 0; i < 2; i++)
		{
			Thread[i]  = CreateThread(NULL,//security attributes thread is not inherited if null
				0,//stack size for thread if 0 it uses size of executable
				read,//call back function
				Str,//parameter to function
				0,//creation flag
				NULL);//thread id
			//reader threads......................................................................

			if (Thread[i] == NULL)
			{
				cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
			}
		}

		//writer threads.................................................................................

		for (int i = 2; i < 6; i++)
		{
			Thread[i]= CreateThread(NULL,//security attributes thread is not inherited if null
				0,//stack size for thread if 0 it uses size of executable
				write,//call back function
				Str,//parameter to function
				0,//creation flag
				NULL);//thread id
			if (Thread[i] == NULL)
			{
				cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
			}
		}
		WaitForMultipleObjects(6, Thread, TRUE, INFINITE);
	}
	return 0;
}
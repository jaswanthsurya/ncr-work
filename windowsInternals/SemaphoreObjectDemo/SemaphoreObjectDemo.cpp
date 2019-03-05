#include<iostream>
#include<Windows.h>
#include<tchar.h>

using namespace std;
HANDLE Semaphore;
#define MAX_THREADS 2  //maximum threads handled at a time by simaphore
#define TotalThreads 3//total number of threads

DWORD WINAPI ThreadFun(LPVOID STR)
{
	BOOL StatusSemaphore=TRUE;
	DWORD Status,ThreadId;
	Status=WaitForSingleObject(Semaphore, 0);//semaphore handle returns status depending on the number of threads it can handle
	/*accordingly swicth the value of the status and do the necessary action required*/
	switch (Status)
	{
	case WAIT_OBJECT_0:
		ThreadId = GetCurrentThreadId();
		cout << "thread " << ThreadId << " wait succeded" << endl;
		//release the semaphore when work is done
		StatusSemaphore = ReleaseSemaphore(Semaphore,//semaphore handle
			1,//increment count value
			NULL);//store present count
		if (!StatusSemaphore)
		{
			cout << "releasing semaphore failed due to error (" << GetLastError() << ")" << endl;
		}
		break;
	case WAIT_TIMEOUT:cout << "thread timeout failed" << endl;//wait timeout indicates that semaphore did not handle the thread as maximum capacity is exceeded
		break;
	}
	return 0;
}

int _tmain(int argc, WCHAR *argv[], WCHAR *env[])
{
	HANDLE ThreadHandle[TotalThreads];
	DWORD ThreadId;
	Semaphore = CreateSemaphore(NULL,//security attributes
		MAX_THREADS,//initial count
		MAX_THREADS,//maximum count
		NULL);//lp name
	if (Semaphore == NULL)
	{
		cout << "creation of semaphore failed due to error (" << GetLastError() << ")" << endl;
	}
	for (int i = 0; i < TotalThreads; i++)
	{
		ThreadHandle[i] = CreateThread(NULL,//security attributes
			0,//stack size
			ThreadFun,//callback function
			NULL,//input parameter
			0,//flags
			&ThreadId);//thread id
		if (ThreadHandle[i] == NULL)
		{
			cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
		}
	}
	WaitForMultipleObjects(TotalThreads, ThreadHandle, TRUE, INFINITE);//wait until all the threads complete execution
	for (int i = 0; i < TotalThreads; i++)
	{
		CloseHandle(ThreadHandle[i]);//close the associated handle
	}
	return 0;
}
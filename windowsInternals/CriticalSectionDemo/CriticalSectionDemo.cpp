#include<Windows.h>
#include<iostream>
#include<tchar.h>

using namespace std;
int GlobalVar;
CRITICAL_SECTION cs;

DWORD WINAPI ThreadFun1(LPVOID STR)
{
	/*whenever any section that is simultaneously accessed by multiple threads it need to be placed in critical 
	section for resource locking and avoid inconsitency when one thread is using the critical section other thread cannot
	access it*/
	EnterCriticalSection(&cs);
	GlobalVar++;
	LeaveCriticalSection(&cs);
	return 0;
}

int _tmain(int argc, WCHAR *argv[], WCHAR *env[])
{
	HANDLE CreateThreadHandle[2];
	InitializeCriticalSection(&cs);/*initialising the crictical section this method makes the second thread to go to sleep 
								   if the critical section is under use and cannot be accessed*/
	//InitializeCriticalSectionAndSpinCount(&cs, 2000);
	/*where as using this type of initialisation makes the thread 
	to sleep only after spinning it for certain time the second argument tells the time for which it is made to sleep before 
	entering the sleep state when critical section is under use*/
	DWORD thid1, thid2;
	int i = 0;
	while (i < 100)
	{
		CreateThreadHandle[0] = CreateThread(NULL,//security attributes
			0,//stack size if 0 it uses size of executable file
			ThreadFun1,//call back function
			NULL,//function parameter
			0,//creation flags
			&thid1);//thread id
		if (CreateThreadHandle[0] == NULL)
		{
			cout << "thread creation failed due to error(" << GetLastError() << ")" << endl;
		}
		CreateThreadHandle[1] = CreateThread(NULL,//security attributes
			0,//stack size if 0 it uses size of executable file
			ThreadFun1,//call back function
			NULL,//function parameter
			0,//creation flags
			&thid2);//thread id
		if (CreateThreadHandle[1] == NULL)
		{
			cout << "thread creation failed due to error(" << GetLastError() << ")" << endl;
		}
		WaitForMultipleObjects(2, CreateThreadHandle, TRUE, INFINITE);//wait until both the threads are signalled
		cout << "the value of global variable accessed by two threads simultaneously is: " << GlobalVar << endl;
		if (GlobalVar != 2)
		{
			cout << "threads are inconsistent : " << endl;
			return 0;
		}
		GlobalVar = 0;
		i++;
	}
	CloseHandle(CreateThreadHandle[0]);
	CloseHandle(CreateThreadHandle[1]);
	cout << "threads are consistent as critical sections are used" << endl;
	return 0;
}
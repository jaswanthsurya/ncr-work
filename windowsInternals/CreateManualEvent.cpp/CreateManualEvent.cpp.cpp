#include<windows.h>
#include<iostream>
#include<tchar.h>

using namespace std;
HANDLE CreateEventHandle;
DWORD WINAPI countwords(LPVOID STR)
{
	WaitForSingleObject(CreateEventHandle, INFINITE);//wait until the event is triggered and then the threads start execution
	cout << "counting words" << endl;
	return 0;
}

DWORD WINAPI checkspelling(LPVOID STR)
{
	WaitForSingleObject(CreateEventHandle, INFINITE);
	cout << "checkspelling" << endl;
	return 0;
}

DWORD WINAPI checkgrammar(LPVOID STR)
{
	WaitForSingleObject(CreateEventHandle, INFINITE);
	cout << "check grammar" << endl;
	return 0;
}

int _tmain(int argc, WCHAR*argv[], WCHAR*env[])
{
	HANDLE ThreadHandle[3];//handle array to hold handles of threads created
	DWORD status;
	CreateEventHandle = CreateEvent(NULL,//security attributes
		TRUE,//manual reset
		FALSE,//initial state is non signaled if false
		TEXT("writer event"));//event name
	if (CreateEventHandle == NULL)//if creation of thread fails we need to get the error code
	{
		cout << "creation of event failed due to error (" << GetLastError() << ")" << endl;
	}
	ThreadHandle[0] = CreateThread(NULL,//security attributes
	0,//stack size if 0 thread takes size of executable
	countwords,//call back function
	NULL,//arguments to function
	0,//creation flags
	NULL);//thread id

	if (ThreadHandle[0] == NULL)
	{
		cout << "creation of thread 0 failed due to error (" << GetLastError() << ")" << endl;
	}

	ThreadHandle[1] = CreateThread(NULL,//security attributes
	0,//stack size if 0 thread takes size of executable
	checkspelling,//call back function
	NULL,//arguments to function
	0,//creation flags
	NULL);//thread id
	
	if (ThreadHandle[1] == NULL)
	{
		cout << "creation of thread 1 failed due to error (" << GetLastError() << ")" << endl;
	}

	ThreadHandle[1] = CreateThread(NULL,//security attributes
		0,//stack size if 0 thread takes size of executable
		checkgrammar,//call back function
		NULL,//arguments to function
		0,//creation flags
		NULL);//thread id

	if (ThreadHandle[2] == NULL)
	{
		cout << "creation of thread 2 failed due to error (" << GetLastError() << ")" << endl;
	}

	cout << "event not triggered" << endl;
	Sleep(4000);
	cout << "event trigerred" << endl;
	if (!SetEvent(CreateEventHandle))//set the event and make the threads to start execution
	{
		cout << "event triggering failed due to error (" << GetLastError() << ")" << endl;
	}
	WaitForMultipleObjects(3, ThreadHandle, TRUE, INFINITE);//wait until all the threads are signalled
}
#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
int g_x;
DWORD ExitCode;
HANDLE CreateThreadHandle;
DWORD WINAPI ThreadFun(LPVOID Str)
{
	g_x++;
	TerminateThread(CreateThreadHandle, ExitCode);
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	g_x = 0;
	cout << "the value of g_x in the main function is: " << g_x << endl;
	CreateThreadHandle = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun,//call back function
		NULL,//parameter to function
		CREATE_SUSPENDED,//creation flag
		NULL);//thread id
	if (CreateThreadHandle == NULL)//if creation of thread fails
	{
		cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
	}
	if (!GetExitCodeThread(CreateThreadHandle, &ExitCode))//function that gives the exit code of the thread in the second parameter
	{
		cout << "exit thread failed due to error (" << GetLastError() << ")" << endl;
	}
	WaitForSingleObject(CreateThreadHandle, 5000);//waits for 5 seconds if the thread is not signalled yet
	cout << "the exit code is : " << ExitCode << endl;
	cout << "the value of g_x after executing thread is :" << g_x << endl;
	CloseHandle(CreateThreadHandle);//closing the associated handle for the thread
	return 0;
}
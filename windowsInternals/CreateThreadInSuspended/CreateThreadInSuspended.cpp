#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

DWORD WINAPI ThreadFun(LPVOID Str)
{
	for (int i = 0; i < 1000; i++)
	{
		cout << i + 1 << endl;
	}
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle;
	CreateThreadHandle = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun,//call back function
		NULL,//parameter to function
		CREATE_SUSPENDED,//creation flag
		NULL);//thread id
	if (CreateThreadHandle == NULL)
	{
		cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
	}
	Sleep(5000);
	ResumeThread(CreateThreadHandle);
	WaitForSingleObject(CreateThreadHandle, INFINITE);
	CloseHandle(CreateThreadHandle);//close the handle after use
	return 0;
}
#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

DWORD WINAPI ThreadFun(LPVOID Str)//thread function
{
	cout << "hi" << endl;
	Sleep(1000);
	return 0;
}

DWORD WINAPI ThreadFun1(LPVOID Str)//thread function
{
	cout << "hi" << endl;
	Sleep(1000);
	return 0;
}
int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle[2];//handle for thread
	DWORD ReturnVal;//return value for wait for single object function
	CreateThreadHandle[0] = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun,//call back function
		NULL,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle[0] == NULL)
	{
		cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
	}
	CreateThreadHandle[1] = CreateThread(NULL,//security attributes thread is not inherited if null
		0,//stack size for thread if 0 it uses size of executable
		ThreadFun1,//call back function
		NULL,//parameter to function
		0,//creation flag
		NULL);//thread id
	if (CreateThreadHandle[1] == NULL)
	{
		cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
	}
	ReturnVal=WaitForMultipleObjects(2,CreateThreadHandle,TRUE,1000);//case WAIT_TIMEOUT
	//ReturnVal = WaitForMultipleObjects(2,CreateThreadHandle,TRUE,INFINITE);//case WAIT_OBJECT_0
	/*wait for multiple object is used to wait until all the objects gets signalled i.e. terminated if this function
	is not used there may be cases where the secondary threads did not get terminated and the primary thread got
	exited in such cases using this function avoids ambiguty this function returns different status*/
	switch (ReturnVal)
	{
	case WAIT_ABANDONED_0:cout << "wait abondened" << endl;
		break;
	case WAIT_TIMEOUT:cout << "wait timedout and object is not signalled yet" << endl;
		break;
	case WAIT_FAILED:cout << "wait failed due to error (" << GetLastError() << ")" << endl;
		break;
	case WAIT_OBJECT_0:cout << "wait succedded and object is signalled" << endl;
		break;
	default:cout << "unhandled return value" << endl;
	}
	CloseHandle(CreateThreadHandle[0]);//close the handle after use
	CloseHandle(CreateThreadHandle[1]);//close the handle after use
	return 0;
}
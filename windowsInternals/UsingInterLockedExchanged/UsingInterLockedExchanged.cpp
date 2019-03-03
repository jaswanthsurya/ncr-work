#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
long g_x = 0;
/*both the function using the same variable which is global and continuously modifying the values
there will be one situation where there is inconsistency of data if that case is found we will exit the loop
this program is to eliminate such inconsistency by using interlockedexchange so the program will not terminate and no inconsistency occcurs*/
DWORD WINAPI ThreadFun1(LPVOID Str)
{
	InterlockedExchangeAdd(&g_x, 1);
	//g_x++;
	return 0;
}

DWORD WINAPI ThreadFun2(LPVOID Str)
{
	InterlockedExchangeAdd(&g_x, 1);
	//g_x++;
	return 0;
}

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE CreateThreadHandle1, CreateThreadHandle2;
	HANDLE ArrayHandles[2];
	while (1)
	{
		g_x = 0;
		CreateThreadHandle1 = CreateThread(NULL,//security attributes thread is not inherited if null
			0,//stack size for thread if 0 it uses size of executable
			ThreadFun1,//call back function
			NULL,//parameter to function
			0,//creation flag
			NULL);//thread id
		if (CreateThreadHandle1 == NULL)
		{
			cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
		}
		CreateThreadHandle2 = CreateThread(NULL,//security attributes thread is not inherited if null
			0,//stack size for thread if 0 it uses size of executable
			ThreadFun2,//call back function
			NULL,//parameter to function
			0,//creation flag
			NULL);//thread id
		if (CreateThreadHandle2 == NULL)
		{
			cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;
		}
		ArrayHandles[0] = CreateThreadHandle1;
		ArrayHandles[1] = CreateThreadHandle2;
		WaitForMultipleObjects(2//number of objects
			, ArrayHandles//base pointer of the object
			, TRUE//if this parameter is true it means the function waits until both the objects are signalled
			, INFINITE);//time in milliseconds
		cout << "the value of g_x is: " << g_x << endl;
		if (g_x == 1)//if g_x=1 it means that there is inconsistency situation because g_x should be always two as we are having two threads
		{
			break;
		}
	}
	CloseHandle(CreateThreadHandle1);//close the handle after use
	CloseHandle(CreateThreadHandle2);//close the handle after use
	return 0;
}
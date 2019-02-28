#include<iostream>
#include<Windows.h>
#include<tchar.h>

using namespace std;

int _tmain(int argc, WCHAR* argv[], WCHAR *env[])
{
	HANDLE CreateEventHandler;
	CreateEventHandler = CreateEvent(NULL,//security attributes
		FALSE,//manual reset
		FALSE,//true is event is signaled
		TEXT("WriterEvent"));//event name
	if (CreateEventHandler == INVALID_HANDLE_VALUE)
	{
		cout << "creation of event failed with error code (" << GetLastError() << ')' << endl;
	}
	else
	{
		cout << "creation of event successful" << endl;
	}
	CloseHandle(CreateEventHandler);
	return 0;
}
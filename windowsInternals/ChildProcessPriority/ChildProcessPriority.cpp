#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	BOOL CreateProcessStatus;
	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcessInfo;
	SECURITY_ATTRIBUTES SecurityAttribute;
	SecurityAttribute.bInheritHandle = TRUE;//inheritance possible
	SecurityAttribute.lpSecurityDescriptor = NULL;
	SecurityAttribute.nLength = sizeof(SecurityAttribute);
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
	CreateProcessStatus = CreateProcess(NULL,//application name if NULL application name is taken through command line argument
		argv[1],//command line argument
		&SecurityAttribute,//process not inheritable
		NULL,//thread not inheritable
		TRUE,//handle inheritance not possible
		HIGH_PRIORITY_CLASS,//flags
		NULL,//use parents environment variables
		NULL,//use parents directory
		&StartupInfo,//startup information
		&ProcessInfo);//process information
	if (CreateProcessStatus == 0)
	{
		cout << "process creation failed due to error (" << GetLastError() << ")" << endl;
	}
	cout << ProcessInfo.hProcess << endl;
	WCHAR handle[] = { (WCHAR)ProcessInfo.hProcess};//typecast handle to string
	CreateProcessStatus = CreateProcess(argv[2],//application name if NULL application name is taken through command line argument
		handle,//command line argument
		&SecurityAttribute,//process not inheritable
		NULL,//thread not inheritable
		TRUE,//handle inheritance not possible
		HIGH_PRIORITY_CLASS,//flags
		NULL,//use parents environment variables
		NULL,//use parents directory
		&StartupInfo,//startup information
		&ProcessInfo);//process information
	if (CreateProcessStatus == 0)
	{
		cout << "process creation failed due to error (" << GetLastError() << ")" << endl;
	}
	CloseHandle(ProcessInfo.hProcess);
	CloseHandle(ProcessInfo.hThread);
}
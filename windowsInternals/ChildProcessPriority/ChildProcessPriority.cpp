#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	BOOL CreateProcessStatus;
	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcessInfo;
	LPSECURITY_ATTRIBUTES lpSecurityAttribute;
	lpSecurityAttribute->bInheritHandle = TRUE;
	lpSecurityAttribute->lpSecurityDescriptor = NULL;
	lpSecurityAttribute->nLength = sizeof(lpSecurityAttribute);
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
	CreateProcessStatus = CreateProcess(argv[2],//application name if NULL application name is taken through command line argument
		NULL,//command line argument
		lpSecurityAttribute,//process not inheritable
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
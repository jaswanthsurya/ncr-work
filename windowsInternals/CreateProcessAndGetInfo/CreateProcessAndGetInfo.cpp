#include<Windows.h>
#include<tchar.h>
#include<iostream>

using namespace std;

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	STARTUPINFO StartUpInfo, StartUpInfo1;
	PROCESS_INFORMATION ProcessInfo, ProcessInfo1;
	ZeroMemory(&StartUpInfo, sizeof(StartUpInfo));
	ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
	StartUpInfo.cb = sizeof(StartUpInfo);
	BOOL Status = 0;
	Status = CreateProcess(NULL,//null if the application name is not given using variable but using command line arguments
		argv[1],//application name given as command line argument 
		NULL,//process not inheritable if null
		NULL,//thread not inheritable if null
		FALSE,//handle inheritance not possible
		0,//flags
		NULL,//use parents environment variables
		NULL,//use parents directory
		&StartUpInfo,//startup information
		&ProcessInfo);//process information
	if (Status == 0)//status 0 indicates that the creation of process failed
	{
		cout << "creation of process failed due to error(" << ")" << GetLastError() << endl;
	}
	WaitForSingleObject(ProcessInfo.hProcess, INFINITE);//wait until child process exits
	cout << "the process id of current process is : " << GetCurrentProcessId() << endl;
	cout << "the thread id of current process is : " << GetCurrentThreadId() << endl;
	cout << "the process id of current process is : " << GetProcessId(ProcessInfo.hProcess)<< endl;
	cout << "the thread id of current process is : " << GetThreadId(ProcessInfo.hThread) << endl;
	cout << "the process id of current process is : " << GetProcessIdOfThread(ProcessInfo.hThread) << endl;
	CloseHandle(ProcessInfo.hProcess);//close handles of process and thread
	CloseHandle(ProcessInfo.hThread);
}
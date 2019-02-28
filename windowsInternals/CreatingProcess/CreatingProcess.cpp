#include<Windows.h>
#include<iostream>
#include<tchar.h>

using namespace std;

int _tmain(int argc, WCHAR *argv[], WCHAR *env[])
{
	STARTUPINFO StartUpInfo,StartUpInfo1;
	PROCESS_INFORMATION ProcessInfo,ProcessInfo1;
	ZeroMemory(&StartUpInfo, sizeof(StartUpInfo));
	ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
	StartUpInfo.cb = sizeof(StartUpInfo);
	ZeroMemory(&StartUpInfo1, sizeof(StartUpInfo1));
	ZeroMemory(&ProcessInfo1, sizeof(ProcessInfo1));
	StartUpInfo1.cb = sizeof(StartUpInfo1);
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
	WaitForSingleObject(ProcessInfo.hProcess,INFINITE);//wait until child process exits
	cout << "the process id is : " << ProcessInfo.dwProcessId << endl;//process if of the process opened present in the process information
	CloseHandle(ProcessInfo.hProcess);//close handles of process and thread
	CloseHandle(ProcessInfo.hThread);

	//second process

	Status = CreateProcess(NULL,//null if the application name is not given using variable but using command line arguments
		argv[2],//application name given as command line argument 
		NULL,//process not inheritable if null
		NULL,//thread not inheritable if null
		FALSE,//handle inheritance not possible
		0,//flags
		NULL,//use parents environment variables
		NULL,//use parents directory
		&StartUpInfo1,//startup information
		&ProcessInfo1);//process information
	if (Status == 0)//status 0 indicates that the creation of process failed
	{
		cout << "creation of process failed due to error(" << ")" << GetLastError() << endl;
	}
	WaitForSingleObject(ProcessInfo1.hProcess, INFINITE);//wait until child process exits
	cout << "the process id is : " << ProcessInfo1.dwProcessId << endl;//process if of the process opened present in the process information
	CloseHandle(ProcessInfo1.hProcess);//close handles of process and thread
	CloseHandle(ProcessInfo1.hThread);
	return 0;
}
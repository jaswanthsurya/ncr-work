#include<Windows.h>
#include<iostream>
#include<tchar.h>

using namespace std;

int _tmain(int argc, WCHAR *argv[], WCHAR* env[])
{
	SECURITY_ATTRIBUTES Attribute;
	Attribute.nLength = sizeof(Attribute);
	Attribute.bInheritHandle = TRUE;
	Attribute.lpSecurityDescriptor = NULL;
	HANDLE CreateFileHandler;
	CreateFileHandler = CreateFile(argv[1],//name of the file which need to be accessed
		GENERIC_WRITE,//type of access required on the file wether read or write or anyone
		0,//shared mode if 0 indicates that the file cannot be accessed by other process
		&Attribute,//security attribute indicates that it cannot be inherited if the value is NULL
		CREATE_ALWAYS,//the indicator to tell wether a new file is to be created or an existing file need to be opened
		FILE_ATTRIBUTE_NORMAL,//flag
		NULL);
	if (CreateFileHandler == INVALID_HANDLE_VALUE)
	{
		cout << "handle initiation failed due to error code: " << GetLastError() << endl;//get the error code when any error has occured in creating file handler
		wcout << "failed to open file: " << argv[1] << endl;
	}
	else
	{
		cout << CreateFileHandler<<endl;
		TCHAR Handle[] = { (TCHAR)CreateFileHandler };
		//TCHAR Handle[] = { TEXT("hello") };
		STARTUPINFO StartUpInfo;
		PROCESS_INFORMATION ProcessInfo;
		ZeroMemory(&StartUpInfo, sizeof(StartUpInfo));
		ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
		StartUpInfo.cb = sizeof(StartUpInfo);
		BOOL Status = 0;
		Status = CreateProcess(argv[2],//null if the application name is not given using variable but using command line arguments
			Handle,//application name given as command line argument 
			&Attribute,//process not inheritable if null
			NULL,//thread not inheritable if null
			TRUE,//handle inheritance possible
			0,//flags
			NULL,//use parents environment variables
			NULL,//use parents directory
			&StartUpInfo,//startup information
			&ProcessInfo);//process information
		if (Status == 0)//status 0 indicates that the creation of process failed
		{
			cout << "creation of process failed due to error(" << ")" << GetLastError() << endl;
		}
	}
	return 0;
}
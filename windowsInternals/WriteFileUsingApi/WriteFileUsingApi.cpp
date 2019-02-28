#include<iostream>
#include<Windows.h>
#include<tchar.h>

using namespace std;

int _tmain(int argc,WCHAR *argv[],WCHAR *env[])//command line api provided by windows 
{
	HANDLE CreateFileHandler;//handler to the create file api
	CreateFileHandler = CreateFile(argv[1],//file name given as command line argument
		GENERIC_WRITE,//access on the file wether to read or write
		0,//shared mode wether we need to provide access for other resources to use this file
		NULL,//security attributes
		CREATE_NEW,//create disposition wether to write or read the file
		FILE_ATTRIBUTE_NORMAL,//attribute of the file wether it is hidden or archived
		NULL);
	if (CreateFileHandler == INVALID_HANDLE_VALUE)//if handler creation failed it returns invalide handle value to the handler
	{
		cout << "the creation of handler exited with a code: " << GetLastError() << endl;
		wcout << "error in writing the file" << argv[1] << endl;
	}
	else
	{
		WCHAR OutBuffer[] = L"create a handler and written values in it";//outbuffer containing the contents to be written
		DWORD OutBufferLen = wcslen(OutBuffer) + 1;//length of the buffer to be written to the file
		DWORD NoOFBytesWritten = 0;//variable to get the value of number of bytes written from the function
		BOOL Status = 0;//success status indicator
		Status = WriteFile(CreateFileHandler,//file handler generated using create file api to access the file in read or write mode
			OutBuffer,//out buffer containing the values to be written in the file
			OutBufferLen,//length of the out buffer including the null character i.e. consider the length with null termination
			&NoOFBytesWritten,//output value of the function which returns the no of bytes written to the file
			NULL);
		if (Status == 0)//status 0 indicates writing to file failed
		{
			cout << "writing to the file exited with code: " << GetLastError() << endl;
			cout << "writing to the file failed" << endl;
		}
		else//status is 1 indicates the file writing has succeded
		{
			cout << "writing to the file succeded.................................." << endl;
			_tprintf(_T("the contents written to the file %s are %s\n"), argv[1], OutBuffer);
			cout << "check the contents of the file to get the success status" << endl;
		}
	}
	CloseHandle(CreateFileHandler);
	return 0;
}
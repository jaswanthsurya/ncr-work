#include<iostream>
#include<Windows.h>
#include<tchar.h>

using namespace std;

int _tmain(int argc, TCHAR *argv[], WCHAR *env[])//command line api provided by windows 
{
	//_tprintf(_T("%s"), argv[0]);
	HANDLE CreateFileHandler = (HANDLE)*(argv[0]);
	WCHAR OutBuffer[] = L"create a handler and written values in it";//outbuffer containing the contents to be written
	DWORD OutBufferLen = wcslen(OutBuffer) + 1;//length of the buffer to be written to the file
	DWORD NoOFBytesWritten = 0;//variable to get the value of number of bytes written from the function
	BOOL Status = 0;//success status indicator
	Status = WriteFile(CreateFileHandler,//file handler generated using create file api to access the file in read or write mode
		OutBuffer,//out buffer containing the values to be written in the file
		sizeof(WCHAR)*OutBufferLen,//length of the out buffer including the null character i.e. consider the length with null termination
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
		cout << "check the contents of the file to get the success status" << endl;
	}
CloseHandle(CreateFileHandler);
return 0;
}
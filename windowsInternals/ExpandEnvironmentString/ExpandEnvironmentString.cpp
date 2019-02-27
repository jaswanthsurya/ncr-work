#include<Windows.h>
#include<iostream>

using namespace std;

#define BUFFERSIZE 100//output buffer size

int main()
{
	TCHAR SourceString[] = { TEXT("%systemroot%")};//environment variable in the source string 
	TCHAR DestString[BUFFERSIZE];//destination string to hold the expanded version of environment variable
	DWORD SourceSize = wcslen(SourceString)+1;//size of the source string
	DWORD DestSize;//Destination size required to hold the expanded string
	DestSize = ExpandEnvironmentStringsW(SourceString,//source string starting address
		DestString,//pointer to the destination string to store the expanded output
		SourceSize);//size of the input string
	if (DestSize > BUFFERSIZE)//if the given buffersize is lesser than the output size then there is a error
	{
		cout << "cannot hold the expanded version of environment variable due to error code:" << GetLastError() << endl;
		return 0;
	}
	else
	{
		cout << "the size required to hold the expanded environment variable is: " << DestSize << endl;
		wcout << "the Expanded Environment String is: " << DestString << endl;
	}
	return 0;
}
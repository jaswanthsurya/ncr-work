#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;

int _tmain(int argc, WCHAR* argv[], WCHAR* env[])
{
	HANDLE handle = (HANDLE)(*argv[0]);
	if (!SetPriorityClass(handle, BELOW_NORMAL_PRIORITY_CLASS))
	{
		cout << "priority modification failed due to error (" << GetLastError() << ")" << endl;
	}
	return 0;
}
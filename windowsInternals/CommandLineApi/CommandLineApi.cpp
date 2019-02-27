#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{
	LPWSTR *args;
	int argSize;
	args = CommandLineToArgvW(GetCommandLine(), &argSize);
	for (int i = 0; i < argSize; i++)
	{
		wcout << "[" << i << "]: " << args[i] << endl;
	}
	return 0;
}
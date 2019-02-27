#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{
	LPWSTR *args;
	int argSize;
	args = CommandLineToArgvW(GetCommandLine()//returnrs the address of the command string 
		, &argSize//return the size of the total number of arguments it is a output parameter for the function 
	);//function to retrieve the command line arguments without using arguments for the main() the return type is a long pointer to wide string
	for (int i = 0; i < argSize; i++)
	{
		wcout << "[" << i << "]: " << args[i] << endl;//wcout to print the widestring characters
	}
	return 0;
}
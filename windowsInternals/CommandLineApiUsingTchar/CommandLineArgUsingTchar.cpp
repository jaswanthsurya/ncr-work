#include<Windows.h>
#include<iostream>
#include <tchar.h>

using namespace std;

int _tmain(int argc//argument count
	, WCHAR * argv[],//agrument list
	WCHAR * env[]//windows provides an additional parameter for the _tmain() function which is the environmental variables 
)
{
	for (int counter = 0; counter < argc; counter++)
	{
		wcout << argv[counter] << endl;
	}
	return 0;
}
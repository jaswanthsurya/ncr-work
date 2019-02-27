#include<Windows.h>
#include<iostream>
#include <tchar.h>

using namespace std;

int _tmain(int argc//argument count
	, TCHAR argv[],//agrument list
	TCHAR env[]//windows provides an additional parameter for the _tmain() function which is the environmental variables 
)
{
	for (int counter = 0; counter < argc; counter++)
	{
		cout << argv[counter] << endl;
	}
	return 0;
}
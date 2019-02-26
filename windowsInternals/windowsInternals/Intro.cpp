#include<windows.h>
#include<iostream>

using namespace std;

int main()
{
	CHAR arr='A'; //character datatype of size 8 bits
	WCHAR arr1 = 'A'; //wide character 16 bit unicode format
	cout << "the size of CHAR datatype is : " << sizeof(CHAR) << endl; //prints the size of char as per ASCI set
	cout << "the size of WCHAR datatype is : " << sizeof(WCHAR) << endl;//prints the size of char as per UNICODE set
	CHAR aarr[] = "ANSI";
	WCHAR uarr[] = L"UNICODE";
	BOOL res;
	wcout << "the length of char string " << aarr << " is: " << strlen(aarr) << endl;//strlen used to find length of ANSI character array
	wcout << "the length of wide char string "<< uarr << " is: " << wcslen(uarr)<<endl;//wcslen used to find length of UNICODE character array
	
	
	res = IsTextUnicode(aarr, strlen(aarr), NULL);//function to check wether text is UNICODE or not
	cout << endl << endl;
	cout << "checking wether CHAR array is UNICODE or not............" << endl;
	if (res == 1)
	{
		cout << "the string" << aarr << " is UNICODE" << endl;
	}
	else
	{
		cout << "the string " << aarr << "is not UNICODE" << endl;
	}
	cout << endl << endl;
	
	
	cout << "checking wether WCHAR array is UNICODE or not..............." << endl;
	res = IsTextUnicode(uarr, wcslen(uarr), NULL);//function to check wether text is UNICODE or not 
	if (res == 1)
	{
		cout << "the string" << uarr << "is UNICODE" << endl;
	}
	else
	{
		cout << "the string " << uarr << "is not UNICODE" << endl;
	}
	cout << endl << endl;
	
	
	cout << "Multibyte to wide char conversion...." << endl;
	int WcharSize = 0;//variable to hold the wchar size 
	WcharSize = MultiByteToWideChar(CP_UTF8,//code page of encoding format
		0,//dwflags should be set to 0 when UTF8 is used
		aarr,//input ANSI array
		-1,//-1 if the string is NULL terminated
		NULL,//output pointer intially null as output size is undefined
		0);
	cout << "the size of multibyte format of the converted String ANSI is: " << WcharSize << endl;
	
	
	PWCHAR outp = new WCHAR[WcharSize];
	int status;
	status = MultiByteToWideChar(CP_UTF8,//code page of encoding format
		0,//dwflags should be set to 0 when UTF8 is used
		aarr,//input ANSI array
		-1,//-1 if the string is NULL terminated
		outp,//output pointer to store WCHAR variables
		WcharSize);
	
	
	if (status)
	{
		wcout << "conversion successfull and the output string in unicode format is: " << outp << endl;
	}
	else
	{
		cout << "conversion failure " << endl;
	}
	cout << endl << endl;
	
	
	
	
	cout << "wide char to multibyte conversion......." << endl;
	int AnsiSize = 0;//to store the size of Ansi string
	AnsiSize = WideCharToMultiByte(CP_UTF8,//code page
		0,//dwflag set to 0 when utf8 is used
		uarr,//input wchar array
		-1,//if the string is NULL terminated
		NULL,//output pointer null
		0,//output size undefined initially so set to 0 and the function returns the size of ANSI required
		NULL,//null when utf8 is used
		NULL);//null when utf8 is used
	
	cout << "the size of ANSI string required for conversion of UNICODE is :" << AnsiSize << endl;
	
	PCHAR outp1 = new CHAR[AnsiSize];//pointer to store the ANSI string
	int status1;//to return the conversion status
	status1 = WideCharToMultiByte(CP_UTF8,//code page
		0,//dwflag set to 0 when utf8 is used
		uarr,//input wchar array
		-1,//if the string is NULL terminated
		outp1,//output pointer null
		AnsiSize,//output size undefined initially so set to 0 and the function returns the size of ANSI required
		NULL,//null when utf8 is used
		NULL);//null when utf8 is used
	
	
	if (status1)
	{
		cout << "conversion successfull and the ANSI string is : " << outp1 << endl;
	}
	else
	{
		cout << "conversion failure" << endl;
	}

	delete(outp);
	delete(outp1);//delete allocated memory
	return 0;
}
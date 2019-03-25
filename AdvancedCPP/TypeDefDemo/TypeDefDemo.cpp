#include<iostream>
using namespace std;

typedef int Myint;
typedef float Myfloat;
typedef double Mydouble;

int main()
{
	Myfloat typedfloat=0.0;
	Myint typedint=0;
	Mydouble typeddouble=0.00;
	cout << "enter double value :";
	cin >> typeddouble;
	while (cin.fail())//taking input until correct value is entered
	{
		cin.clear();//clears error flags
		cin.ignore();//ignore the character at that instant
		cout << "entered invalid input" << endl << endl;
		cout << "enter input again :";
		cin >> typeddouble;//take input again
	}
	cout << endl;
	cout << "enter float value :";
	cin >> typedfloat;
	cout << endl;
	cout << "enter int value :";
	cin >> typedint;
	cout << endl;
	cout << "double value: " << typeddouble << endl << "floatvalue :" << typedfloat << endl << "Int value:" << typedint << endl;
	return 0;
}
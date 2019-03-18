/*this program is to demonstrate inline function usage, in general inline functions are same as the preprocessor directives
but in case of preprocessor directives there is no error checking as they are executed before compilation
so inorder to provide error checking inline functions are introduced in general inline functions are represented using
keyword inline and the operations are performed and the value is returned when the inline function is called the lines in
the functions are substituted at the calling site
*/

#include<iostream>

using namespace std;
inline int sum(int a, int b)//inline function for sum
{
	return (a + b);
}

inline int sub(int a, int b)//inline function for subtraction
{
	return (a - b);
}

inline long int mul(int a, int b)//inline function for multiplication
{
	return (a*b);
}

inline int divi(int a, int b)//inline function for division
{
	if (b == 0)//checking divide by zero error
	{
		cout << "division error" << endl;
		return -1;
	}
	return (a/b);
}


int main()
{
	int add=0, a=0,b=0, di=0, su=0;
	long int mu = 0;
	cout << "enter two numbers for performing arithmetic operations" << endl;
	cin >> a;
	cin >> b;
	cout << "the sum of two numbers using inline function: ";
	add = sum(a, b);//call to inline function
	cout << add << endl;
	cout << "the product of two numbers using inline function: ";
	mu = mul(a, b);//call to inline function
	cout << mu << endl;
	cout << "the division of two numbers using inline function: ";
	di = divi(a, b);//call to inline function
	cout << di << endl;
	cout << "the difference of two numbers using inline function: ";
	su = sub(a, b);//call to inline function
	cout << su << endl;
	return 0;
}
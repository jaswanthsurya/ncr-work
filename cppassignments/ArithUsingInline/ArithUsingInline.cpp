#include<iostream>

using namespace std;
inline int sum(int a, int b)
{
	return (a + b);
}

inline int sub(int a, int b)
{
	return (a - b);
}

inline long int mul(int a, int b)
{
	return (a*b);
}

inline int divi(int a, int b)
{
	return (a/b);
}


int main()
{
	int add=0, a=0,b=0, di=0, su=0;
	long int mu = 0;
	cout << "enter the numbers" << endl;
	cin >> a;
	cin >> b;
	cout << "the sum of two numbers using inline function: ";
	add = sum(a, b);
	cout << add<<endl;
	cout << "the product of two numbers using inline function: ";
	mu = mul(a, b);
	cout << mu<<endl;
	cout << "the division of two numbers using inline function: ";
	di = divi(a, b);
	cout << di<<endl;
	cout << "the difference of two numbers using inline function: ";
	su = sub(a, b);
	cout << su<<endl;
	return 0;
}
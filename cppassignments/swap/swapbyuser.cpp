/*program to demonstrate the use of call by value and call by reference*/

#include<iostream>

using namespace std;
void swapbyval(int, int);//prototype for call by value function
void swapbyref(int *, int *);//prototype for call by reference function
int main()
{
	int n = 0,a=0,b=0;
	cout << "enter input to proceed" << endl;
	cout << "1.swap by value" << endl;
	cout << "2.swap by reference" << endl;
	cin >> n;
	cout << "enter the values" << endl;
	cin >> a;
	cin >> b;
	switch (n)
	{
	case 1:swapbyval(a,b);
		break;
	case 2:swapbyref(&a,&b);
		break;
	default: cout << "invalid" << endl;
	}
	cout<<"result after swapping" << endl;
	cout << a << " " << b << endl;
	return 0;
}
void swapbyval(int a, int b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void swapbyref(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
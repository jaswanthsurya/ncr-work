#include<iostream>

using namespace std;

extern "C" 
{
	void add(int, int);
	void sub(int, int);
}/*method to link external c functions this can be done by just specifying the prototype of the function*/

int main()
{
	int x = 0, y = 0;
	cout << "enter two numbers: ";
	cin >> x >> y;
	add(x, y);//call to c function included externally
	sub(x, y);//call to c function included externally
	return 0;
}
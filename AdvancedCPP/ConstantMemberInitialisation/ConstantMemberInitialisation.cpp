#include<iostream>

using namespace std;

class Myclass {
	const int x;
	const int y;//constant member variables
public:
	Myclass(int a, int b):x(a),y(b)//syntax for initialisation for constant members
	{

	}
	void disp()
	{
		cout << "the values are: " << x << " " << y << endl;
	}
	~Myclass()//destructor
	{

	}
};

class Myclass1
{
	int x;
	int y;
public:
	Myclass m;
	Myclass1(int x, int y) :m(x, y)//syntax for member function initialisation
	{
		this->x = x;
		this->y = y;
	}
	void disp()
	{
		cout << "the values are :" << x << " " << y << endl;
	}
	~Myclass1()//destructor
	{

	}
};

int main()
{
	int x, y;
	cout << "enter two elements: ";
	cin >> x >> y;
	Myclass1 m1(x, y);
	m1.m.disp();//call to display function of myclass object through myclass1 object
	m1.disp();//call to display function of myclass1
	return 0;
}
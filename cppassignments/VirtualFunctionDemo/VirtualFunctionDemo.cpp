/*this program is to demonstrate the use of virtual function
in general when a function is overrided in the parent class and child class
then if that overrided function is called by using derived class object the function in the base class is 
called this is genrally called compile time binding where as in case if we use virtual function when a method in
base class is defined by using virtual keyword and it is overrided in the derived class then when this method is
called by using the object of the derived class the method in the child class is only called this is acheived by using
runtime linking with the help of virtual table 
*/
#include<iostream>

using namespace std;

class Shape
{
public:
	void area(int a,int b);
	void NonVirtualDisplay()//non virtual display function binded at compile time 
	{
		cout << "base class non virtual display function" << endl;
	}
	virtual void Display()//virtual display function binded during run time
	{
		cout << "base class display function" << endl;
	}
	void master()
	{
		cout << "in master" << endl;
	}
};

class triangle :public Shape
{
public:
	void area(int b, int h)
	{
		cout << "area is :" << (0.5)*b*h << endl;
	}
	void Display()//overriding the virtual function in the child class
	{
		cout << "triangle class display function" << endl;
	}
	void NonVirtualDisplay()//overriding non virtual function in child class
	{
		cout << "triangle class non virtual display function" << endl;
	}
};

class Square :public Shape
{
public:
	void area(int b, int h)
	{
		cout << "area is :" << b*h << endl;
	}
	void Display()//overriding the virtual function in the child class
	{
		cout << "Square class display function" << endl;
	}
	void NonVirtualDisplay()//overriding non virtual function in child class
	{
		cout << "Square class non virtual display function" << endl;
	}
};

class rectangle :public Shape
{
public:
	void area(int l, int b)
	{
		cout << "area is :" << b * l << endl;
	}
	void Display()//overriding the virtual function in the child class
	{
		cout << "rectangle class display function" << endl;
	}
	void NonVirtualDisplay()//overriding non virtual function in child class
	{
		cout << "rectangle class non virtual display function" << endl;
	}
};

int main()
{
	Shape *p;
	triangle t;
	Square s;
	rectangle r;
	cout << "calling virtual functions from individual objects " << endl << endl;
	t.Display();
	s.Display();
	r.Display();//calling overrided virtual functions which results in calling the function that belong to the same class
	cout << endl << endl;
	cout << "calling non virtual functions from individual objects" << endl << endl;
	t.NonVirtualDisplay();
	s.NonVirtualDisplay();
	r.NonVirtualDisplay();/*calling non virtual function that is overrided in the derived class this type will always call
						  the function in the base class*/
	cout << endl << endl;
	cout << "calling functions using base class pointer that is assigned to triangle class" << endl << endl;
	p = &t;
	p->Display();
	p->NonVirtualDisplay();
	return 0;
}
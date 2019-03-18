/*program to observe deep copy and shallow copy concepts*/

#include<iostream>

using namespace std;

class Demo
{
private:
	int a, b;//private section
public://public section
	Demo()//constructor
	{
		a = 0, b = 0;
	}
	Demo(Demo &s)//copy constructor for deep copying
	{
		a = s.a;
		b = s.b;
	}
	void display()
	{
		cout << "a:" << a <<"\n" << "b:" << b << endl;
	}
	~Demo()//destructor
	{

	}
};

int main()
{
	Demo d1, d2(d1);//using deep copy method in the class
	Demo d3;
	d3 = d2;/*using default copy constructor provided by c++
			this case is sufficient for most of the cases but in certain cases this will not be necessary
			because the two objects can point to same location leading to dangling reference*/
	d3.display();
	d2.display();
	return 0;
}
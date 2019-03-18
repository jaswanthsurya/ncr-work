/*program to create a class that stores values of the polar coordinates and also a static variable to count the 
number of active objects*/

#include<iostream>

using namespace std;
class polar {
	int angle;
	int radius;
public:
	static int count;//static object to count number of active objects which is incremented when object is created and decremented when object is destructed
	polar()//default constructor
	{
		cout << "in default constructor" << endl;
		count++;
	}
	polar(int a)//parameterised constructor
	{
		cout << "in parameterised constructor" << endl;
		radius = angle = a;
		count++;
	}
	polar(int r, int a)//parameterised constructor
	{
		cout << "in double parameterised constructor" << endl;
		radius = r;
		angle = a;
		count++;
	}
	polar(polar &p)//copy constructor
	{
		cout << "in copy constructor" << endl;
		radius = p.radius;
		angle = p.angle;
		count++;
	}
	~polar()//destructor
	{
		count--;
		cout << "number of active members are : " << count<<endl;
	}
};
int polar::count;//static member included in polar class
int main()
{
	polar p1;
	polar p2(1);
	{
		polar p3(1, 2);
	}
	polar p4(p1);
	{
		polar p5(p2);
	}
	return 0;
}
#include<iostream>

using namespace std;
class polar {
	int angle;
	int radius;
public:
	static int count;
	polar()
	{
		cout << "in default constructor" << endl;
		count++;
	}
	polar(int a)
	{
		cout << "in parameterised constructor" << endl;
		radius = angle = a;
		count++;
	}
	polar(int r, int a)
	{
		cout << "in double parameterised constructor" << endl;
		radius = r;
		angle = a;
		count++;
	}
	polar(polar &p)
	{
		cout << "in copy constructor" << endl;
		radius = p.radius;
		angle = p.angle;
		count++;
	}
	~polar()
	{
		count--;
		cout << "number of active members are : " << count<<endl;
	}
};
int polar::count;
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
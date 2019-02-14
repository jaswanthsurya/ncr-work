#include<iostream>

using namespace std;

class Distance {
	int xcord;
	int ycord;
public:
	void assign(int x, int y)
	{
		xcord = x;
		ycord = y;
	}
	friend void dist(Distance, Distance);
};

void dist(Distance d1, Distance d2)
{
	cout << (((d2.xcord - d1.xcord)*(d2.xcord - d1.xcord)) + ((d2.ycord - d1.ycord)*(d2.ycord - d1.ycord))) << endl;
}

int main()
{
	int a = 0, b = 0;
	Distance d1, d2;
	cout << "enter x and y cordinates of point one" << endl;
	cin >> a >> b;
	d1.assign(a, b);
	cout << "enter x and y cordinates of point two" << endl;
	cin >> a >> b;
	d2.assign(a, b);
	cout << "the distance between two points is: " << endl;
	dist(d1, d2);
	return 0;
}
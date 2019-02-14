#include<iostream>

using namespace std;
class Distance2;
class Distance1 {
	float lengthinM;
	float lengthinCM;
public:
	friend void calLen(Distance1,Distance2,int a);
	void assign(float a)
	{
		lengthinM = a;
		lengthinCM = 100*a;
	}
	void display()
	{
		cout << "length in meters and centimeters respectively is: " << lengthinM << " "<<lengthinCM << endl;
	}
};

class Distance2 {
	float lengthinIn;
	float lengthinFe;
public:
	friend void calLen(Distance1,Distance2,int a);
	void assign(float a)
	{
		lengthinIn = a;
		lengthinFe = a / 12;
	}
	void display()
	{
		cout << "length in inches and feets respectively is: " << lengthinIn << " " << lengthinFe << endl;
	}
};

void calLen(Distance1 d1,Distance2 d2,int a)
{
	if (a == 1)
	{
		Distance1 d3;
		d3.assign((d1.lengthinM + (d2.lengthinIn*0.3048)));
		d3.display();
	}
	else
	{
		Distance2 d3;
		d3.assign(((d1.lengthinM*39.27) + d2.lengthinIn));
		d3.display();
	}
}

int main()
{
	Distance1 d1;
	Distance2 d2;
	float a = 0;
	int b = 0;
	cout << "enter distance in meters" << endl;
	cin >> a;
	d1.assign(a);
	cout << "enter distance in inches" << endl;
	cin >> a;
	d2.assign(a);
	cout << "enter your choice" << endl;
	cout << "1. output in meters" << endl;
	cout << "2. output in inches" << endl;
	cin >> b;
	calLen(d1,d2,b);
	return 0;
}
#include<iostream>

using namespace std;

class overload
{
	int x;
	int y;
public:
	overload()
	{
		x = 0;
		y = 0;
	}
	overload(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	overload(int x)
	{
		this->x = x;
		this->y = x;
	}
	void disp()
	{
		cout << "the value of x :" << x << endl;
		cout << "the value of y :" << y << endl;
	}
	overload operator+(overload &e)
	{
		this->x = this->x + e.x;
		this->y = this->y + e.y;
		return (*this);
	}
	overload operator-(overload &e)
	{
		this->x = this->x - e.x;
		this->y = this->y - e.y;
		return (*this);
	}
	overload operator-()
	{
		this->x = -(this->x);
		this->y = -(this->y);
		return (*this);
	}
	friend ostream& operator<<(ostream& cout, overload &o);
	friend istream& operator>>(istream& cin, overload &o);
	overload operator++(int x)//postfix
	{
		overload o;
		o.x = this->x++;
		o.y = this->y++;
		return o;
	}
	overload operator++()
	{
		++x;
		++y;
		return *this;
	}
};

ostream& operator<<(ostream& cout, overload &o)
{
	cout << o.x << endl;
	cout << o.y << endl;
	return cout;
}

istream& operator>>(istream& cin, overload &o)
{
	cin >> o.x;
	cin >> o.y;
	return cin;
}

int main()
{
	overload o1;
	overload o2(1, 2);
	overload o3;
	o3 = o3 + o2;
	overload o4(10,10);
	o4 = o4 - o3;
	cout << "values of object three" << endl;
	o3.disp(); 
	cout << "values of object four" << endl;
	o4.disp();
	o2 = -o2;
	o2.disp();
	cout << "display using overloaded operator: " << endl;
	cout << o4;
	overload o5;
	cout << "enter values" << endl;
	cin >> o5;
	cout << "display using overloaded operator: " << endl;
	cout << o5;
	cout <<"overloading prefix and postfix operators" << endl;
	o5 = o4++;
	cout << "postfix operation on object four" << endl;
	cout << o4;
	++o4;
	cout << "prefix operation on object four" << endl;
	cout << o4;
	cout << "overloading comma operator" << endl;
	o4 = (o3, o2, o1);
	cout << o4;
	return 0;
}
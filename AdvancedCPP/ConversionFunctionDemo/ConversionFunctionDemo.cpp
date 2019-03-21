#include<iostream>

using namespace std;

class _ConvoDemo_//class to demonstarte the use of conversion functions
{
	double base;
	int power;
	double val;
public:
	_ConvoDemo_()//default constructor
	{
		base = power = 0;
		val = 1;
	}
	_ConvoDemo_(double base, int power)/*parameterised constructor that takes the base and power as input and
									   generates the value of the result*/
	{
		this->base = base;
		this->power = power;
		val = 1;
		for (; power != 0; power--)
		{
			val = val * base;
		}
	}
	_ConvoDemo_ operator+(_ConvoDemo_ o)/*overloaded function for performing addition of objects and generating
										the result object*/
	{
		double resBase;
		int resPow;
		resBase = this->base + o.base;
		resPow = this->power + o.power;
		_ConvoDemo_ temp(resBase, resPow);
		return temp;
	}
	double getVal() const {/*getter for getting the private variables of the class this function is made constant
						   because the getter functions are accessing the private variable of the class so they should 
						   have only read only permissions*/
		return val;
	}
	operator double()/*conversion function that return the value of the result to a double variable
						   this is used when a variable of datatype double is assigned with an object*/
	{
		return this->val;
	}
	~_ConvoDemo_()//destructor
	{
		base = power = 0;
		val = 1;
	}
};


int main()
{
	_ConvoDemo_ d1(2, 3), d2(2, 0);
	double res = 0;
	_ConvoDemo_ temp = d1 + d2;//this statement makes a call to the overloaded function
	res = d1 + d2;//this statement makes a call to the conversion function
	cout << "the value of the result is :" << temp.getVal() << endl;
	cout << "the value of the result is :" << res;
	return 0;
}
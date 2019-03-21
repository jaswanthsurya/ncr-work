#include<iostream>

using namespace std;

class _CONSTCLASSDEMO_//class to demonstrate constant member functions in a class and their use
{
	mutable int val1;/*mutable identifier indicates that even though if the member function is const it can modify 
					 the value of the variable since it is mutable*/
	int val2;
public:
	_CONSTCLASSDEMO_()//default constructor
	{
		val1 = val2 = 0;
	}
	_CONSTCLASSDEMO_(int val1, int val2)//parameterised constructor
	{
		this->val1 = val1;
		this->val2 = val2;
	}
	~_CONSTCLASSDEMO_()//destructor
	{
		val1 = val2 = 0;
	}

	int getVal() const/*getter function to get the value of the private variables made constant since it should not 
					  modify the values of private variables*/
	{
		return val1;
	}
	void setVal(int val)//setter function to set the values of the variables
	{
		val1 = val2 = val;
	}
	void setValConst(int val) const {
		val1 = val;//as val1 is mutable the const function can modify the value of the variable
		//val2 = val;//this gives and error since the var2 is not mutable
	}
};

int main()
{
	_CONSTCLASSDEMO_ c1(2, 3), c2(3, 4);//objects creation using parameterised constructor
	const _CONSTCLASSDEMO_ c3(2, 3);
	cout << c1.getVal() << endl;//call to const getter function in the object
	c1.setVal(2);//call to non constant function
	c1.setValConst(2);//call to constant function modifying the mutable object
	cout << c1.getVal() << endl;

	/*c3.setVal(2);*//*this throws an error because the const object of the class has been initialised
				 so as it is const we cannot modify the contents of the object*/
	return 0;
}
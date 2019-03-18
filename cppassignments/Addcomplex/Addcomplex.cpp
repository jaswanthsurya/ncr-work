/*this program is to add and multiply two complex numbers using friend functions
friend functions are used when any external function other than member functions
try to access the class variables, generally member functions only can access the private 
variables of the class in order to make external functions access the private variables they need to be friend function*/


#include<iostream>
#include<string.h>
#include<typeinfo>//for getting type of variables

using namespace std;
class complexnum {
	int img;
	int real;
public:
	complexnum()//default constructor
	{
		img = real = 0;
	}
	complexnum(int n)//parameterised contructor
	{
		img = real = n;
	}
	complexnum(int n, int n1)//parameterised constructor
	{
		real = n;
		img = n1;
	}
	//friend functions to add and multiply two complex numbers
	friend void complexadd(complexnum a, complexnum b);
	friend void complexmul(complexnum a, complexnum b);
	~complexnum()//destructor
	{

	}
};

void complexadd(complexnum a, complexnum b)//complex addition functions
{
	cout << "upon adding two complex numbers :" << "(" << (a.real + b.real) << ")" << "+i" << "(" << (b.img + a.img) << ")" << endl;
}
void complexmul(complexnum a, complexnum b)//complex multiplication function
{
	cout << "upon multiplying two complex number :" << "(" << ((a.real * b.real) - (a.img * b.img)) << ")" << "+i" << "(" << ((a.real * b.img) + (a.img * b.real)) << ")" << endl;
}
int main()
{
	int real1=0,
		real2=0,
		img1=0, 
		img2=0;
	cout << "using type (" << typeid(real1).name() << ") for all the variables so provide inputs accordingly" << endl;
	cout << "enter the real part of the first complex number :";
	cin >> real1;
	if (cin.fail())
	{
		cout << "provided wrong input " << endl;
		return 0;
	}
	cout << "enter the imaginary part of the first complex number :";
	cin >> img1;
	if (cin.fail())
	{
		cout << "provided wrong input " << endl;
		return 0;
	}
	cout << "enter the real part of the second complex number :";
	cin >> real2;
	if (cin.fail())
	{
		cout << "provided wrong input " << endl;
		return 0;
	}
	cout << "enter the imaginary part of the second complex number :";
	cin >> img2;
	if (cin.fail())
	{
		cout << "provided wrong input " << endl;
		return 0;
	}
	if (real1 == 0 && real2 == 0 && img1 == 0 && img2 == 0)
	{
		cout << endl;
		cout << endl;
		cout << "entered invalid input " << endl;
		cout << "process terminated" << endl;
		return 0;
	}
	complexnum a(real1,img1), b(real2,img2);//complex objects created using parameterised constructor
	complexadd(a, b);//addition function
	complexmul(a, b);//multiplication function
	return 0;
}
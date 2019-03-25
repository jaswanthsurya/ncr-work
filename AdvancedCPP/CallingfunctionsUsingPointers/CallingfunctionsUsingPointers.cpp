#include<iostream>

using namespace std;

class Operate
{
public:
	Operate()//default constructor
	{

	}
	virtual int operator()(int x, int y) = 0;
	~Operate()//destructor
	{
		cout << "in parent" << endl;
	}
};

class sum :public Operate{//derived add class
public:
	sum()//default constructor
	{

	}
	int operator()(int x, int y)//overloaded () operator
	{
		return (x + y);
	}
	~sum()//destructor
	{
		cout << "in child add" << endl;
	}
};

class mul :public Operate {//derived mul class
public:
	mul()//default constructor
	{

	}
	int operator()(int x, int y)//overloaded () operator
	{
		return(x*y);
	}
	~mul()//destructor
	{
		cout << "in child mul" << endl;
	}
};

//function object
int Operate_fun(int x, int y, Operate *obj)//function to call class overloaded function depending on the pointer
{
	return (*obj)(x, y);//call to overloaded function ()
}

int Nadd(int x, int y)//normal function add
{
	return x + y;
}

int Nmul(int x, int y)//normal function mul
{
	return x * y;
}

int Noperate(int x, int y, int (*f)(int, int))//calling function
{
	return f(x, y);
}

int main()
{
	Operate *obj1;//base class pointer
	sum obj2;
	mul obj3;
	int x, y = 0;
	cout << "enter two numbers :";
	cin >> x >> y;
	
	//function objects
	cout << "operate function using function objects" << endl;
	obj1 = &obj2;//base class pointer refering to derived class object
	cout << "the addition value of two numbers is: " << Operate_fun(x, y, obj1) << endl;

	obj1 = &obj3;//base class pointer refering to derived class object
	cout << "the multiplication value of two numbers is: " << Operate_fun(x, y, obj1) << endl;


	cout << "operation performed using function pointers" << endl;
	cout << "the addition value of two numbers is: " << Noperate(x, y, Nadd) << endl;
	cout << "the multiplication value of two numbers is: " << Noperate(x, y, Nmul) << endl;
	return 0;
}
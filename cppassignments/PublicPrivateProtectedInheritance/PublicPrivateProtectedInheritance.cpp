#include<iostream>
using namespace std;

/*this program is to show different types of inheritances and the type of access modifications performed 
when a class is inherited*/

class Main
{
public:
	int a;
protected:
	int b;
private:
	int c;
};

class A :public Main
{
	/* in this type of  public inheritance the private members are not accessed by the derived class
	and the public and private members are accessed by the class with the same access specifier*/
};

class B :protected Main
{
	/*in this type of protected inheritance the private members are not accessed by the derived class 
	and the public member access modifier is changed to protected mode and the protected mode of b will remain the same*/
};

class C :private Main
{
	/*in this type of private inheritance all the methods and variables wether may be in any access modifier they will 
	be converted to private mode*/
};

int main()
{
	A a;
	B b;
	C c;
	//cout << c.b;
	//cout << c.c;
	//cout<<c.a; gives an error since a is private member so it is inaccessible
	//cout << b.a;
	//cout << b.b;
	//cout << b.c;a and b are in accessible because they are in proteted mode and c is inaccessible because it is private
	cout << a.a;
	//cout << a.b;
	//cout << a.c; a is accessible because it is public and b,c are inaccessible because they are proteced and private
	return 0;
}
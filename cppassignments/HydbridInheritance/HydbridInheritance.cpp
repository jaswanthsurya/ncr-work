/*program to demonstrate hybrid inheritance and virtual class*/

/*public derivation from base classs
public members will be retained as public
private members will be retained as private
protected members will be retained as protected
*/


#include<iostream>
#include<string.h>
using namespace std;

class person {//base class 
public:
	string name;
	int age;
};

class physique :public person {//child class deriving the base class in public derivation mode
public:
	float height;
	int weight;
};

class family :public person {//child class deriving the base class in public derivation mode
public:
	int numberOfChildren;
	string religion;
};

class employee :public physique, public family {//classs employeee deriving multiple class using hybrid inheritance
public:
	int empno;
	int salary;

};

int main()
{
	person p;
	physique p1;
	family f;
	employee e;
	return 0;
}
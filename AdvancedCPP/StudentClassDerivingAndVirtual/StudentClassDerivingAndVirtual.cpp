#include<iostream>

/*program to demonstartate the use of virtual functions in case of accessing class without virtual functions
when a base class pointer is used to access overrided methods between base and child class if virtual functions
are not used the accessing of functions is done at compile time depending on the type of pointer
where as using virtual keyword the accessing is done based on the virtual table and done at run time
thus run time polymorphism is acheived*/

using namespace std;

class Student {

public:
};

class Engineer :public Student {

};

class Medicine :public Student {

};

class Science :public Student {

};

int main()
{
	return 0;
}
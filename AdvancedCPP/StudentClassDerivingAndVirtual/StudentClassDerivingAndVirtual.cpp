#include<iostream>
#include<string>

/*program to demonstartate the use of virtual functions in case of accessing class without virtual functions
when a base class pointer is used to access overrided methods between base and child class if virtual functions
are not used the accessing of functions is done at compile time depending on the type of pointer
where as using virtual keyword the accessing is done based on the virtual table and done at run time
thus run time polymorphism is acheived*/

using namespace std;

class Student {
protected:
	int id;
	string name;
public:
	Student(int i,string name)//parameterised constructor
	{
		id = i;
		this->name = name;
	}
	virtual void average() = 0;//pure virtual function
};

class Engineer :public Student {
	int maths;
	int physics;
	int tech;
	int noOfSub;
public:
	Engineer(int m, int p, int t, int i, string name) :Student(i, name)//paramterised constructor
	{
		maths = m; physics = p; tech = t;
		noOfSub = 3;
	}
	void average()//overrided virtual function
	{
		cout << "the average marks of engineer " << name << " bearing roll no " << id <<
			" are: " << (maths + physics + tech) / noOfSub << endl;
	}
};

class Medicine :public Student {
	int biology;
	int zoology;
	int noOfSub;
public:
	Medicine(int b, int z, int i, string name) :Student(i, name)//parameterised constructor
	{
		biology = b; zoology = z; noOfSub = 2;
	}
	void average()//overrided virtual function
	{
		cout << "average marks of medicine student " << name << " bearing roll no " << id << 
			" are: " << (biology + zoology) / noOfSub << endl;
	}
};

class Science :public Student {
	int chemistry;
	int lab;
	int noOfSub;
public:
	Science(int c, int l, int i, string name) :Student(i, name)//parameterised constructor
	{
		chemistry = c; lab = l; noOfSub = 2;
	}
	void average()//overrided virtual function
	{
		cout << "average marks of Science student" << name << name << " bearing roll no " << id << 
			" are: " << (chemistry + lab) / noOfSub << endl;
	}
};

int main()
{
	Student *s[3];//pointer of base class
	Engineer eobj(10,10,10,1,"surya");
	Medicine mobj(20,20,2,"jash");
	Science sobj(30,30,3,"hi");
	s[0] = &eobj;
	s[1] = &mobj;
	s[2] = &sobj;//assigning objects to the base class pointer array
	s[0]->average();
	s[1]->average();
	s[2]->average();/*as the average function is virtual the call is done depending on the type of object it is pointed to
				  at run time (thus run time polymorphism is acheived)*/
	return 0;
}
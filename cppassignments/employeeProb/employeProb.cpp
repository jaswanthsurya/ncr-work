/*function to create an employee class with employee details and populate five objects of employees by overloading cin and
cout functions
*/

#include<iostream>

using namespace std;
class employee {
	int empno;
	char name[20];
	long int salary;//employee details
public:
	employee()//constructor
	{

	}
	friend istream& operator>>(istream& cin, employee &e);//overloaded cin function
	friend ostream& operator<<(ostream& cout, employee &e);//overloaded cout function
	~employee()//destructor
	{

	}
};
istream& operator>>(istream& cin, employee &e)
{
	cout << "enter employee number : ";
	cin >> e.empno;
	cout << "enter employee name: ";
	cin >> e.name;
	cout << "enter salary: ";
	cin >> e.salary;
	return cin;
}
ostream& operator<<(ostream& cout, employee &e)
{
	cout << "employee number : ";
	cout << e.empno << endl;
	cout << "employee name: ";
	cout << e.name << endl;
	cout << "salary: ";
	cout << e.salary << endl;
	return cout;
}
int main()
{
	employee e[5];//array of employee objects
	for (int i = 0; i < 5; i++)
	{
		cin >> e[i];
	}
	cout << "employee details are:--------------------------------------------------"<<endl;
	for (int i = 0; i < 5; i++)
	{
		cout << e[i];
	}
	return 0;
}
#include<iostream>
#include<string.h>
#include<string>

using namespace std;

bool flag = 0;
class myString
{
	char *name;
	int length;
public:
	myString()//default constructor 
	{
		name = NULL;
		length = 0;
	}
	myString(string s)//parameterised constructor
	{
		int i = 0;
		for (i = 0; s[i] != '\0'; i++);//find out length of input string
		this->length = i;
		this->name = new char[this->length + 1];
		for (i = 0; i <= this->length; i++)
		{
			this->name[i] = s[i];
		}
	}
	myString(myString &s)
	{
		this->length = s.length;
		this->name = new char[this->length + 1];
		for (int i = 0; i <= this->length; i++)
		{
			this->name[i] = s.name[i];
		}
	}
	myString operator=(myString &s)//overloaded function for = operator
	{
		if (this->name != NULL)
		{
			delete(this->name);
		}
		this->length = s.length;
		this->name = new char[this->length + 1];
		for (int i = 0; i <= this->length; i++)
		{
			this->name[i] = s.name[i];
		}
		return *this;
	}
	myString operator+(myString &s)//oveloaded function for concatinating string
	{
		myString temp;
		temp.length = this->length + s.length;
		temp.name = new char[temp.length + 1];
		int i = 0, j = 0;//incrementers
		for (i = 0; this->name[i] != '\0'; i++)
			temp.name[i] = this->name[i];
		for (j = 0; s.name[j] != '\0'; j++)
		{
			temp.name[i] = s.name[j];
			i++;
		}
		temp.name[i] = '\0';
		cout << "the string after manipulating ti using (+) operator is:";
		cout << temp;
		return temp;
	}
	bool operator<(myString &s)//operator to check which of the string is greater used for sorting
	{
		return (strcmp(this->name,s.name));
	}
	friend istream& operator>>(istream& cin, myString &s);
	friend ostream& operator<<(ostream& cout, myString &s);//overloaded functions of cin and cout
	friend void SortObjects(myString *s, int length);
	~myString()//destructor
	{
		delete(name);//delete associated memory to avoid memory leak
		length = 0;
	}
};
istream& operator>>(istream& cin, myString &s)//overloaded cin function to read the object variables
{
	string temp;//variable to hold the string temporarily before pushing it into the class variable
	int length = 0, i = 0;
	cout << "enter the string: ";
	getline(cin, temp);//getline function to read the string using gets terminates when a space is entered
	if (cin.fail())//error handler
	{
		cout << "entered invalid input" << endl;
		flag = 1;
	}
	for (i = 0; temp[i] != '\0'; i++);//finding out the length of input string
	length = i;
	s.length = length;
	s.name = new char[s.length + 1];//allocating the necessary memory
	for (i = 0; i <= s.length; i++)
	{
		s.name[i] = temp[i];
	}
	return cin;
}

ostream& operator<<(ostream& cout, myString &s)//overloaded cout function to print the object variables
{
	cout << "the entered string is: " << s.name << endl;
	return cout;
}


//function to sort the array of objects takes the array and length as input and sorts the array objects
void SortObjects(myString *s,int length)
{
	int i = 0, j = 0;//incrementers
	bool swapped = 0;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length - i - 1; j++)
		{
			if ((s[j] < s[j+1])>=0)
			{
				myString temp;
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
				swapped = 1;
			}
			if (swapped == 0)
			{
				break;
			}
			swapped = 0;
		}
	}
	for (int k = 0; k < length; k++)
	{
		cout << s[k];
	}
	cout << endl << endl;
}


int main()
{
	const int arrSize = 5;
	int i = 0;
	myString s("hello");//object created using parameterised constructor
	cout << "object created using parameterised constructor: " << endl;
	cout << s << endl << endl;


	myString s1;//object created using default constructor
	cin >> s1;
	if (flag == 1)
	{
		flag = 0;
		return 0;
	}
	cout << s1 << endl << endl;//call to overloaded functions to read and print the string


	myString s2(s);//object created using copy constructor
	cout << "object created using copy constructor" << endl;
	cout << s2 << endl << endl;

	myString s3;
	s3 = s1;//calling overloaded function for assigning object variables
	cout << "the value of the string modified by overloading(=) operator is:" << endl;
	cout << s3 << endl << endl;

	s + s1;//call to overloaded function for concatinating the string objects
	cout << endl << endl;

	myString sa[arrSize];//array of string objects
	while (i != 5)
	{
		cout << "enter the " << i << "th string " << endl;
		cin >> sa[i];
		if (flag == 1)
		{
			flag = 0;
			return 0;
		}
		i++;
	}
	SortObjects(sa,arrSize);//call function for sorting string in objects
	cout << endl << endl;
	return 0;
}
//program to overload strings and its operators

#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class String {
	char * sptr;
	int len;
public:
	String()//constructor
	{
		sptr = NULL;
		len = 0;
	}
	String(string ptr)//parameterised constructor
	{
		int len = 0, i = 0;
		for (i = 0; ptr[i] != '\0'; i++);//find the length of entered string 
		len = i;
		sptr = new char[len + 1];//allocating necessary memory
		i = 0;
		while (ptr[i] != '\0')
		{
			sptr[i] = ptr[i];
			i++;
		}
		sptr[i] = '\0';
		this->len = len;
	}
	String(const String &s)//copy constructor for deep copying the string to avoid dangling reference
	{
		if (sptr != NULL)//deallocate the assigned memory and make the pointer free to avoid memory leak
		{
			delete(sptr);
		}
		sptr = new char[strlen(s.sptr) + 1];
		int i = 0;
		while (s.sptr[i] != '\0')
		{
			sptr[i] = s.sptr[i];
			i++;
		}
		sptr[i] = '\0';
		this->len = s.len;
	}
	~String()//destructor
	{
		delete(sptr);
		len = 0;
		cout << "destructed" << endl;
	}
	char operator[](int x)//overloaded function for []
	{
		return sptr[x];
	}


	void operator=(String &s)//overloading = operator
	{
		if (sptr != NULL)//deallocate the assigned memory and make the pointer free to avoid memory leak
		{
			delete(sptr);
		}
		sptr = new char[strlen(s.sptr) + 1];
		int i = 0;
		while (s.sptr[i] != '\0')
		{
			sptr[i] = s.sptr[i];
			i++;
		}
		sptr[i] = '\0';
		this->len = s.len;
	}
	void operator+(String &s)//overloading + operator
	{
		String s3;
		s3.len = len + s.len;
		s3.sptr = new char[s3.len + 1];
		int i = 0, j = 0;
		while (sptr[i] != '\0')
		{
			s3.sptr[i] = sptr[i];
			i++;
		}
		while (s.sptr[j] != '\0')
		{
			s3.sptr[i] = s.sptr[j];
			j++;
			i++;
		}
		s3.sptr[i] = '\0';
		cout << s3.sptr << endl;
	}
	friend istream& operator>>(istream& cin, String &s);//overloaded cin operator
	friend ostream& operator<<(ostream& cout, String &s);//overloaded cout operator
};


istream& operator>>(istream& cin, String &s)//overloaded cin function to take input and feed them into object variables
{
	cout << "enter the string :" << endl;
	string p;
	getline(cin, p);//get the input string with spaces using getline function using gets will terminate when space is entered
	if (s.sptr != NULL)
	{
		delete(s.sptr);//deallocate the memory of sptr if it is not null so rewriting it does not result in memory leak
	}
	int len = 0, i = 0;
	for (i = 0; p[i] != '\0'; i++);//find the length of entered string 
	len = i;
	s.sptr = new char[len + 1];//allocating necessary memory
	i = 0;
	while (p[i] != '\0')
	{
		s.sptr[i] = p[i];
		i++;
	}
	s.sptr[i] = '\0';
	s.len = len;
	return cin;
}




ostream& operator<<(ostream& cout, String &s)//overloaded cout function to display the members of objects
{
	cout << "the entered string is: ";
	cout << s.sptr << endl;
	return cout;
}

int main()
{
	//String s1;
	//cin >> s1;
	//cout << s1;//using overloaded cin and cout operators
	//String s2;
	//cin >> s2;
	//cout << s2;//using overloaded cin and cout operators
	//String s3(s1);//using copy constructor
	//cout << "using copy constructor function" << endl;
	//cout << s3;
	//String s4;
	//s4 = s1;//using overloaded = operator
	//cout << s4;
	//s2 + s1;
	//String s1,s2;
	//s2 = s1;
	const String s3("hello");
	String s4 = s3;
	String s5(s3);
	cout << s5;

	String s7("hai");
	String s8 = s7;
	return 0;
}
#include<iostream>
#include<string>

using namespace std;

class String {
	char * sptr;
	int len;
public:
	String()
	{
		sptr = NULL;
		len = 0;
	}
	String(char* ptr, int len)
	{
		sptr = new char[strlen(ptr)+1];
		strcpy_s(sptr, 100, ptr);
		this->len = len;
	}
	String(String &s)
	{
		if (sptr != NULL)
		{
			//delete(sptr);
		}
		else
		{
			sptr = new char[strlen(s.sptr)+1];
			strcpy_s(sptr, 100, s.sptr);
			this->len = s.len;
		}
	}
	~String()
	{
		//delete(sptr);
		len = 0;
		cout << "destructed" << endl;
	}
	friend istream& operator>>(istream& cin, String &s);
	friend ostream& operator<<(ostream& cout, String &s);
};

istream& operator>>(istream& cin, String &s)
{
	char p[100];
	cout << "enter the string: ";
	cin >> p;
	if (s.sptr != NULL)
	{
		//delete(s.sptr);
	}
	else
	{
		s.sptr = new char[strlen(p)+1];
		strcpy_s(s.sptr, 100, p);
		s.len = strlen(p);
		cout << s.len << endl;
	}
	return cin;
}

ostream& operator<<(ostream& cout, String &s)
{
	cout << "the entered string is: ";
	cout << s.sptr<<endl;
	cout << s.len<<endl;
	return cout;
}

int main()
{
	String s;
	cin >> s;
	cout << s;
	return 0;
}
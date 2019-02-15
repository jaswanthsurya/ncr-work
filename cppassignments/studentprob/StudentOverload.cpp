#include<iostream>
#include<string.h>
#include<string>

using namespace std;

class student {
	int rollno;
	char name[20];
	long int totalMarks;
	int marks[3];
	char grade;
public:
	friend void calTot(student s[], int n);
	friend istream& operator >> (istream &cin, student &s);
	friend ostream& operator << (ostream &cout, student &s);
};
ostream & operator <<(ostream &cout, student &s)
{
	cout << "roll no:" << s.rollno << endl;
	cout << "name: " << s.name << endl;
	for (int j = 0; j < 3; j++)
	{
		cout << "marks"<<j+1<<" :"<< s.marks[j]<<endl;
	}
	return cout;
}
istream & operator >>(istream &cin, student &s)
{
	int j = 0;
	cout << "enter student details: " << endl;
	cout << "roll no: ";
	cin >> s.rollno;
	cout << "enter name :";
	cin >> s.name;
	for (j = 0; j < 3; j++)
	{
		cout << "enter marks" << " " << j + 1 << ":";
		cin >> s.marks[j];
	}
	s.totalMarks = 0;
	return cin;
}
void calTot(student s[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << s[i];
		for (int j = 0; j < 3; j++)
		{
			s[i].totalMarks = s[i].totalMarks + s[i].marks[j];
		}
		if (s[i].totalMarks > 60)
		{
			s[i].grade = 'A';
			cout << "total marks: " << s[i].totalMarks << endl;
			cout << "grade :" << s[i].grade << endl;
		}
		else if (s[i].totalMarks > 40 && s[i].totalMarks < 60)
		{
			s[i].grade = 'B';
			cout << "total marks: " << s[i].totalMarks << endl;
			cout << "grade :" << s[i].grade << endl;
		}
		else
		{
			s[i].grade = 'C';
			cout << "total marks: " << s[i].totalMarks << endl;
			cout << "grade :" << s[i].grade << endl;
		}
	}
}
int main()
{
	const int n=3;
	int i = 0;
	student s[n];
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cout << "student details are -----------------------------------------------------------" << endl;
	calTot(s, 3);
	return 0;
}
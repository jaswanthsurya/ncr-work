#include<iostream>
#include<string.h>
using namespace std;
class student {
	int marks1;
	int marks2;
	int marks3;
	int average;
	char *name;
public:
	student()
	{

	}
	void set_Data(const char* s1, int m1, int m2, int m3)
	{
		int len1 = 0;
		len1 = strlen(s1);
		name = (char *)malloc(sizeof(char)*len1);
		strcpy_s(name,10, s1);
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
	}
	void calculateAverage()
	{
		average = marks1 + marks2 + marks3;
	}
	void calculateGrade()
	{
		if (average > 60)
		{
			cout << "first class" << endl;
		}
		else if (average > 50 && average < 60)
		{
			cout << "second class" << endl;
		}
		else
		{
			cout << "third class" << endl;
		}
	}
};

int main()
{
	student st;
	st.set_Data("hai", 50, 50, 50);
	st.calculateAverage();
	st.calculateGrade();
	return 0;
}
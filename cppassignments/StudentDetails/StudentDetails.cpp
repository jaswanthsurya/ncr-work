/*this program is to store the data of students and calculate the average and grade of the students*/

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
		marks1 = marks2 = marks3 = average = 0;
	}
	void set_Data(const char* s1, int m1, int m2, int m3)//set the data of the student details
	{
		int len1 = 0;
		len1 = strlen(s1);
		name = (char *)malloc(sizeof(char)*len1);//dynamically allocate memory for student name
		strcpy_s(name,10, s1);
		marks1 = m1;
		marks2 = m2;
		marks3 = m3;
	}
	void calculateAverage()//function to calculate average
	{
		average = marks1 + marks2 + marks3;
	}
	void calculateGrade()//function to calculate grade
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
	student st;//student object created by default constructor
	st.set_Data("hai", 50, 50, 50);
	st.calculateAverage();
	st.calculateGrade();
	return 0;
}
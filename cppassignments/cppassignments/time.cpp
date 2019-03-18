/*below program is to create class of type time which holds the seconds minutes and hours 
it consists of constructor and a destructor and a member function to display the time in
system format and a member function to add two time objects and generate the result
*/

#include<iostream>
using namespace std;
class time {
	int minutes;
	int seconds;
	int hours;
public:
	time()// default constructor initialised when object is created
	{
		hours = minutes = seconds = 0;
	}
	time(int h, int m, int s)//parameterised constructor 
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display()//display function
	{
		cout << hours << ':' << minutes << ':' << seconds << endl;
	}
	/*this function is to add two time objects and store the final result in the third time object*/
	void add(time &t1, time &t2)
	{
		int SecondsI=0, MinutesI=0;
		seconds = t1.seconds + t2.seconds;
		if (seconds>60)
		{
			SecondsI = 1;
			seconds = seconds-60;
		}
		minutes = t1.minutes + t2.minutes + SecondsI;
		if (minutes>60)
		{
			MinutesI = 1;
			minutes = minutes-60;
		}
		hours = t1.hours + t2.hours + MinutesI;
	}

};
int main()
{
	time t1;//object created using default constructor
	time t2(1, 30, 31);//objects created using parameterised constructor
	time t3(2, 31, 30);
	cout << "time for object t1 ";
	t1.display();
	cout << "time for object t2 ";
	t2.display();
	cout << "time for object t3 ";
	t3.display();
	t1.add(t2, t3);
	cout << "time after adding objects t2 and t3 ";
	t1.display();
	return 0;
}

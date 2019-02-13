#include<iostream>
using namespace std;
class time {
	int minutes;
	int seconds;
	int hours;
public:
	time()
	{
		hours = minutes = seconds = 0;
	}
	time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display()
	{
		cout << hours << ':' << minutes << ':' << seconds << endl;
	}
	void add(time &t1, time &t2)
	{
		int temp1=0, temp2=0;
		seconds = t1.seconds + t2.seconds;
		if (seconds>60)
		{
			temp1 = 1;
			seconds = seconds-60;
		}
		minutes = t1.minutes + t2.minutes + temp1;
		if (minutes>60)
		{
			temp2 = 1;
			minutes = minutes-60;
		}
		hours = t1.hours + t2.hours + temp2;
	}

};
int main()
{
	time t1;
	time t2(1, 30, 31);
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

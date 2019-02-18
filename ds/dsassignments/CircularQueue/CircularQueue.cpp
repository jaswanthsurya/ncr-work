#include<iostream>

using namespace std;

class queue {
	int * ptr;
	int rear;
	int front;
	int size;
	int count = 0;
public:
	queue()
	{
		ptr = NULL;
		rear = -1;
		front = -1;
		size = 0;
		count = 0;
	}
	void insert(int n);
	void del();
	bool underflow();
	bool overflow();
	void getsize(int n);
	void display();
	~queue()
	{
		delete(ptr);
	}
};
void queue::getsize(int n)
{
	ptr = new int[n];
	size = n;
}
void queue::insert(int n)
{
	if (!overflow())
	{
		rear = (rear + 1) % size;
		ptr[rear] = n;
		if (rear == 0 && count == 0)
		{
			front = (front + 1) % size;
		}
		count++;
	}
	else
	{
		cout << "queue is full" << endl;
	}
}
void queue::del()
{
	if (!underflow())
	{
		cout << "deleted element is: ";
		cout << (ptr[front]) << endl;
		front = (front + 1) % size;
		count--;
	}
	else
		cout << "queue is empty" << endl;
}
bool queue::underflow()
{
	return(count==0);
}
bool queue::overflow()
{
	return(count==size);
}
void queue::display()
{
	int i = 0;
	for (i = front; i !=rear; i=(i+1)%size)
	{
		cout << ptr[i] << " ";
	}
	cout << ptr[i];
	cout << endl;
}
int main()
{
	queue q1;
	int n = 0, x = 0, p = 0;
	cout << "enter size of queue : ";
	cin >> n;
	q1.getsize(n);
	while (1)
	{
		cout << "enter your choice : " << endl;
		cout << "1.insert" << endl << "2.delete" << endl << "3.display" << endl << "4.exit" << endl;
		cin >> x;
		switch (x)
		{
		case 1:cout << "enter element :";
			cin >> p;
			q1.insert(p);
			break;
		case 2:q1.del();
			break;
		case 3:q1.display();
			break;
		case 4:return 0;
		}
	}
}
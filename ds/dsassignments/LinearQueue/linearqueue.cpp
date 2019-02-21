#include<iostream>

using namespace std;

class queue {
	int * ptr;
	int rear;
	int front;
	int size;
public:
	queue()//default contructor to initialise the variables when object is created
	{
		ptr = NULL;
		rear = -1;
		front = -1;
		size = 0;
	}
	void insert(int n);
	void del();
	bool underflow();
	bool overflow();
	void getsize(int n);
	void display();
	~queue()//deallocate the assigned memory to avoid memory leak
	{
		delete(ptr);
	}
};
void queue::getsize(int n)//function to allocate the memory required
{
	ptr = new int[n];
	size = n;
}
void queue::insert(int n)
{
	if (!overflow())//checking for overflow condition to prevent index going out of bounds
	{
		ptr[++rear] = n;
		if (rear == 0)
		{
			front++;
		}
	}
	else
	{
		cout << "queue is full" << endl;
	}
}
void queue::del()
{
	if (!underflow())//checking for underflow condition to avoid index going out of bounds condition
	{
		cout << "deleted element is: ";
		cout << (ptr[front++]) << endl;
	}
	if (rear == front)//reinitialising the index pointers to -1 when the last element in queue is deleted
	{
		rear = front = -1;
	}
	else
		cout << "queue is empty" << endl;
}
bool queue::underflow()
{
	return(front==size);
}
bool queue::overflow()
{
	return(rear == size - 1);
}
void queue::display()
{
	for (int i = front; i <= rear; i++)
	{
		cout << ptr[i] << " ";
	}
	cout << endl;
}
int main()
{
	queue q1;
	int n = 0,x=0,p=0;
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
			break;
		default:cout << "enter correct choice" << endl;
		}
	}
}
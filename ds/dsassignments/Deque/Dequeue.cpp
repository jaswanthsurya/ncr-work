#include<iostream>

using namespace std;

class queue {
	int * ptr;
	int rear;
	int front;
	int size;
public:
	queue()
	{
		ptr = NULL;
		rear = -1;
		front = -1;
		size = 0;
	}
	void insertFirst(int n);
	void delFirst();
	void insertLast(int n);
	void delLast();
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
void queue::insertLast(int n)
{
	if (rear == -1 && front == -1)
	{
		front++;
	}
	if (!overflow())
	{
		ptr[++rear] = n;
	}
	else
	{
		cout << "queue is full" << endl;
	}
}
void queue::insertFirst(int n)
{
	if (front > 0)
	{
		if (rear == -1 && front == -1)
		{
			front++;
		}
		if (!overflow())
		{
			ptr[--front] = n;
		}
	}
	else
	{
		cout << "cannot insert at first" << endl;
	}
}
void queue::delFirst()
{
	if (!underflow())
	{
		if (rear == front)
		{
			cout << "deleted element is: ";
			cout << (ptr[front++]) << endl;
			rear = front = -1;
		}
		else
		{
			cout << "deleted element is: ";
			cout << (ptr[front++]) << endl;
		}
		
	}
	else
		cout << "queue is empty" << endl;
}
void queue::delLast()
{
	if (!underflow())
	{
		if (rear == front)
		{
			cout << "deleted element is: ";
			cout << (ptr[rear--]) << endl;
			rear = front = -1;
		}
		else
		{
			cout << "deleted element is: ";
			cout << (ptr[rear--]) << endl;
		}
		
	}
	else
		cout << "queue is empty" << endl;
}
bool queue::underflow()
{
	return(front == -1 && rear == -1);
}
bool queue::overflow()
{
	return(rear == size - 1 && front == 0);
}
void queue::display()
{
	cout << front << endl << rear << endl;
	for (int i = front; i <= rear; i++)
	{
		cout << ptr[i] << " ";
	}
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
		cout << "1.insert at first" << endl << "2.delete at first" << endl << "3.insert at last"<<endl<<"4.delete at last"<<endl<<"5.display" << endl << "6.exit" << endl;
		cin >> x;
		switch (x)
		{
		case 1:cout << "enter element :";
			cin >> p;
			q1.insertFirst(p);
			break;
		case 2:q1.delFirst();
			break;
		case 3:cout << "enter element :";
			cin >> p;
			q1.insertLast(p);
			break;
		case 4:q1.delLast();
			break;
		case 5:q1.display();
			break;
		case 6:return 0;
		}
	}
}
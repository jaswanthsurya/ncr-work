#include<iostream>

using namespace std;

class queue {
	int * ptr;
	int rear;
	int front;
	int size;
public:
	queue()//default constructor called using creation of object
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
	~queue()//deallocation of assigned memory
	{
		delete(ptr);
	}
};
void queue::getsize(int n)//function to assign the size to the mentioned value
{
	ptr = new int[n];
	size = n;
}
void queue::insertLast(int n)
{
	if (rear == -1 && front == -1)//front should be incremented initially during first insertion as it is assigned with -1
	{
		front++;
	}
	if (!overflow())//checking for overflow condition while inserting into queue to avoid index out of bounds case
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
	if (front > 0)//inserting at first can happen only if we have empty space at first
	{
		if (rear == -1 && front == -1)//front should be incremented initially during first insertion as it is assigned with -1
		{
			front++;
		}
		if (!overflow()) // checking for overflow condition while inserting into queue to avoid index out of bounds case
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
	if (!underflow())//checking for underflow to avoid index out of bounds case
	{
		if (rear == front)//when rear and front are pointing to same element it means there is only one element left so rear and front need to be initialised to originals
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
	if (!underflow())//checking for underflow to avoid index out of bounds case
	{
		if (rear == front)//when rear and front are pointing to same element it means there is only one element left so rear and front need to be initialised to originals
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
	for (int i = front; i <= rear; i++)//printing elements between rear and front
	{
		cout << ptr[i] << " ";
	}
	cout << endl;
}
int main()
{
	queue q1;
	int n = 0, x = 0, p = 0;
	cout << "enter size of queue in numbers : ";
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
			break;
		default:cout<<"enter correct choice to proceed";
		}
	}
}
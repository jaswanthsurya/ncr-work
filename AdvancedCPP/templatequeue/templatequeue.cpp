#include<iostream>

using namespace std;

template<class T>
class queue {
	int rear;
	int front;
	int size;
	T *ptr;//queue paramaters
public:
	queue()//constructor
	{
		rear = front = -1;
		ptr = NULL;
	}
	~queue()//destructor
	{
		delete(ptr);
		front = -1;
		rear = -1;
	}
	void getsize(int n);//function to allocate memory for the queue
	void insert(T ele);//insert element into queue
	T deleteele();//delete element from the queue
	void display();//display elements in the queue
};

template<class T>
void queue<T>::getsize(int n)//function to allocate memory for the queue
{
	ptr = new T[n];
	size = n;
}

template<class T>
void queue<T>::insert(T ele)//insert element into queue
{
	if (rear == size - 1)//if rear reaches the end
	{
		cout << "queue is full" << endl;
	}
	else
	{
		if (front == -1 && rear == -1)
		{
			ptr[++rear] = ele;
			front = rear;
		}
		else
		{
			ptr[++rear] = ele;
		}
	}
}

template<class T>
T queue<T>::deleteele()//delete element from the front in the queue
{
	T x;
	if (rear == front && rear != -1)
	{
		x = ptr[front];
		rear = front = -1;
	}
	else if (front == -1 && rear == -1)
	{
		cout << "empty queue" << endl;
		return -1;
	}
	else
	{
		x = ptr[front++];
	}
	return x;
}

template<class T>
void queue<T>::display()//display elements in the queue
{
	if (front == -1 && rear == -1)
	{
		cout << "empty queue" << endl;
	}
	else
	{
		for (int i = front; i <= rear; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << endl;
	}
}


#define type char //type can be int,float,double,char
int main()
{
	queue<type> qobj;
	cout << "enter size of queue :";
	int size;
	cin >> size;
	while (cin.fail())//check wether input is valid or not else iterate until correct input is entered
	{
		cin.clear();
		cin.ignore();
		cout << "entered invalid input please enter again to procees" << endl;
		cin >> size;
	}
	qobj.getsize(size);
	int choice = 0;
	type data;
	while (1)
	{
		cout << "enter your choice :" << endl;
		cout << "1.insert" << endl << "2.delete" << endl << "3.display" << endl << "4.exit" << endl;
		cin >> choice;
		while (cin.fail())//check wether input is valid or not else iterate until correct input is entered
		{
			cin.clear();
			cin.ignore();
			cout << "entered invalid input please enter again to procees" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1:cout << "enter data to insert :";
			cin >> data;
			while (cin.fail())//check wether input is valid or not else iterate until correct input is entered
			{
				cin.clear();
				cin.ignore();
				cout << "entered invalid input please enter again to procees" << endl;
				cin >> data;
			}
			qobj.insert(data);
			break;
		case 2:data = qobj.deleteele();
			if (data != -1)
			{
				cout << "the deleted element is : " << data << endl;
			}
			break;
		case 3:qobj.display();
			break;
		case 4:return 0;
			break;
		default:cout << "invalid choice" << endl;
		}
	}
}
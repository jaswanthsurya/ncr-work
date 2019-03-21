#include<iostream>

using namespace std;

struct node //structure for deque
{
	struct node *left;
	int data;
	struct node *right;
};

class Deque {
protected:
	struct node *start;
	struct node *rear;
	struct node *front;
public:
	Deque()//constructor
	{
		start = NULL;
		rear = NULL;
		front = NULL;
	}
	virtual ~Deque()//destructor
	{
		rear = NULL;
		front = NULL;
		struct node* temp = NULL;
		while (start != NULL)//delete nodes one by one
		{
			temp = start;
			start = start->right;
			delete(temp);
		}
		cout << "in parent" << endl;
	}
	void insertFront(int data);
	void insertRear(int data);
	int deleteFront();
	int deleteRear();
	void display();
};

void Deque::insertFront(int data)//insert at front of the queue
{
	struct node *temp = NULL;
	temp = new node;
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	if (start == NULL)//queue empty
		front = rear = start = temp;
	else
	{
		temp->right = start;
		start->left = temp;
		front = start = temp;
	}
}

void Deque::insertRear(int data)//insert at end of the queue
{
	struct node *temp = NULL;
	temp = new node;
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	if (start == NULL)//queue empty
		front = rear = start = temp;
	else
	{
		struct node *curr = start;
		while (curr->right != NULL)
			curr = curr->right;
		curr->right = temp;
		temp->left = curr;
		rear = temp;
	}
}

int Deque::deleteFront()//delete from front in the queue
{
	if (rear == front && front != NULL)
	{
		int retval = rear->data;
		delete(rear);
		rear = front = start = NULL;
		return(retval);
	}
	else if (front != NULL)
	{
		int retval = 0;
		retval = front->data;
		start = start->right;
		delete(front);
		front = start;
		return(retval);
	}
	else
	{
		return -1;
	}
}
int Deque::deleteRear()//delete from rear in the queue
{
	if (rear == front && rear != NULL)
	{
		int retval = rear->data;
		delete(rear);
		rear = front = start = NULL;
		return(retval);
	}
	else if (rear != NULL)
	{
		struct node*temp = rear;
		rear = rear->left;
		int retval = temp->data;
		delete(temp);
		return(retval);
	}
	else
	{
		return -1;
	}
}

void Deque::display()//display function
{
	struct node *temp = start;
	if (start != NULL)
	{
		while (temp != rear)
		{
			cout << temp->data << " ";
			temp = temp->right;
		}
		cout << rear->data;
	}
	else
	{
		cout << "sorry no element to display" << endl;
	}
	cout << endl;
}


class Stack :public Deque {//stack class inheriting the deuque in public mode
	int top;
public:
	Stack() :Deque()//constructor to initialise both the parent and child class variables
	{
		top = -1;
	}
	void push(int ele)
	{
		insertRear(ele);
		top++;
	}
	int pop()
	{
		top--;
		return(deleteRear());
	}
	int peek()//retrive element from stack top without deleting it
	{
		struct node *temp = rear;
		return(temp->data);
	}
	virtual ~Stack()
	{
		top = -1;
		cout << "in stack" << endl;
	}
};



class queue :public Deque {//queue class inheriting dequeu in public mode of derivation
public:
	queue() : Deque()
	{

	}
	void insert(int ele)
	{
		insertRear(ele);
	}
	int deleteele()
	{
		return(deleteFront());
	}
	virtual ~queue()
	{
		cout << "in queue" << endl;
	}
};



int main()
{
	int choice = 0;
	int data = 0;
	int ds;
	cout << "enter the data structure u want to create: " << endl;
	cout << "1.double ended queue" << endl << "2.stack" << endl << "3.queue" << endl << "4.exit" << endl;
	cin >> ds;
	if (ds == 1 && sizeof(ds) == 4)//check if wether choice entered is correct and valid integer
	{
		Deque deobj;//parent class object
		while (1)
		{
			cout << "enter choice:" << endl;
			cout << "1.insert front" << endl << "2.insert rear" << endl << "3.delete front" << endl
				<< "4.delete rear" << endl << "5.display" << endl << "6.exit" << endl;
			cin >> choice;
			if (cin.fail())
			{
				cout << "invalid choice try again" << endl;
			}
			else
			{
				switch (choice)
				{
				case 1:cout << "enter data to insert: ";
					cin >> data;
					if (cin.fail())
					{
						cout << "invalid data try again" << endl;
					}
					else
						deobj.insertFront(data);
					break;
				case 2:cout << "enter data to insert: ";
					cin >> data;
					if (cin.fail())
					{
						cout << "invalid data try again" << endl;
					}
					else
						deobj.insertRear(data);
					break;
				case 3:
					data = deobj.deleteFront();
					if (data != -1)
						cout << "the deleted element is :" << data << endl;
					else
						cout << "empty deque" << endl;
					break;
				case 4:
					data = deobj.deleteRear();
					if (data != -1)
						cout << "the deleted element is :" << data << endl;
					else
						cout << "empty deque" << endl;
					break;
				case 5:deobj.display();
					break;
				case 6:return 0;
					break;
				default:cout << "invalid choice" << endl;
				}
			}
		}
	}
	
	else if (ds == 2 && sizeof(ds) == 4)
	{
		Stack sobj;//derived class object
		while (1)
		{
			cout << "enter choice:" << endl;
			cout << "1.push" << endl << "2.pop" << endl << "3.peek" << endl
				<< "4.display" << endl << "5.exit" << endl;
			cin >> choice;
			if (cin.fail())
			{
				cout << "invalid choice try again" << endl;
			}
			else
			{
				switch (choice)
				{
				case 1:cout << "enter data to insert: ";
					cin >> data;
					if (cin.fail())
					{
						cout << "invalid data try again" << endl;
					}
					else
						sobj.push(data);
					break;
				case 2:
					data = sobj.pop();
					if (data != -1)
						cout << "the deleted element is :" << data << endl;
					else
						cout << "empty stack" << endl;
					break;
				case 3:
					data = sobj.peek();
					if (data != -1)
						cout << "the top element is :" << data << endl;
					else
						cout << "empty stack" << endl;
					break;
				case 4:sobj.display();
					break;
				case 5:return 0;
					break;
				default:cout << "invalid choice" << endl;
				}
			}
		}
	}
	else if (ds == 3 && sizeof(ds) == 4)
	{
		queue qobj;
		while (1)
		{
			cout << "enter choice:" << endl;
			cout << "1.insert" << endl << "2.delete" << endl << "3.display" << endl
				<< "4.exit" << endl;
			cin >> choice;
			if (cin.fail())
			{
				cout << "invalid choice try again" << endl;
			}
			else
			{
				switch (choice)
				{
				case 1:cout << "enter data to insert: ";
					cin >> data;
					if (cin.fail())
					{
						cout << "invalid data try again" << endl;
					}
					else
						qobj.insert(data);
					break;
				case 2:
					data = qobj.deleteele();
					if (data != -1)
						cout << "the deleted element is :" << data << endl;
					else
						cout << "empty stack" << endl;
					break;
				case 3:qobj.display();
					break;
				case 4:return 0; 
					break;
				default:cout << "invalid choice" << endl;
				}
			}
		}
	}
	else
	{
		cout << "invalid" << endl;
	}
	return 0;
}
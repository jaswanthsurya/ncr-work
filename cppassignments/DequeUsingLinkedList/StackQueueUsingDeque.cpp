#include<iostream>

using namespace std;

struct node //structure for deque
{
	struct node *left;
	int data;
	struct node *right;
};

class Deque {
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
	~Deque()//destructor
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

void Deque::display()
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

int main()
{
	Deque deobj;
	int choice = 0;
	int data = 0;
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
	return 0;
}
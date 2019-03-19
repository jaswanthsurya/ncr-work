#include<iostream>

using namespace std;

struct node//structure of linked list
{
	int data;
	struct node *next;
};

class LinkedList
{
	struct node* start;
public:
	LinkedList()//default constructor
	{
		start = NULL;
	}
	~LinkedList()//destructor
	{
		struct node*temp = NULL;
		while (start != NULL)
		{
			temp = start;
			start = start->next;
			delete(temp);
		}
	}
	void insertAtPos(int data, int pos);//inserting at position
	void insertFront(int data);//inserting at front
	void deleteNodeWithval(int data);//deleting node with given value
	void displayFor();//display elements in forward direction
	void reverseList();//reversing the linked list//wrapper function
	void display(struct node*temp);
	void displayRev();//display the linked list in reverse order
};
void LinkedList::insertAtPos(int data, int pos)//function to insert node at given position
{
	struct node* temp = NULL, *temp1 = start;
	temp = new node;
	temp->data = data;
	temp->next = NULL;
	int i = 1;
	if (start == NULL)//if list is empty
	{
		start = temp;
	}
	else
	{
		while (i++ != pos)
		{
			if (temp1 == NULL)//is given position is out of bounds
			{
				cout << "entered position is invalid" << endl;
				break;
			}
			temp1 = temp1->next;
		}
		if (temp1 != NULL)
		{
			temp->next = temp1->next;
			temp1->next = temp;
		}
	}
}
void LinkedList::insertFront(int data)//function to insert at front in the linked list
{
	struct node* temp = NULL;
	temp = new node;
	temp->data = data;
	temp->next = NULL;
	if (start == NULL)//if linked list is empty
	{
		start = temp;
	}
	else
	{
		temp->next = start;
		start = temp;
	}
}

void LinkedList::deleteNodeWithval(int data)//deleting the given node with value
{
	struct node *temp = start, *temp1 = start;
	if (start->data == data)//if start has the given data
	{
		start = start->next;
		cout << "deleted element : " << temp->data << endl;
		delete(temp);
	}
	else
	{
		while (temp->data != data)
		{
			if (temp->next == NULL)//it means linked list does not contain the given data
			{
				cout << "entered data not found" << endl;
				temp = temp->next;
				break;
			}
			temp = temp->next;
		}
		if (temp != NULL)
		{
			while (temp1->next != temp)
				temp1 = temp1->next;
			temp1->next = temp->next;
			cout << "deleted element : " << temp->data << endl;
			delete(temp);
		}
	}
}

void LinkedList::displayFor()//function to display elements of the list
{
	struct node* temp = start;
	while (temp!= NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void LinkedList::reverseList()//function to reverse the linked list
{
	struct node* temp1 = NULL, *temp = start;
	while (start != NULL)
	{
		if (temp1 == NULL)
		{
			temp1 = temp;
			start = start->next;
			temp1->next = NULL;
		}
		else
		{
			start = start->next;
			temp->next = temp1;
			temp1 = temp;
		}
		temp = start;
	}
	start = temp1;
	displayFor();
}

void LinkedList::displayRev()
{
	struct node*temp = start;
	display(temp);
	cout << endl;
}

void LinkedList::display(struct node*temp)
{
	if (temp == NULL)
	{
		return;
	}
	else
	{
		display(temp->next);
		cout << temp->data << " ";
	}
}

int main()
{
	LinkedList l;
	int choice = 0,pos=0,data=0;
	while (1)
	{
		cout << "enter your choice: " << endl;
		cout << "1.insert at pos" << endl << "2.insert at front" << endl << "3.delete node with val" << endl
			<< "4.display forward" << endl << "5.display reverse" << endl << "6.reverse linked list" << endl
			<< "7.exit" << endl;
		cin >> choice;
		if (cin.fail())
		{
			cout << "invalid choice" << endl;
			return 0;
		}
		switch (choice)
		{
		case 1:pos = 0, data = 0;
			cout << "enter position:";
			cin >> pos;
			if (cin.fail())//error handler
			{
				cout << "invalid position" << endl;
				return 0;
			}
			cout << "enter data: ";
			cin >> data;
			if (cin.fail())//error handler
			{
				cout << "invalid value" << endl;
				return 0;
			}
			l.insertAtPos(data, pos);
			break;
		case 2:cout << "enter data: ";
			cin >> data;
			if (cin.fail())//error handler
			{
				cout << "invalid value" << endl;
				return 0;
			}
			l.insertFront(data);
			break;
		case 3:data = 0;
			cout << "enter the value to be deleted :";
			cin >> data;
			if (cin.fail())//error handler
			{
				cout << "invalid value" << endl;
				return 0;
			}
			l.deleteNodeWithval(data);
			break;
		case 4:l.displayFor();
			break;
		case 6:l.reverseList();
			break;
		case 5:l.displayRev();
			break;
		case 7:return 0;
			break;
		default:cout << "invalid choice";
		}
		cout << endl << endl;
	}
	return 0;
}
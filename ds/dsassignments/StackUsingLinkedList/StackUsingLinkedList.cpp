#include<iostream>
#include<string>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

class list {
	struct node *start;
public:
	list()//default constructor to initialise varibles when an object is created
	{
		start = NULL;
	}
	void InsertAtFirst(int n);
	int DeleteAtFirst();
	void TravelForward();
	~list()//destructor to deallocate the assigned memory to avoid memory leak
	{
		struct node *temp;
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			delete(temp);
		}
	}
};
void list::InsertAtFirst(int n)//inserting elements at first since in stack operation elements are inserted at the top always
{
	struct node *temp;
	temp = new node;
	temp->data = n;
	temp->next = start;
	start = temp;
}



void list::TravelForward()//print the elemts in the stack
{
	struct node *temp;
	temp = start;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int list::DeleteAtFirst()//pop function to pop the top most element of the stack which is the first element in the linked list
{
	struct node *temp;
	int x = -1;
	if (start != NULL)
	{
		if (start->next == NULL)//case for deleting the last element
		{
			x = start->data;
			delete(start);
			start = NULL;
		}
		else//case when multiple elements are present
		{
			temp = start;
			start = temp->next;
			x = temp->data;
			delete(temp);
		}
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}

int main()
{
	list l;
	int n = 0, x = 0, d = 0, p = 0;
	while (1)
	{
		cout << "enter you choice:"<<endl;
		cout << "1.push" << endl << "2.pop" << endl << "3.display" << endl<<"0.exit"<<endl;
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:cout << "enter integer element: ";
			cin >> x;
			l.InsertAtFirst(x);
			break;
		case 2:d = l.DeleteAtFirst();
			if(d!=-1)
				cout << "deleted : " << d << endl;
			break;
		case 3:l.TravelForward();
			break;
		case 0:return 0;
			break;
		default:cout << "enter correct choice to proceed" << endl;
		}
		cout << endl;
		cout << endl;
	}
}
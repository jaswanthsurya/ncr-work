#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

class list {
	struct node *start;
public:
	list()
	{
		start = NULL;
	}
	void InsertAtLast(int n);
	int DeleteAtFirst();
	void TravelForward();
	~list()
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

void list::InsertAtLast(int n)
{
	struct node *temp, *curr;
	temp = new node;
	if (start == NULL)
	{
		temp->data = n;
		temp->next = NULL;
		start = temp;
	}
	else
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		temp->data = n;
		curr->next = temp;
		temp->next = NULL;
	}
}



int list::DeleteAtFirst()
{
	struct node *temp;
	int x = -1;
	if (start == NULL)
	{
		return -1;
	}
	else if (start->next == NULL)
	{
		x = start->data;
		delete(start);
		start = NULL;
	}
	else
	{
		temp = start;
		start = temp->next;
		x = temp->data;
		delete(temp);
	}
	return x;
}


void list::TravelForward()
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

int main()
{
	list l;
	int n = 0, x = 0, d = 0, p = 0;
	while (1)
	{
		cout << "1.enqueue" << endl << "2.dequeue" << endl << "3.display" << endl << "4.exit" << endl;
		cout << "enter your choice: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:cout << "enter element: ";
			cin >> d;
			l.InsertAtLast(d);
			break;
		case 2:p = l.DeleteAtFirst();
			if (p == -1)
				cout << "queue is empty" << endl;
			else
				cout << "deleted : " << p << endl;
			break;
		case 3:l.TravelForward();
			break;
		case 4:return 0;
		}
		cout << endl;
		cout << endl;
	}
}
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
	void TravelForward();
	void SelfAdjust(int n);
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

void list::SelfAdjust(int n)
{
	struct node *temp,*temp1;
	temp = start;
	temp1 = start;
	if (start->data == n)
	{
		return;
	}
	else
	{
		while (temp->data != n && temp!=NULL)
		{
			temp1 = temp;
			temp = temp->next;
		}
		if (temp != NULL)
		{
			temp1->next = temp->next;
			temp->next = start;
			start = temp;
		}
	}
}

int main()
{
	list l;
	int n = 0, x = 0, d = 0, p = 0;
	while (1)
	{
		cout << "1.insert" << endl << "2.display"<<endl<<"3.self adjust"<<endl<<"4.exit"<<endl;
		cout << "enter your choice: ";
		cin >> n;
		switch (n)
		{
		case 1:cout << "enter element to insert : ";
			cin >> d;
			l.InsertAtLast(d);
			break;
		case 2:l.TravelForward();
			break;
		case 3:cout << "enter data to be self adjusted : ";
			cin >> d;
			l.SelfAdjust(d);
			break;
		case 4:return 0;
		}
		cout << endl;
	}
}
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
	list()
	{
		start = NULL;
	}
	void InsertAtFirst(int n);
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
void list::InsertAtFirst(int n)
{
	struct node *temp;
	temp = new node;
	temp->data = n;
	temp->next = start;
	start = temp;
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

int list::DeleteAtFirst()
{
	struct node *temp;
	int x = -1;
	if (start->next == NULL)
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
		case 1:cout << "enter element: ";
			cin >> x;
			l.InsertAtFirst(x);
			break;
		case 2:d = l.DeleteAtFirst();
			cout << "deleted : " << d << endl;
			break;
		case 3:l.TravelForward();
			break;
		case 0:return 0;
		}
		cout << endl;
		cout << endl;
	}
}
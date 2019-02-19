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
	void InsertAtLast(int n);
	void InsertAtPos(int ele, int n);
	int DeleteAtFirst();
	int DeleteAtLast();
	int DeleteAtPos(int ele);
	void TravelForward();
	void TravelBackward();
	void Reverse();
	void recurr1(struct node *temp);
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

void list::InsertAtLast(int n)
{
	struct node *temp,*curr;
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

void list::InsertAtPos(int ele, int n)
{
	struct node *temp, *curr;
	temp = new node;
	if (start->data == ele)
	{
		temp->data = n;
		temp->next = start;
		start = temp;
	}
	else
	{
		curr = start;
		while (curr!=NULL&&curr->next->data != ele)
			curr = curr->next;
		if (curr != NULL)
		{
			temp->data = n;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
		{
			cout << "element not found"<<endl;
		}
	}
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

int list::DeleteAtLast()
{
	struct node *curr;
	int x = -1;
	if (start->next == NULL)
	{
		x = start->data;
		delete(start);
		start = NULL;
	}
	else
	{
		curr = start;
		while (curr->next->next!= NULL)
			curr = curr->next;
		x = curr->next->data;
		delete(curr->next);
		curr->next = NULL;
	}
	return x;
}

int list::DeleteAtPos(int ele)
{
	struct node *curr=NULL,*temp=NULL;
	int x = -1;
	if (start->data == ele)
	{
		x = start->data;
		curr = start;
		start = start->next;
		delete(curr);
	}
	else
	{
		while (curr != NULL && curr->next->data == ele)
			curr = curr->next;
		if (curr != NULL)
		{
			temp = curr->next;
			curr->next = curr->next->next;
			x = temp->data;
			delete(temp);
		}
		else
		{
			cout << "element not found" << endl;
		}
	}
	return x;
}

void list::TravelForward()
{
	struct node *temp;
	temp = start;
	while (temp != NULL)
	{
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << endl;
}

void list::TravelBackward()
{
	recurr1(start);
	cout << endl;
}

void list::recurr1(struct node *temp)
{
	if (temp == NULL)
		return;
	else
	{
		recurr1(temp->next);
		cout << temp->data<<" ";
	}
}

void list::Reverse()
{
	struct node *rev=NULL, *temp;
	if (start != NULL)
	{
		if (start->next != NULL)
		{
			while (start != NULL)
			{
				temp = start;
				start = temp->next;
				temp->next = rev;
				rev = temp;
			}
		}
	}
	start = rev;
}
int main()
{
	list l;
	int n = 0,x=0,d=0,p=0;
	while (1)
	{
		cout << "1.insert at beginning" << endl << "2.insert at last" << endl << "3.insert at element" << endl;
		cout << "4.delete at beginning" << endl << "5.delete at last" << endl << "6.delete at element" << endl;
		cout << "7.travel forward" << endl << "8.travel backward" << endl<<"9.reverse linked list"<<endl << "0.exit" << endl;
		cout << "enter your choice: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:cout << "enter element: ";
			cin >> x;
			l.InsertAtFirst(x);
			break;
		case 2:cout << "enter element: ";
			cin >> x;
			l.InsertAtLast(x);
			break;
		case 3:cout << "enter element: ";
			cin >> x;
			cout << "enter the element position";
			cin >> p;
			l.InsertAtPos(p,x);
			break;
		case 4:d = l.DeleteAtFirst();
			cout << "deleted : " << d << endl;;
			break;
		case 5:d = l.DeleteAtLast();
			cout << "deleted : " << d<<endl;
			break;
		case 6:cout << "enter the position to be deleted :";
			cin >> p;
			d = l.DeleteAtPos(p);
			cout << "deleted :" << d<<endl;
			break;
		case 7:l.TravelForward();
			break;
		case 8:l.TravelBackward();
			break;
		case 9:l.Reverse();
			break;
		case 0:return 0;
		}
		cout << endl;
		cout << endl;
	}
}
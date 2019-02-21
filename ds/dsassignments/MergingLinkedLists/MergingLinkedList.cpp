#include<iostream>
#include<string>

using namespace std;

struct node//structure for defining the linked list
{
	int data;
	struct node* next;
};

class list {
	struct node *start;
public:
	list()//default contructor
	{
		start = NULL;
	}
	void InsertAtLast(int n);
	void TravelForward();
	friend void merge(list &a, list &b,int x);
	~list()//parameterused constructor
	{
		struct node *temp;
		while (start != NULL)//deallocating the memory node by node starting from first to last
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
	temp = new node;//creating a new node
	if (start == NULL)//case when first insertion is done
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
	while (temp != NULL)//display the elements of linked list starting from first till last
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void merge(list &a, list &b, int x)
{
	struct node*temp, *temp1, *temp2 = NULL;//pointers to linked lists
	int i = 0, max = 0;
	temp = a.start;
	if (a.start != NULL)//if this is not used there would be an exception at run time as null is accessed for all pointers
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = b.start;
		temp = a.start;
		temp1 = a.start;
		b.start = NULL; //assigning list b to NULL and using it to store output
		for (i = 0; i < x; i++)
		{
			max = 0;
			temp = a.start;
			temp1 = a.start;//pointers to linked list a
			//finding out maximum element in the linked list
			while (temp != NULL)
			{
				if (temp->data > max)
				{
					max = temp->data;
				}
				temp = temp->next;
			}
			temp = a.start;
			while (temp->next != NULL && temp->data != max)//traversing temp until the maximum element is reached and temp1 to its previous node
			{
				temp1 = temp;
				temp = temp->next;
			}
			if (temp2 != NULL)//case where the output list has elements
			{
				if (temp == a.start)//case if the maximum element is at first
				{
					temp2->next = temp;
					temp2 = temp;
					a.start = temp->next;
					temp->next = NULL;
				}
				else if (temp->next == NULL)//case if ending element is the maximum element
				{
					temp2->next = temp;
					temp2 = temp;
					temp->next = NULL;
					temp1->next = NULL;
				}
				else//case if the maximum element is in between
				{
					temp1->next = temp->next;
					temp2->next = temp;
					temp2 = temp;
					temp->next = NULL;
				}
			}
			else if (temp2 == NULL)//if output list does not have any elements
			{
				temp2 = b.start = temp;
				if (a.start == temp)//if the maximum element in the merged list is at the beginning
				{
					a.start = temp->next;
					temp2 = b.start = temp;
					temp2->next = NULL;
				}
				if (temp->next == NULL)//if the maximum element in the merged list is at end
				{
					temp1->next = NULL;
					temp2 = b.start = temp;
					temp2->next = NULL;
				}
				else//if the maximum element is in between in the merged list
				{
					temp1->next = temp->next;
					temp2 = b.start = temp;
					temp2->next = NULL;
				}
			}
		}
	}
	else
	{
	cout << "list is empty";
	}
}

int main()
{
	list l1,l2;
	int x = 0, n = 0, indicator = 0, count = 0;//indicator is to switch between loops and take inputs,count is to find number of elements entered
	while (indicator!=1)//accept the first list
	{
		cout << "1.insert" << endl << "2.display" <<endl<<"3.enter second list"<< endl;
		cout << "enter your choice: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:cout << "enter integer element: ";
			cin >> x;
			l1.InsertAtLast(x);
			count++;
			break;
		case 2:l1.TravelForward();
			break;
		case 3:indicator = 1;
			break;
		default:cout << "enter correct option" << endl;
		}
		cout << endl;
		cout << endl;
	}
	indicator = 0;
	while (indicator != 1)//accept the second list
	{
		cout << "1.insert" << endl << "2.display" << endl << "3.merge two lists" << endl;
		cout << "enter your choice: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:cout << "enter integer element: ";
			cin >> x;
			l2.InsertAtLast(x);
			count++;
			break;
		case 2:l2.TravelForward();
			break;
		case 3:merge(l1,l2,count);
			l2.TravelForward();
			indicator = 1;
			break;
		default:cout << "enter correct option" << endl;
		}
		cout << endl;
		cout << endl;
	}
	return 0;
}
#include<iostream>

using namespace std;

struct node
{
	int data;
	int pow;
	struct node *next;
};
class Poly
{
	struct node *start;
public:
	Poly()//default constructor called during object creation
	{
		start = NULL;
	}
	void insert(int n,int p);//number and power as arguments to insert into node created
	void display();
	friend void PolyAdd(Poly &p, Poly &p1);//function prototype for polynomial addition , friend function since it need to access object private variables
	~Poly()//destructor used to deallocate the assigned memory
	{
		struct node *temp;
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			//delete(temp);
		}
	}
};

void Poly::insert(int n, int p)
{
	struct node *temp, *curr;
	temp = new node;
	if (start == NULL)//case for inserting at last when there are no elements in the list
	{
		temp->data = n;
		temp->pow = p;
		temp->next = NULL;
		start = temp;
	}
	else
	{
		curr = start;
		while (curr->next != NULL)//move until current pointer reaches end of the list if any nodes present
			curr = curr->next;
		temp->data = n;
		temp->pow = p;
		curr->next = temp;
		temp->next = NULL;
	}
}


void Poly::display()
{
	cout << endl << endl;
	struct node *temp;
	temp = start;
	cout << "the added polynomial expression is" << endl << endl;
	while (temp != NULL)//traverse until last node and print the data and power in each node
	{
		if (temp->next != NULL)
		{
			cout << temp->data << "x" << temp->pow << "+";
		}
		else
		{
			cout << temp->data << "x" << temp->pow;
		}
		temp = temp->next;
	}
	cout << endl;
	cout << endl;
}

void PolyAdd(Poly &a, Poly &b)//function to add the two polynomials and store result in the first linked list
{
	struct node *apointer,*bpointer,*temppointer,*acurrpointer;
	apointer = a.start;
	bpointer = b.start;
	if (a.start != NULL && b.start != NULL)//proceed to add only if two lists consists of nodes
	{
		while (apointer != NULL && bpointer != NULL)//loop the instructions until any of the pointer reaches null
		{
			if (apointer->pow == bpointer->pow)//add the coefficients if both the powers are equal
			{
				apointer->data = apointer->data + bpointer->data;
				apointer = apointer->next;
				bpointer = bpointer->next;
			}
			else if (apointer->pow > bpointer->pow)//if the power of first list is greater move the pointer of first list to next position
			{
				apointer = apointer->next;
			}
			else//if the power of node in the second list is greater append the node in the first linked list
			{
				temppointer = bpointer;
				bpointer = bpointer->next;
				if (apointer == a.start)
				{
					temppointer->next = apointer;
					a.start = temppointer;
				}
				else
				{
					acurrpointer = a.start;
					while (acurrpointer->next != apointer)
					{
						acurrpointer = acurrpointer->next;
					}
					temppointer->next = apointer;
					acurrpointer->next = temppointer;
				}
			}
		}
		apointer = a.start;
		while (apointer->next != NULL)
		{
			apointer = apointer->next;
		}
		while (bpointer != NULL)
		{
			apointer->next = bpointer;
			bpointer = bpointer->next;
			apointer = apointer->next;
		}
		apointer->next = NULL;
	}
	else
	{
		cout << "either of the list is empty" << endl;
	}
}

int main()
{
	Poly p1, p2;
	int choice = 0, insert_val = 0, insert_pow=0;
	bool indicator = 0;//used to switch between expressions to take input from user
	while (indicator!=1)//loop to take the first expression from the user
	{
		cout << "1.insert" << endl << "2.display" << endl << "3.enter second expression" << endl;
		cout << "enter your choice: ";
		cin >> choice;
		switch (choice)//break the loop when 3 is entered by the user and switch to taking second expression
		{
		case 1:cout << "-------------enter expression in decreasing order of powers---------------------" << endl << endl << endl;
			cout << "enter the integer coefficient :";
			cin >> insert_val;
			cout << "enter the integer power :";
			cin >> insert_pow;
			p1.insert(insert_val,insert_pow);
			break;
		case 2:p1.display();
			break;
		case 3:indicator = 1;
			break;
		default:cout<<"enter correct option to proceed" << endl;
		}
		cout << endl;
		cout << endl;
	}
	indicator = 0;
	cout << endl << endl << "..............enter second expression options......................" << endl << endl;
	while (indicator != 1)//loop to take the second expression entering input 3 adds the two polynomials 
	{
		cout << "1.insert" << endl << "2.display" << endl << "3.Add two polynomials" << endl << "4.exit" << endl;
		cout << "enter your choice: ";
		cin >> choice;
		switch (choice)//entering 4 terminates the program and entering 3 adds the two polynomials
		{
		case 1:cout << "-------------enter expression in decreasing order of powers---------------------" << endl << endl << endl;
			cout << "enter the integer coefficient :";
			cin >> insert_val;
			cout << "enter the integer power : ";
			cin >> insert_pow;
			p2.insert(insert_val, insert_pow);
			break;
		case 2:p2.display();
			break;
		case 3:PolyAdd(p1, p2);
			p1.display();
			indicator = 1;
			break;
		case 4:return 0;
		default:cout << "enter correct option to proceed" << endl;
		}
		cout << endl;
		cout << endl;
	}
	return 0;
}
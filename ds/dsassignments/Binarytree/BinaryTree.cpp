#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};//structure for double linked list

void print(struct node*);
void print1(struct node*);
void print2(struct node*);
struct node* insertfun(int, struct node*);//function declarations

class tree
{
	struct node * start;
public:
	void insert(int n);
	void inorder();
	void preorder();
	void postorder();
	tree()
	{
		start = NULL;
	}
	~tree()
	{

	}
	friend struct node* insertfun(int ele, struct node *start);
	friend void print(struct node* temp);
	friend void print1(struct node* temp);
	friend void print2(struct node* temp);
};

void tree::insert(int n)
{
	insertfun(n, start);//call the insert function with start
}

struct node * insertfun(int ele, struct node * temp)
{
	if (temp == NULL)//if temp reaches null then insert the node and return its address
	{
		struct node *temp1 = new node;
		temp1->data = ele;
		temp1->right = NULL;
		temp1->left = NULL;
		temp = temp1;
	}
	else if (ele > temp->data)//if the value is greater than root then call insert function for right subtree
	{
		temp->right = insertfun(ele, temp->right);
	}
	else if (ele < temp->data)//if value is less than root then call insert function for left subtree
	{
		temp->left = insertfun(ele, temp->left);
	}
	return temp;
}

void tree::inorder()//print the nodes in the tree in the order left-root-right
{
	print(start);
}

void print(struct node*temp)
{
	if (temp != NULL)
	{
		print(temp->left);
		cout << temp->data;
		print(temp->right);
	}
}

void tree::preorder()//print nodes in order root-left-right
{
	print1(start);
}

void print1(struct node*temp)
{
	if (temp != NULL)
	{
		cout << temp->data;
		print1(temp->left);
		print1(temp->right);
	}
}

void tree::postorder()//print nodes inorder left-right-root
{
	print1(start);
}

void print2(struct node*temp)
{
	if (temp != NULL)
	{
		print2(temp->left);
		print2(temp->right);
		cout << temp->data;
	}
}


int main()
{
	tree obj;
	obj.insert(4);
	obj.insert(2);
	obj.insert(5);
	obj.inorder();
	return 0;
}
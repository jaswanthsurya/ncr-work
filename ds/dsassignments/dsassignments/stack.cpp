#include<iostream>

using namespace std;

struct stack
{
	int top;
	int *sptr;
	int size;
};

class Stack {
	stack s;
public:
	Stack()//default constructor to initialise variables
	{
		s.top = -1;
		s.sptr = NULL;
		s.size = 0;
	}
	void push(int n);
	int pop();
	int peek();
	bool isempty();
	bool isfull();
	void getsize(int n);
	void display();
	~Stack()//deallocating the assigned memory
	{
		delete(s.sptr);
	}
};

void Stack::push(int n)
{
	if (!isfull())//checking for overflow condition to avoid index going out of bounds
	{
		s.sptr[++s.top] = n;
	}
	else
	{
		cout << "stack is full" << endl;
	}
}
int Stack::pop()
{
	int x = -999;
	if (!isempty())//checking for underflow to avoid index going out of bounds
	{
		x = s.sptr[s.top--];
	}
	else
	{
		cout << "stack is empty"<<endl;
	}
	return x;
}
int Stack::peek()//function used to just get the top of stack without popping elements of stack
{
	int x=-999;
	if (!isempty())
	{
		x = s.sptr[s.top];
	}
	else
	{
		cout << "stack is empty"<<endl;
	}
	return x;
}
bool Stack::isempty()
{
	return(s.top == -1);
}
bool Stack::isfull()
{
	return(s.top == s.size - 1);
}
void Stack::getsize(int n)//initialising stack with size given
{
	s.sptr = new int[n];
	s.size = n;
}
void Stack::display()
{
	for (int i = 0; i <= s.top; i++)
	{
		cout << s.sptr[i]<<" ";
	}
	cout << endl;
}


int main()
{
	Stack s1;
	int n = 0,x=0,x1=0;
	cout << "enter size of stack : ";
	cin >> n;
	s1.getsize(n);
	while (1)
	{
		cout << "enter options : " << endl;
		cout << "1.push" << endl;
		cout << "2.pop" << endl;
		cout << "3.peek" << endl;
		cout << "4.display" << endl;
		cout << "5.exit" << endl;
		cin >> x;
		switch (x)
		{
		case 1:cout << "enter integer number :";
			cin >> x1;
			s1.push(x1);
			break;
		case 2:x1 = s1.pop();
			cout << "the popped element is: " << x1<<endl;
			break;
		case 3:x1 = s1.peek();
			cout << "the top element is: " << x1<<endl;
			break;
		case 4:s1.display();
			break;
		case 5:return 0;
			break;
		default:cout << "enter the correct choice";
		}
	}
}
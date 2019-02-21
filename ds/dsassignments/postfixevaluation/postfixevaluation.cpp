#include<iostream>
#include<string>

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
	Stack()//deafult constructor to initialise the variables when object is created
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
	int checktop();
	~Stack()//deallocating the assigned memory 
	{
		delete(s.sptr);
	}
};

void Stack::push(int n)//pushing elements into stack and checking overflow condition is met to avoid index going out of bounds
{
	if (!isfull())
	{
		s.sptr[++s.top] = n;
	}
	else
	{
		cout << "stack is full" << endl;
	}
}
int Stack::pop()//popping elements from stack and checking for underflow condition to avoid index going out of bounds
{
	int x = -999;
	if (!isempty())
	{
		x = s.sptr[s.top--];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
int Stack::peek()//function to get the topmost element of stack without popping it
{
	int x = -999;
	if (!isempty())
	{
		x = s.sptr[s.top];
	}
	else
	{
		cout << "stack is empty" << endl;
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
void Stack::getsize(int n)//allocate the stack with given memory
{
	s.sptr = new int[n];
	s.size = n;
}
int Stack::checktop()
{
	if (s.top >= 1)
	{
		return 1;
	}
	return -1;
}
int main()
{
	string str;
	Stack s1;
	int x=0,count = 0,i=0;
	int b = 0, a = 0;
	cout << "enter postfix expression :";
	getline(cin, str);
	for (count = 0; str[count] != '\0'; count++);
	s1.getsize(count);
	for (i = 0; i < count; i++)
	{
		x = str[i] - '0';
		if (x >= 0 && x <= 9)//push the operands into stack 
		{
			s1.push(x);
		}
		else//when an operator is identified pop two elements from the stack and perform respective operation and push the result
		{
			switch (str[i])
			{
			case '*':
				if (s1.checktop())
				{
					a = s1.pop();
					b = s1.pop();
					s1.push(b*a);
					break;
				}
			case '/':
				if (s1.checktop())
				{
					a = s1.pop();
					b = s1.pop();
					s1.push(b / a);
					break;
				}
			case '+':if (s1.checktop())
			{
				a = s1.pop();
				b = s1.pop();
				s1.push(b + a);
				break;
			}
			case '-':
				if (s1.checktop())
				{
					a = s1.pop();
					b = s1.pop();
					s1.push(b - a);
					break;
				}
			}
		}
	}
	cout << s1.pop();
	return 0;
}
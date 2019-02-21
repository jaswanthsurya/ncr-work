#include<iostream>
#include<string>
using namespace std;

struct stack//structure to define all the variables in stack
{
	int top;
	char *sptr;
	int size;
};

class Stack {
	stack s;
public:
	Stack()//default constructor
	{
		s.top = -1;
		s.sptr = NULL;
		s.size = 0;
	}
	void push(char n);
	char pop();
	char peek();
	bool isempty();
	bool isfull();
	void getsize(int n);
	~Stack()//deallocating the assigned memory to avoid memory leak
	{
		delete(s.sptr);
	}
};

void Stack::push(char n)
{
	if (!isfull())//checking for overflow while pushing element into stack
	{
		s.sptr[++s.top] = n;
	}
	else
	{
		cout << "stack is full" << endl;
	}
}
char Stack::pop()
{
	char x = '0';
	if (!isempty())//check for underflow when popping elements 
	{
		x = s.sptr[s.top--];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
char Stack::peek()//function to just observe the top element of stack but not pop it
{
	char x = '0';
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
	return(s.top == -1);//underflow condition
}
bool Stack::isfull()
{
	return(s.top == s.size - 1);//overflow condition
}
void Stack::getsize(int n)
{
	s.sptr = new char[n];
	s.size = n;
}


int main()
{
	string str;
	Stack s1;
	int i = 0, count = 0;
	getline(cin, str);
	for (count = 0; str[count]!='\0'; count++);//finding the length of string
	s1.getsize(count);
	for (i = 0; i < count; i++)
	{
		switch (str[i])
		{
		case '[':
		case '{':
		case '(':s1.push(str[i]);
			break;
		case ']':
		case '}':
		case ')':
			if ((str[i] == ')'&& s1.peek() == '(')|| (str[i] == ']'&& s1.peek() == '[')|| (str[i] == '}'&& s1.peek() == '{')&&(!s1.isempty()))
			{
				s1.pop();
			}
			else
			{
				break;
			}
		}
	}
	if (s1.isempty())
	{
		cout << "balanced expression" << endl;
	}
	else
	{
		cout << "unbalnced expression" << endl;
	}
	return 0;
}
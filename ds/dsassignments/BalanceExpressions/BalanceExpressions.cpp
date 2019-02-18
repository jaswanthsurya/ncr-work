#include<iostream>
#include<string>
using namespace std;

struct stack
{
	int top;
	char *sptr;
	int size;
};

class Stack {
	stack s;
public:
	Stack()
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
	~Stack()
	{
		delete(s.sptr);
	}
};

void Stack::push(char n)
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
char Stack::pop()
{
	char x = '0';
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
char Stack::peek()
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
	return(s.top == -1);
}
bool Stack::isfull()
{
	return(s.top == s.size - 1);
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
	for (count = 0; str[count]!='\0'; count++);
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
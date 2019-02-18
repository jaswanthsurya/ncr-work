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
	Stack()
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
	~Stack()
	{
		delete(s.sptr);
	}
};

void Stack::push(int n)
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
int Stack::pop()
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
int Stack::peek()
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
void Stack::getsize(int n)
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
		if (x >= 0 && x <= 9)
		{
			s1.push(x);
		}
		else
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
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
	int checkprec(char c);
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
int Stack::checkprec(char c)
{
	int x = 0;
	if (!isempty())
	{
		switch (peek())
		{
		case '+':
		case '-':x = 4;
			break;
		case '*':
		case '/':x = 5;
			break;
		}
		switch (c)
		{
		case '+':
		case '-':x = 4-x;
			break;
		case '*':
		case '/':x = 5-x;
			break;
		}
	}
	return x;
}
int main()
{
	Stack s1;
	string str;
	char temp='a';
	char ostr[100];
	int i = 0,j=0,x=0, count = 0;
	getline(cin, str);
	for (count = 0; str[count] != '\0'; count++);
	s1.getsize(count);
	for (i = 0; i < count; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			ostr[j] = str[i];
			j++;
		}
		else
		{
			if (str[i] == '('||str[i]=='[')
			{
				s1.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
			{
				if (s1.checkprec(str[i]) > 0)
				{
					s1.push(str[i]);
				}
				else
				{
					while (s1.checkprec(str[i]) <= 0&&(!s1.isempty()))
					{
						ostr[j] = s1.pop();
						j++;
					}
					s1.push(str[i]);
				}
			}
			else if (str[i] == ')')
			{
				while (temp != '(')
				{
					temp = s1.pop();
					ostr[j] = temp;
					j++;
				}
				j--;
			}
			else if (str[i] == ']')
			{
				while (temp != '[')
				{
					temp = s1.pop();
					ostr[j] = temp;
					j++;
				}
				j--;
			}
		}
	}
	while (!s1.isempty())
	{
		ostr[j] = s1.pop();
		j++;
	}
	ostr[j] = '\0';
	j++;
	for (i = 0; i < j; i++)
	{
		cout << ostr[i];
	}
	return 0;
}
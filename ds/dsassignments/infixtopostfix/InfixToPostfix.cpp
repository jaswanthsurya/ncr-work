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
	Stack()//default constructor to initialise variables
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
	~Stack()//destructor to deallocate the assigned memory
	{
		delete(s.sptr);
	}
};

void Stack::push(char n)
{
	if (!isfull())//checking or overflow condition to avoid index going out of bounds
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
	if (!isempty())//checking or underflow condition to avoid index going out of bounds
	{
		x = s.sptr[s.top--];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
char Stack::peek()//function to get the top most element of stack without popping it
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
void Stack::getsize(int n)//initialise stack with given size and allocating memory
{
	s.sptr = new char[n];
	s.size = n;
}
int Stack::checkprec(char c)//function to retrive precedence value of elements in the stack to check for any violation that can happen
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
	for (count = 0; str[count] != '\0'; count++);//cal the length of the given expression
	s1.getsize(count);
	for (i = 0; i < count; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')//append the character value to output string if the character in input string is a alphabet
		{
			ostr[j] = str[i];
			j++;
		}
		else
		{
			if (str[i] == '('||str[i]=='[')//if an open paranthesis is encountered blindly push it 
			{
				s1.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')//when an operator is overcomed check for precedence and push and pop according to cases
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
			else if (str[i] == ')')//when a close paranthesis is encountered pop elements until open bracket is encountered
			{
				while (s1.peek() != '(')
				{
					temp = s1.pop();
					ostr[j] = temp;
					j++;
				}
				//j--;
			}
			else if (str[i] == ']')
			{
				while (s1.peek() != '[')
				{
					temp = s1.pop();
					ostr[j] = temp;
					j++;
				}
				//j--;
			}
		}
	}
	while (!s1.isempty())//popping out elements at the last if any
	{
		if (s1.peek() != '(')
		{
			ostr[j] = s1.pop();
			j++;
		}
		else
		{
			s1.pop();
		}
	}
	ostr[j] = '\0';//appending null character at the end 
	j++;
	for (i = 0; i < j; i++)
	{
		cout << ostr[i];
	}
	return 0;
}
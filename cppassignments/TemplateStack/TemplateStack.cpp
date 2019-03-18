/*program to implement template stack*/

#include<iostream>
#include<typeinfo>//to get the type of variable
using namespace std;

int flag = 0;
class complex
{
	int real;
	int img;
public:
	complex()//constructor
	{
		real = img = 0;
	}
	friend istream& operator>>(istream& cin, complex &c);//overloaded cin  operator as a friend function
	friend ostream& operator<<(ostream& cout, complex &c);//overloaded cout operator as a friend function
	~complex()//destructor
	{

	}
};

istream& operator>>(istream& cin, complex &c)//overloaded function for cin
{
	cout << "enter the real part: ";
	cin >> c.real;
	cout << "enter the imaginary part:";
	cin >> c.img;
	return cin;
}

ostream& operator<<(ostream& cout, complex &c)//overloaded function for cout
{
	cout << "the real part is:" << c.real << endl;
	cout << "the imaginary part is:" << c.img << endl;
	return cout;
}

template<class T>//template class
class stack
{
	T  *arr;//array depending on type of template used
	int size;
	int top = -1;
public:
	void getsize(int n)//function to initialise the stack
	{
		arr = new T[n];
		size = n;
	}
	void push(T n)//function to push element into stack
	{
		if (!isfull())
		{
			arr[++top] = n;
			cout << "pushed element: " << n << endl;
		}
		else
		{
			cout << "stack is full" << endl;
		}
	}
	T pop()//function to delete or pop element from the stack
	{
		T b;
		if (sizeof(b) == 4 || sizeof(b) == 8)//initialise variables
			b = 0;
		else if (sizeof(b) == 1)
			b = '0';
		if (!isempty())
		{
			return arr[top--];
		}
		else
		{
			cout << "stack is empty" << endl;
			flag = 1;
			return b;
		}
	}
	T peek()//function to just view top of stack
	{
		T b;
		if (sizeof(b) == 4||sizeof(b)==8)//initialise the variables
			b = 0;
		else if (sizeof(b) == 1)
			b = '0';
		if (!isempty())
		{
			return arr[top];
		}
		else
		{
			cout << "stack is empty" << endl;
			flag = 1;
			return b;
		}
	}
	void display()//display function
	{
		int i = 0;
		for (i = 0; i <= top; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}
	bool isfull()//conditional function returning wether stack is full or not
	{
		return(top == size-1);
	}
	bool isempty()//conditional function returning wether stack is empty or not
	{
		return(top == -1);
	}
};

# define type double //define either int,float,char,double,complex
int main()
{
	int size = 0,choice=0;
	stack <type>typestack;//template class definition
	type ele;
	cout << "using data type (" << typeid(type).name() << ") in stack so provide input accordingly" << endl;
	cout << "enter size of stack: ";
	cin >> size;
	if (sizeof(size) != 4 || size == 0)//input validation for checking wether correct size is mentioned
	{
		cout << "invalid size" << endl;
		return 0;
	}
	typestack.getsize(size);//initialise the stack with size provided
	while (1)
	{
		cout << "enter choice: " << endl << "1.push" << endl << "2.pop" << endl << "3.peek" << endl << "4.display"<<endl 
			<< "5.exit" << endl;
		cin >> choice;
		if (choice == 1 && sizeof(choice) == 4)//push element
		{
			cout << "enter the element to push :";
			cin >> ele;
			if (cin.fail())
			{
				cout << "provided wrong input" << endl;
				cout << "process terminated" << endl;
				return 0;
			}
			typestack.push(ele);
		}
		else if (choice == 2 && sizeof(choice) == 4)//pop element
		{
			ele = typestack.pop();
			if (!flag)
			{
				cout << "popped :" << ele << endl;
			}
			flag = 0;
		}
		else if (choice == 3 && sizeof(choice) == 4)//peek top element
		{
			ele = typestack.peek();
			if (!flag)
			{
				cout << "top element is :" << ele << endl;
			}
			flag = 0;
		}
		else if (choice == 4 && sizeof(choice) == 4)//display
		{
			typestack.display();
		}
		else if (choice == 5 && sizeof(choice) == 4)//exit
		{
			return 0;
		}
		else //exit if correct choice is not given
		{
			cout << "invalid input" << endl;
			cout << "enter correct choice" << endl;
			return 0;
		}
	}
}
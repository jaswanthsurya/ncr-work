#include<iostream>

using namespace std;

class exa {
	int a;
public:
	exa()
	{
		a = 0;
		cout << "in default contructor" << endl;
	}
	exa(int b)
	{
		a = b;
		cout << "in single parameterised constructor" << endl;
	}
	exa(exa &e1)
	{
		a = e1.a;
		cout << "in copy constructor" << endl;
	}
	exa(int a, int b)
	{
		this->a = a + b;
		cout << "in two parameterised constructor" << endl;
	}
	~exa()
	{
		cout << "in destructor" << endl;
	}
};

int main()
{
	exa e1;
	exa e2(2);
	exa e3(2, 3);
	exa e4(e2);
	return 0;
}
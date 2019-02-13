#include<iostream>
#include<string.h>

using namespace std;
class complexnum {
	int img;
	int real;
public:
	complexnum();
	complexnum(int n)
	{
		img = real = n;
	}
	complexnum(int n, int n1)
	{
		real = n;
		img = n1;
	}
	friend void complexadd(complexnum a, complexnum b);
	friend void complexmul(complexnum a, complexnum b);
};

void complexadd(complexnum a, complexnum b)
{
	cout << "upon adding two complex numbers :" << (a.real + b.real) <<"+i"<< (b.img + a.img) << endl;
}
void complexmul(complexnum a, complexnum b)
{
	cout << "upon multiplying two complex number :" << ((a.real * b.real) - (a.img * b.img)) << "+i" << ((a.real * b.img) + (a.img * b.real)) << endl;
}
int main()
{
	complexnum a(1, 2), b(2, 3);
	complexadd(a, b);
	complexmul(a, b);
	return 0;
}
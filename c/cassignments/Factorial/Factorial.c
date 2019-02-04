//program to find factorial of given number

#include<stdio.h>
long int fact(long int);
int main()
{
	long int num=0,res=0;
	printf("enter the number : ");
	scanf_s("%ld", &num);
	res = fact(num);
	printf("factorial of %ld is : %ld", num, res);
}

long int fact(long int num)
{
	if (num == 0 || num == 1)
	{
		return 1;
	}
	else
	{
		return num * fact(num - 1);
	}
}
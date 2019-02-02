#include<stdio.h>
int main()
{
	long int num = 0,sum=0,temp=0;
	scanf_s("%ld", &num);
	while (num > 0)
	{
		temp = num % 10;
		sum = sum + temp;
		num = num / 10;
	}
	printf("%ld", sum);
}
//reversing the digits of number;


#include<stdio.h>
void reverseNum(int);
int main()
{
	int num = 0;
	printf("enter the number : ");
	scanf_s("%d", &num);
	reverseNum(num);
	return 0;
}
void reverseNum(int num)
{
	long int temp = 0,a=0;
	int k = 0, i = 0;
	while (num > 0)
	{
		temp = num % 10;
		num = num / 10;
		a = (a*10)+temp;
	}
	printf("%ld", a);
}
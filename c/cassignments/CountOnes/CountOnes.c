//count ones in an eight bit number

#include<stdio.h>
int main()
{
	int num = 0,num1=0, a = 0,count=0;
	printf("enter the number: ");
	scanf_s("%d", &num);
	num1 = num;
	while (num > 0)
	{
		a = num % 2;
		if (a)
		{
			count++;
		}
		num = num / 2;
	}
	printf("number of ones in %d are:  %d", num1, count);
}
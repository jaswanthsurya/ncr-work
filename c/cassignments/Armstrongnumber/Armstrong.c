//program to find wether a number is armstrong or not
//an armstrong number is that in which sum of cubes of
//each digit is equal to the number itself

#include<stdio.h>
void Armstrong(long int);
long int num1 = 0;
int main()
{
	printf("enter the number: ");
	scanf_s("%ld", &num1);
	Armstrong(num1);
	return 0;
}
void Armstrong(long int num)
{
	int temp;
	long int sum = 0;
	while (num > 0)
	{
		temp = num % 10;
		num = num / 10;
		sum = sum + (temp*temp*temp);
	}
	if (sum == num1)
	{
		printf("Armstrong number");
	}
	else
	{
		printf("not an Armstrong number");
	}
}
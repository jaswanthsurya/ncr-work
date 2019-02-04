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
	long int temp = 0;
	int a[100],k=0,i=0;
	while (num > 0)
	{
		temp = num % 10;
		num = num / 10;
		a[k] = temp;
		k++;
	}
	k--;
	i = k;
	while (k >= 0)
	{
		printf("%d", a[i-k]);
		k--;
	}
}
#include<stdio.h>
void IntToBin(int);
void IntToHex(int);
int main()
{
	int num = 0;
	printf("enter the number");
	scanf("%d", &num);
	IntToBin(num);
	printf("\n");
	IntToHex(num);
	return 0;
}
void IntToBin(int num)
{
	int temp,a[100],k=0;
	while (num > 0)
	{
		temp = num % 2;
		num = num / 2;
		a[k] = temp;
		k++;
	}
	k--;
	while (k >= 0)
	{
		printf("%d", a[k]);
		k--;
	}
}
void IntToHex(int num)
{
	printf("%x", num);
}
//program to invert bits from a position specified



#include<stdio.h>
void InvertPosOnwards(long int, int,int);
int main()
{
	long int n = 0;
	int p = 0, b = 0;
	printf("enter the number:");
	scanf("%d", &n);
	printf("enter the bit position:");
	scanf("%d", &p);
	printf("enter number of bits to be inverted:");
	scanf("%d", &b);
	InvertPosOnwards(n, p, b);
	return 0;
}
void InvertPosOnwards(long int n, int p, int b)
{
	long int temp=0;
	int a[100], k = 0,i=0;
	while (n > 0)
	{
		temp = n % 2;
		n = n / 2;
		if (k <= p || k>p + b)
		{
			a[k] = temp;
			k++;
		}
		else
		{
			if (temp ==0)
			{
				a[k] = 1;
			}
			else
			{
				a[k] = 0;
			}
			k++;
		}
	}
	printf("binary representation after inverting bits as per given inputs :");
	for (i = k; i >=0; i--)
	{
		printf("%d", a[i]);
	}
}
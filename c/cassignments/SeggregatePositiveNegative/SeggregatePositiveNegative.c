//seggregating positive and negative numbers

#include<stdio.h>
int main()
{
	int i=0,size = 0,j=0,k=0,temp=0;
	int a[100];
	printf("enter the size of array: ");
	scanf_s("%d", &size);
	printf("enter numbers");
	for (i = 0; i < size; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0, j = size-1; i < size&&j>=0; i++)
	{
		if (i >= j)
		{
			break;
		}
		if (a[i] < 0)
		{
			while (a[j] < 0)
			{
				j--;
			}
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			j--;
		}
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}

}
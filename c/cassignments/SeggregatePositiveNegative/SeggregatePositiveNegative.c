//seggregating positive and negative numbers

#include<stdio.h>
int main()
{
	int i=0,size = 0;
	int a[100];
	printf("enter the size of array: ");
	scanf_s("%d", &size);
	printf("enter numbers");
	for (i = 0; i < size; i++)
	{
		scanf_s("%d", a[i]);
	}
}
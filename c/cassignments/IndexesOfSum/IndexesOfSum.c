//indexes of an array at which the given sum can be found out
#include<stdio.h>
int main()
{
	int a[100], size = 0,m_sum=0,sum=0,i = 0,k=0;
	printf("enter the size of array: ");
	scanf_s("%d", &size);
	printf("\nenter the number : ");
	for (i = 0; i < size; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("\nenter the sum : ");
	scanf_s("%d", &m_sum);
	for (i = 0; i < size; i++)
	{
		sum = sum + a[i];
		if (sum > m_sum)
		{
			i = k;
			k++;
			sum = 0;
		}
		else if (sum == m_sum)
		{
			printf("starting index is: %d\n", k);
			printf("ending index is : %d", i);
			break;
		}
	}
	if (sum != m_sum)
	{
		printf("no sub array found");
	}
	return 0;
}
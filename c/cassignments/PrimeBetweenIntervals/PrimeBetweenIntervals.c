//program to find prime numbers between intervals

#include<stdio.h>
void prime(long int, long int);
int main()
{
	long int start_num = 0, end_num = 0;
	printf("enter start and end intervals : ");
	scanf_s("%ld", &start_num);
	scanf_s("%ld", &end_num);
	prime(start_num, end_num);
	return 0;
}

void prime(long int s_num, long int e_num)
{
	int i = 0,j=0,count=0;
	printf("the prime numbers between %ld and %ld are\n",s_num,e_num);
	for (i = s_num; i <= e_num; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i%j == 0)
			{
				count++;
			}
		}
		if (count == 2)
		{
			printf("%d\n", i);
		}
		count = 0;
	}
}
#include<stdio.h>
int main()
{
	long int a=1;
	long int i = 0, sum = 0, min = 65535, max = 0;
	double avg;
	while (a > 0)
	{
		scanf_s("%ld", &a);
		if (a < 0)
		{
			break;
		}
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
		sum = sum + a;
		i++;
	}
	avg = (sum/i);
	printf("number of positive values entered  : %ld \n minimum value : %ld \n maximum value: %ld \n average: %lf \n", i, min, max, avg);
	return 0;
}
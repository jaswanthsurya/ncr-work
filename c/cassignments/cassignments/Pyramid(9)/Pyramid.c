#include<stdio.h>
int main()
{
	int n = 0,t=0,i=0,j=0,flag=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		t = i;
		for (j = 1; j <= (2*n-1); j++)
		{
			if (j<(n -i+1) || j>(2*n-1)-(n-i))
			{
				printf(" ");
			}
			else
			{
				if (t > 1&&flag==0)
				{
					printf("%d", t);
					t = t - 1;
				}
				else
				{
					printf("%d", t);
					flag = 1;
					t = t + 1;
				}
			}
		}
		printf("\n");
		flag = 0;
	}
	return 0;
}
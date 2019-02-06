//program to rotate a number rightside by given number of bits


#include<stdio.h>
void rotate_right(long int, int);
int main()
{
	long int n = 0;
	int b = 0;
	printf("enter the number  :");
	scanf_s("%ld", &n);
	printf("enter numbers of bits to be shifted :");
	scanf_s("%d",&b);
	rotate_right(n, b);
	return 0;
}
void rotate_right(long int n, int b)
{
	long int res = 0;
	res = n >> b;
	printf("%ld rotated right by %d bits gives: %ld",n,b,res);
}
#include<stdio.h>
#include<conio.h>
void main() {
	int a, b, c,res1,res2,res3;
	a = 1; b = 2; c = 3;
	res1 = sum(a, b);
	res2 = sub(c, b);
	printf("%d\n", res1);
	printf("%d", res2);
	getch();
}
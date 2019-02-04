//calculator program using multiple files

#include<stdio.h>
int main()
{
	int a = 0, b = 0;
	char c;
	printf("enter expression  two operands and one operator  :  ");
	scanf_s("%d", &a);
	scanf_s("%c", &c);
	scanf_s("%d", &b);
	switch (c)
	{
	case '+':sum(a, b);
		break;
	case '-': sub(a, b);
		break;
	case '/':div(a, b);
		break;
	case '*':mul(a, b);
		break;
	default:printf("Invalid");
	}
	return 0;
}
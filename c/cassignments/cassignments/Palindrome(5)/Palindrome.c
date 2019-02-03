//program to find wether a number is palindrome or not


#include<stdio.h>
void PalindromeCheck(char[],int);
int main()
{
	char name[100];
	int count = 0, i = 0;
	printf("enter the number : ");
	gets(name);
	for (i = 0; name[i] != '\0'; i++)
	{
		count++;
	}
	PalindromeCheck(name, count);
}
	
void PalindromeCheck(char *name, int count)
{
	int i = 0, count1 = 0;
	for (i = 0; i < (count / 2); i++)
	{
		if (name[i] == name[count-1 - i])
		{
			count1++;
		}
		else
		{
			break;
		}
	}
	if (count1==(count/2))
	{
		printf("palindrome");
	}
	else
	{
		printf("not a palindrome");
	}
}
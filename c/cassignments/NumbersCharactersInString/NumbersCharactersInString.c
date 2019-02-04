//program to find number of alphabets,spaces and numbers in given sentence


#include<stdio.h>
int main()
{
	char str[80];
	int space = 0, characters = 0, numbers = 0,i=0;
	printf("enter the sentence :");
	gets(str);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			space++;
		}
		else
		{
			if ('0' <= str[i] <= '9')
			{
				numbers++;
			}
			else if ('A' <= str[i] <= 'z')
			{
				characters++;
			}
		}
	}
	printf(" number of spaces in the sentence :%d\n number of characters in the sentence: %d\n number of digits in sentence: %d\n", space, characters, numbers);
	return 0;
}
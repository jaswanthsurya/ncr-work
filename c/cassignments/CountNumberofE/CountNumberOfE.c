//count number of e's in an string array

#include<stdio.h>


int main()
{
	char *s[] = {"we will teach you how to",
		"move a mountain",
		"level a building",
		"erase the past",
		"make a million"};
	int len = 0,i=0,count=0;
	char *p = NULL;
	len = sizeof(s) / sizeof(char*);
	for (i = 0; i < len; i++)
	{
		p = s[i];
		while (*p != '\0')
		{
			if (*p == 'e')
			{
				count++;
			}
			p++;
		}
	}
	printf("number of e's are %d", count);
	return 0;
}
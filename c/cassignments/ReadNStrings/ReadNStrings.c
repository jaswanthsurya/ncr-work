//reading n number of strings
//using dynamic memory allocation

#include<stdio.h>
int main()
{
	int n = 0,len=0,i=0;
	char **p = NULL;
	char s[100];
	printf("enter number of strings: ");
	scanf_s("%d", &n);
	p = (char **)malloc(n*sizeof(char*));
	printf("enter the strings: \n");
	for (i = 0; i <=n; i++)
	{
		gets(s);
		len = strlen(s);
		p[i] = (char*)malloc(len*sizeof(char));
		strcpy(p[i], s);
	}
	for (i = 0; i <=n; i++)
	{
		printf("%s\n", (*(p+i)));
		printf("%d", i);
	}
}
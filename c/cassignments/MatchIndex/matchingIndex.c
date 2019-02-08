#include<stdio.h>
#include<string.h>
int any(char *s1, char *s2);
int main() {
	char s1[10], s2[10];
	gets(s1);
	gets(s2);
	printf("matching index is %d", any(s1, s2));
	getch();
	return 0;
}

int any(char *s1, char *s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len;
	if (len1 > len2)
		len = len2;
	else
		len = len1;
	for (int i = 0; i < len; i++)
		if (*(s1 + i) == *(s2 + i))
			return i;
	return 0;
}
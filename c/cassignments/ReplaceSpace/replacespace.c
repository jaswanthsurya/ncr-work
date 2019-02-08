#include<stdio.h>
#include<string.h>
int main() {
	char ch[20];
	int i,p;
	printf("Enter the string : ");
	gets(ch);
	for (i = 0; i < strlen(ch); i++) {
		p = ch[i];
		if (p == 32)
			ch[i] = '-';

	}
	printf("string after replaccing spaces with - is: ");
	printf("%s\n", ch);
}
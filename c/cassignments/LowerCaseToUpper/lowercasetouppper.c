#include<stdio.h>
#include<string.h>
int main() {
	char ch[100];
	int i, j;
	printf("Enter the string\n");
	gets(ch);
	for (i = 0; i < strlen(ch); i++) {
		j = ch[i];
		if (j >= 65 && j <= 90)
			ch[i] = ch[i] + 32;
		if (j >= 97 && j <= 122)
			ch[i] = ch[i] - 32;
	}
	printf("manipulated string: ");
	printf("%s\n", ch);
	return 0;
}
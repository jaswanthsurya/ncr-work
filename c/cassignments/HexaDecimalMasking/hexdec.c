#include<stdio.h>
#include<math.h>

void compliment()
{
	int temp=0,hex = 0,dec=0,i=0;
	long int comp = 0;
	printf("enter hexadecimal number\n");
	scanf_s("%x", &hex);
	dec = (int)hex;
	while (dec > 0)
	{
		temp = dec % 2;
		if (temp)
		{
			temp = 0;
		}
		else
		{
			temp = 1;
		}
		comp =comp + ((temp)*pow(10, i));
		dec = dec / 2;
		i++;
	}
	i = 0;
	while (comp > 0)
	{
		temp = comp % 10;
		dec = dec + (temp*pow(2, i));
		comp = comp / 10;
		i++;
	}
	printf("the complimented hexadecimal representation is : %x\n", dec);
}

void bitshifting()
{
	int hex = 0, dec = 0, i = 0,bitnum=0;
	printf("enter hexadecimal number\n");
	scanf_s("%x", &hex);
	dec = (int)hex;
	printf("enter the option\n");
	printf("1. Left shift\n2.right shift\n");
	scanf_s("%d", &i);
	printf("enter number of bits to be shifted\n");
	scanf_s("%d", &bitnum);
	if (i)
	{
		dec = dec << bitnum;
	}
	else
	{
		dec = dec >> bitnum;
	}
	printf("The updated hexadecimal number is: %x\n",dec);
}
void masking() {
	int temp = 0, hex = 0, dec = 0, i = 0,num,a=0;
	long int comp = 0;
	printf("enter hexadecimal number\n");
	scanf_s("%x", &hex);
	dec = (int)hex;
	printf("Enter masking bit position\n");
	scanf_s("%d", &num);
	printf("enter options\n");
	printf("1.and masking\n2.or masking\n");
	scanf_s("%d", &a);
	while (dec > 0)
	{
		i++;
		temp = dec % 2;
		if (i == num) {
			if (a==1)
			{
				temp = 0;
			}
			else
			{
				temp = 1;
			}
		}
		comp = comp + ((temp)*pow(10, i-1));
		dec = dec / 2;
	}
	
	printf("the masked binary representation is : %ld\n", comp);

}



int main() {
	int a;
	printf("Enter the options\n");
	printf("1. 1's Compliment\n");
	printf("2. Masking\n");
	printf("3. Bitshifting\n");
	printf("4. Exit\n");
		
	while (1) {
		printf("enter your option\n");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1: compliment();
			break;
		case 2:masking();
			break;
		case 3:bitshifting();
			break;
		case 4: return 0;
		}
	}
}
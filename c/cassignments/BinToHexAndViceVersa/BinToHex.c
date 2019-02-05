//program to convert binary to hexadecimal and vice versa


#include<stdio.h>
#include<math.h>
int main()
{
	long int hex = 0, d = 0, bin = 0;
	int c = 0, coun = 0;
	printf("enter the input: \n");
	printf("1.Binary to hexadecimal\n");
	printf("2.hexadecimal to binary\n");
	scanf_s("%d", &c);
	if (c == 1)
	{
		printf("enter binary number : ");
		scanf_s("%ld", &bin);
		while (bin > 0)
		{
			d = bin % 10;
			if (d > 1)
			{
				printf("invalid");
				goto x;
			}
			hex = hex + (d*pow(2, coun));
			bin = bin / 10;
			coun++;
		}
		printf("the hexadecimal representation  is : %x", hex);
	}
	else
	{
		printf("enter the hexadecimal number");
		scanf_s("%x", &hex);
		hex = (int)hex;
		while (hex > 0)
		{
			d = hex % 2;
			bin = bin + (d*pow(10, coun));
			hex = hex / 2;
			coun++;
		}
		printf("the binary representation  is :%ld", bin);
	}
	x:
	return 0;
}
//program to convert binary to decimal and viceversa

#include<stdio.h>
#include<math.h>
int main()
{
	long int dec = 0,d=0, bin = 0;
	int c = 0,coun=0;
	printf("enter the input: \n");
	printf("1.Binary to decimal\n");
	printf("2.decimal to binary\n");
	scanf_s("%d", &c);
	if (c==1)
	{
		printf("enter binary number : ");
		scanf_s("%ld", &bin);
		while (bin > 0)
		{
			d = bin % 10;
			if (d>1)
			{
				printf("invalid");
				goto x;
			}
			dec = dec + (d*pow(2, coun));
			bin = bin / 10;
			coun++;
		}
		printf("the decimal representation  is : %ld",  dec);
	}
	else
	{
		printf("enter decimal number :");
		scanf_s("%ld", &dec);
		while (dec > 0)
		{
			d = dec % 2;
			bin = bin + (d*pow(10, coun));
			dec = dec / 2;
			coun++;
		}
		printf("the binary representation  is :%ld",bin);
	}
	x:
	return 0;
}
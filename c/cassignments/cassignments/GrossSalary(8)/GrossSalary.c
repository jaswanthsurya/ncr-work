#include<stdio.h>
int main()
{
	double BaseSalary, HRA , DA ;
	scanf("%lf", &BaseSalary);
	if (BaseSalary <= 4000)
	{
		HRA = (BaseSalary * 10)/100;
		DA = (BaseSalary * 50)/100;
	}
	else if (4000 < BaseSalary <= 8000)
	{
		HRA = (BaseSalary *20)/100;
		DA = (BaseSalary * 60)/100;
	}
	else if (8000 < BaseSalary <= 12000)
	{
		HRA = (BaseSalary * 25)/100;
		DA = (BaseSalary * 70)/100;
	}
	else if (BaseSalary>12000)
	{
		HRA = (BaseSalary * 30)/100;
		DA = (BaseSalary * 80)/100;
	}
	printf("Gross salary is :%lf", (BaseSalary+HRA+DA));
	return 0;
}
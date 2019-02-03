//program to find simple interest and compound interest 
//simple interest doesnot change when computed yearly or quarterly
//compound interest changes



#include<stdio.h>
#include<math.h>
void SimpleInterest(int);
void CompoundInterest(int);
double Principal = 500000;
int time = 10,RateOfInterest=10;
int main()
{
	printf("principal amount : %lf\n",Principal);
	printf("time : %d\n",time);
	printf("rate of interest : %d\n",RateOfInterest);
	printf("---------simple interest--------\n");
	SimpleInterest(1);
	SimpleInterest(2);
	SimpleInterest(4);
	SimpleInterest(365);
	SimpleInterest(3650);
	printf("-------compound interest------\n");
	CompoundInterest(1);
	CompoundInterest(2);
	CompoundInterest(4);
	CompoundInterest(365);
	CompoundInterest(3650);
	return 0;
}
void SimpleInterest(int a)
{
	double interest = 0.0;
	interest = ((Principal*RateOfInterest*time)/100.0);
	printf("interest compounded for %d times an year    : %lf\nprincipal + interest    = %lf\n",a, interest,(Principal+interest));
}
void CompoundInterest(int a)
{
	double interest = 0.0, intResult = 0.0;
	intResult = (1 + (RateOfInterest / (a*100.00)));
	interest = Principal*(pow(intResult, (time*a)));
	printf("principal+interest compounded for %d times an year       : %lf\n", a, interest);
}
#pragma once
/*namespace function that performs addition and subtraction function on the obsolute values of the given variables*/
namespace addnamespace2
{
	int addobs(int a, int b)
	{
		if (a < 0)
			a = a * -1;
		if (b < 0)
			b = b * -1;
		return(a + b);
	}
	int subobs(int a, int b)
	{
		if (a < 0)
			a = a * -1;
		if (b < 0)
			b = b * -1;
		return(a - b);
	}
}
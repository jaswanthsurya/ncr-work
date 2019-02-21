

#include<iostream>

using namespace std;;

int main()
{
	int n = 0,i=0,j=0,temp=0,flag=0;
	int *a;
	cout << "enter size of array : ";
	cin >> n;
	a = new int[n];
	cout << "enter array elements: ";
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				flag = 1;//to optimize the code
			}
		}
		if (!flag)//when no swaps are performed it means the array is sorted and no need to perform additional loops
		{
			break;
		}
	}
	cout << "the sorted array is: ";
	for (i = 0; i < n; i++)
	{
		cout<< a[i]<<" ";
	}
	delete(a);
}
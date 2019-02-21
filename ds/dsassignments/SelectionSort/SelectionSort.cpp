#include<iostream>

using namespace std;;

int main()
{
	int n = 0, i = 0, j = 0,k=0,min=0, temp = 0;
	int *a;
	cout << "enter size of array : ";
	cin >> n;
	a = new int[n];
	cout << "enter array elements: ";
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n-1; i++)
	{
		min = a[i];
		for (j = i + 1; j < n-i; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				k = j;//k is a pointer pointing the array at the element that is minimum in the array
			}
		}
		temp = a[k];
		a[k] = a[i];
		a[i] = temp;
	}
	cout << "the sorted array is: ";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete(a);
}
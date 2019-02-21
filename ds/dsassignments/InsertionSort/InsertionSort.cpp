#include<iostream>

using namespace std;;

int main()
{
	int n = 0, i = 0, j = 0, temp = 0;
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
		j = i;
		temp = a[j + 1];
		while (temp < a[j] && j>=0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	cout << "the sorted array is: ";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete(a);
}
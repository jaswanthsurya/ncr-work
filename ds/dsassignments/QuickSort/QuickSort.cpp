#include<iostream>

using namespace std;

void quicksort(int arr[], int low, int high)
{
	int pivot,temp=0, i = 0, j = 0;//pivot element to perform partition of the array and perform quick sort on sub array
	pivot = arr[high]; // considering pivot as the last element
	i = low;
	j = high - 1;
	if (low >= high)//base condition for recurrsive call
	{
		return;
	}
	while (i <= j)//function to arrange elements that are greater and lesser than pivot to their right position 
	{
		if (arr[i] > pivot&&arr[j] < pivot)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
		else if (arr[i] < pivot&&arr[j] < pivot)
		{
			i++;
		}
		else if (arr[i] > pivot&&arr[j] > pivot)
		{
			j--;
		}
		else
		{
			i++;
			j--;
		}
	}
	temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;
	quicksort(arr, low, i - 1);
	quicksort(arr, i + 1, high);
}

int main()
{
	int size,*arr;
	cout << "enter size of array : ";
	cin >> size;
	arr = new int[size];//allocate array with size mentioned
	cout << "enter elements : " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	quicksort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		cout<< arr[i];
	}
	delete(arr);//delete allocated memory
	return 0;
}
/*this program is to define a template class for linear search algorithm*/

#include<iostream>
using namespace std;
template <class T>

bool linearSearch(T *arr, int size, T ele)//template function for finding element for datatypes int,float,double
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == ele)
		{
			return 1;
		}
	}
	return 0;
}

#define type float//type of array used for linear search
int main()
{
	type *a;//array pointer
	int size = 0;
	cout << "enter size of array: ";
	cin >> size;
	if (sizeof(size) != 4)
	{
		cout << "invalid input" << endl;
		return 0;
	}
	a = new type[size];//allocating dynamic memory
	cout << "enter " << size << " elements :" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	type ele;
	cout << "enter the element to search :";
	cin >> ele;
	bool res;
	res=linearSearch<type>(a, size, ele);
	if (res == 1)
	{
		cout << "element found" << endl;
	}
	else
	{
		cout << "element not found" << endl;
	}
	return 0;
}
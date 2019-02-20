using namespace std;
#include<iostream>
void merge(int a[], int low, int mid, int high) {
	int s1, i = 0, k = 0, s2, e1, e2, *t, te = 0;
	s1 = low;
	e1 = mid;
	s2 = mid + 1;
	e2 = high;
	t = new int[high + 1];
	while (s1 <= e1 && s2 <= e2) {
		if (a[s1] < a[s2]) {
			t[te] = a[s1]; te++;
			s1++;
		}
		else {
			t[te] = a[s2]; te++;
			s2++;
		}
	}
	while (s1 <= e1)
	{
		t[te] = a[s1];
		s1++; te++;
	}
	while (s2 <= e2)
	{
		t[te] = a[s2];
		s2++; te++;
	}
	k = 0;
	for (i = low; i <= high; i++)
	{
		a[i] = t[k];
		k++;
	}
}

void mergesort(int a[], int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}


int main() {
	int size, *a, c;
	cout << "Enter size of array: " << endl;
	cin >> size;
	a = new int[size];
	cout << "enter the elements" << endl;
	for (int i = 0; i < size; i++)
		cin >> a[i];
	mergesort(a, 0, size - 1);
	cout << "the sorted array is: " << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	return 0;
}
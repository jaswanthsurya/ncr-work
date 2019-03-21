#include<iostream>
/*namespaces should be included in the header files if they are to be used by writing them in seperate files*/
#include "namespace2.h"
#include "namespace1.h"
using namespace std;
using namespace addnamespace1;//using the user defined namespace
using namespace addnamespace2;//using the user defined namespace

int main()
{
	int addres1, addres2;
	int subres1, subres2;
	addres1 = add(2, 3);//call to the function in namespace one
	addres2 = addobs(-2, -3);//call to function in namespace two
	subres1 = sub(-4, -5);//call to the function in namespace one
	subres2 = subobs(-4, -5);//call to function in namespace two
	cout << "the addition and subtraction result from the first namespace is: " << addres1 << " " << subres1 << endl;
	cout << "the addition and subtraction result from the second namespace is: " << addres2 << " " << subres2 << endl;
	return 0;
}


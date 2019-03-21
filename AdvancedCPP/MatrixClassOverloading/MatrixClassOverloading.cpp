#include<iostream>

using namespace std;

class _Matrix_//function to create two dimensional matrix and perform overloading operations on the matrix
{
	int **ptr;
	int rows;
	int col;
public:
	_Matrix_()//default contructor
	{
		ptr = NULL;
		rows = 0;
		col = 0;
	}
	_Matrix_(int rows, int col)//parameterised constructor
	{
		this->rows = rows;
		this->col = col;
	}
	_Matrix_(const _Matrix_ &m)//copy constructor
	{
		this->rows = m.rows;
		this->col = m.col;
		ptr = new int*[rows];//allocate memory for int* pointer 
		for (int rowcounter = 0; rowcounter < col; rowcounter++)
		{
			ptr[rowcounter] = new int[col];//allocate int memory for each int* pointer
		}
		for (int rowcounter = 0; rowcounter < rows; rowcounter++)//assign the values of the object to the currrent object
		{
			for (int  colcounter = 0; colcounter < col; colcounter++)
			{
				ptr[rowcounter][colcounter] = m.ptr[rowcounter][colcounter];
			}
		}
	}
	~_Matrix_()//destructor
	{
		if (ptr != NULL)
		{
			rows--;
			while (rows != -1)
			{
				delete(ptr[rows]);
				rows--;
			}
			delete(ptr);
		}
	}
	void operator=(_Matrix_ &m)//function for overloading = operator
	{
		if (ptr != NULL)//deallocate the memory if already it is assigned
		{
			rows--;
			while (rows != -1)
			{
				delete(ptr[rows]);
				rows--;
			}
			delete(ptr);
		}
		this->rows = m.rows;
		this->col = m.col;
		ptr = new int*[rows];//allocate memory for int* pointer 
		for (int rowcounter = 0; rowcounter < col; rowcounter++)
		{
			ptr[rowcounter] = new int[col];//allocate int memory for each int* pointer
		}
		for (int rowcounter = 0; rowcounter < rows; rowcounter++)//assign the values of the object to the currrent object
		{
			for (int colcounter = 0; colcounter < col; colcounter++)
			{
				ptr[rowcounter][colcounter] = m.ptr[rowcounter][colcounter];
			}
		}
	}

	void operator+(_Matrix_ m)
	{
		if (rows == 0 && col == 0)
		{
			cout << "cannot add empty matrix with non empty matrix:" << endl;
		}
		else if (rows != m.rows&&col != m.col)
		{
			cout << "cannot add matrices of different dimensions" << endl;
		}
		else
		{
			for (int rowcounter = 0; rowcounter < rows; rowcounter++)//assign the values of the object to the currrent object
			{
				for (int colcounter = 0; colcounter < col; colcounter++)
				{
					ptr[rowcounter][colcounter] = ptr[rowcounter][colcounter] + m.ptr[rowcounter][colcounter];
				}
			}
		}
	}
	friend istream& operator>>(istream& cin, _Matrix_ &m);//overloaded fucntion for cin
	friend ostream& operator<<(ostream& cout, _Matrix_ &m);//overloaded function for cout
};

istream& operator>>(istream& cin, _Matrix_ &m)//overloaded function for cin
{
	if (m.rows == 0 && m.col == 0)
	{
		cout << "enter the number of rows of the matrix: ";
		cin >> m.rows;
		cout << "enter the number of coloumns of the matrix :";
		cin >> m.col;
	}
	m.ptr = new int*[m.rows];//allocate memory for int* pointer 
	for (int rowcounter = 0; rowcounter < m.col; rowcounter++)
	{
		m.ptr[rowcounter] = new int[m.col];//allocate int memory for each int* pointer
	}
	for (int rowcounter = 0; rowcounter < m.rows; rowcounter++)
	{
		cout << "enter the " << rowcounter << " th row elements" << endl;
		for (int colcounter = 0; colcounter < m.col; colcounter++)
		{
			cout << "enter element: ";
			cin >> m.ptr[rowcounter][colcounter];
		}

	}
	return cin;
}

ostream& operator<<(ostream& cout, _Matrix_ &m)//overloaded function for cout operator
{
	cout << "the elements of the matrix are: " << endl;
	for (int rowcounter = 0; rowcounter < m.rows; rowcounter++)
	{
		for (int colcounter = 0; colcounter < m.col; colcounter++)
		{
			cout << m.ptr[rowcounter][colcounter] << " ";
		}
		cout << endl;
	}
	return cout;
}
int main()
{
	int rows, col;
	cout << "enter the no of rows in the matrix" << endl;
	cin >> rows;
	cout << "enter the no of coloumns in the matrix" << endl;
	cin >> col;//get the dimensions of the matrix

	_Matrix_ m(rows,col);
	cin >> m;//call to overloaded function
	cout << m;//call to overloaded function

	_Matrix_ m1(m);//call to copy constructor
	cout << "object created using copy constructor:" << endl;
	cout << m1;

	_Matrix_ m2;//object created using default constructor
	cout << "object initialised using overloaded(=) operator" << endl;
	m2 = m;//call to overloaded (=) function 
	cout << m2;

	m2 + m;//call to overloaded (+) function
	cout << "call to overloaded (+) function" << endl;
	cout << m2;
	return 0;
}
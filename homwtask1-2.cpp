// homwtask1-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
class Array2D
{
public:
	Array2D(int r = 0, int c = 0)
	{
		rows = r;
		col = c;
		a = new int [rows*col];
		for (int i = 0; i < rows*col; i++)
		{
				*(a + i) = 0;
		}
	}
	~Array2D()
	{
		delete[] a;
		cout << "dying-----------";
	}
	Array2D(Array2D& other)
	{
		rows = other.rows;
		col = other.col;
		a =new int [rows*col];
		for (int i = 0; i < rows*col; i++)
		{
				*(a + i) = *(other.a + i);
		}
	}
	int getindexvalue(int i, int j)
	{
		return *(a + i + j * rows);
	}
	void setindexval(int i, int j, int val)
	{
		*(a + i + j * rows) = val;
	}
	void printarray()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << *(a + i + j * rows)<<" ";
			}
			cout << endl;
		}
	}
	int addressOfIndex(int i, int j, int  StartIndex)
	{
		return StartIndex + ( i + j * rows);
	}
	Array2D operator+(Array2D& other)
	{
		if (this->rows != other.rows || this->col != other.col)
		{
			cout << "arrays are not equal";
			return -1;
	    }
		Array2D arr(rows, col);
		for( int i = 0; i <rows* col; i++)
		{
				*(arr.a + i ) = *(a + i ) + *(other.a + i);

		}

	}
	void printSubArray(int r1, int r2, int c1, int c2)
	{
		if (r1 < 0 || r2 >= rows ||c1 < 0 || c2 >= col)
		{
			cout << "can't print beyond array size";
		}
		else
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j <= c2; j++)
				{

					cout<< *(a + i + j * rows)<<" ";
				}
				cout << endl;
			}

		}
	}
	void clear(int m, int n)
	{
		for (int i = m; i < n; i++)
		{
			for (int j = m; j < n; j++)
			{

				*(a + i + j * rows) = 0;
			}
		}
	}
	void display()
	{
		for (int i = 0; i < rows * col; i++)
		{
			cout << *(a + i);
		}
	}
private:
	int* a;
	int rows;
	int col;
};

int main()
{
	Array2D arra(3, 3);
	Array2D arra1(3, 3);
	arra.setindexval(0, 0, 1);
	arra.setindexval(0, 1, 2);
	arra.setindexval(0, 2, 3);
	arra.setindexval(1, 0, 4);
	arra.setindexval(1, 1, 5);
	arra.setindexval(1, 2, 6);
	arra.setindexval(2, 0, 7);
	arra.setindexval(2, 1, 8);
	arra.setindexval(2, 2, 9);
	arra.printarray();
	int val = 1;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			arra1.setindexval(i, j, val++);
		}
	}
	arra.printarray();
	arra.printSubArray(0, 1, 0, 1);
	arra.display();
	Array2D arra2(3, 3);
	arra2.printarray();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

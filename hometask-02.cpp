

#include <iostream>
#include<fstream>
using namespace std;
class Matrix
{
public:
	Matrix(int nr = 0, int nc = 0)
	{

			rows = nr;
			cols = nc;

			// Allocate memory
			data = new int* [rows];
			for (int i = 0; i < rows; ++i) {
				data[i] = new int[cols];
				for (int j = 0; j < cols; ++j) {
					data[i][j] = 0; // Initialize to 0
				}
			}

	}

	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete[] data;
		cout << "dying--------------";
	}
	Matrix& operator=(Matrix& other)
	{
		if (this == &other)
		{
			return *this;
		}
		rows = other.rows;
		cols = other.cols;
		for (int i = 0; i < cols; i++)
		{
			delete[] data[i];
		}
		delete[] data;
		data = new int* [rows];
		for (int i = 0; i < rows; ++i) {
			data[i] = new int[cols];
			for (int j = 0; j < cols; ++j) {
				data[i][j] = other.data[i][j]; 
			}
		}
		return *this;

	}
	void setvalue(int row, int col, int value)
	{
		this->data[row][col] = value;
	}
	int getvalue(int row, int col)
	{
		return this->data[row][col];
	}
	void display()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout<<data[i][j]<<" ";
			}
			cout << endl;
		}
	}
	int* operator[](int r)
	{
		return data[r];
	}
	void readFromFile(const string & filename)
	{
			ifstream fin(filename);
			if (!fin)
			{
				cout << "Error: File not found!" << endl; 
				exit(1); 
			}
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					fin >> data[i][j];
			    }
			}
			fin.close(); 
	}
	int getrows() { return rows; }
	int getcol() { return cols; }
private:
	int** data;
	int rows;
	int cols;
};
class SparseMatrix
{
public:
	SparseMatrix(int nonzero=0)
	{
		non_zero = nonzero;
		if (non_zero > 0)
		{
			s_Mat = new int* [non_zero];
		
			for (int i = 0; i < non_zero; i++)
			{
				s_Mat[i] = new int[col];
			}
		}
		else
		{
			s_Mat = nullptr;
		}
	}
	~SparseMatrix()
	{
		for (int i = 0; i < non_zero; i++)
		{
			delete[] s_Mat[i];
		}
		delete[] s_Mat;
		s_Mat = nullptr;
	}

	void readSparse(Matrix& m)
	{
		int r = m.getrows();
		int c = m.getcol();
		non_zero = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (m.getvalue(i, j) != 0)
				{
					non_zero++;
				}
			}
		}
		s_Mat = new int* [non_zero];
		{
			for (int i = 0; i < non_zero; i++)
			{
				s_Mat[i] = new int[col];
			}
		}
		int k = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int val = m.getvalue(i, j);
				if (val != 0)
				{
					s_Mat[k][0] = i;
					s_Mat[k][1] = j;
					s_Mat[k][2] = val;
					k++;
				}
			}
		}
	}
	//SparseMatrix ADDsparsematrix(SparseMatrix B);
   void display() const
		{
			cout << "Row  Col  Value" << endl;
			for (int i = 0; i < non_zero; i++) {
				cout << s_Mat[i][0] << "    "
					<< s_Mat[i][1] << "    "
					<< s_Mat[i][2] << endl;
			}
		}



private:
	int non_zero;
	const int col{ 3 };
	int** s_Mat;
};


int main()
{
	Matrix m(2, 2);
	m.setvalue(0, 0, 2);
	m.setvalue(0, 1, 0);
	m.setvalue(1, 1, 0);
	m.setvalue(1, 0, 7);
	m.display();
	SparseMatrix s(2);
	s.readSparse(m);
	s.display();
	cout << m[0][0] << endl;
	Matrix m1(3, 3);
	m1.readFromFile("TextFile1.txt");
	s.readSparse(m1);
	s.display();
}


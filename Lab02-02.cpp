/*#include<iostream>
using namespace std;
class NDarray
{
private:
	int* data;
	int* in;
	int d;
public:
	NDarray(int n = 0, int* arr=0)
	{
		d = n;
		int si=1;
		for (int i = 0; i < n; i++)
		{
			si *= arr[i];
			in[i] = arr[i];
		}
		data = new int[si];
	}
	int calculateIndex(int* ind)
	{   
		int inde=0;
		for (int i = 0; i < d-1; i++)
		{
			for (int j = i + 1; i < d; j++)
			{
				inde += ind[i] * in[j];
			}
		}
		inde += ind[d - 1];
		return *(data + inde);
	}
	void setValue(int *i,int v)
	{
		int i1;
		i1 = calculateIndex(i);
		data[i1] = v;
	}
	int getValue(int* other)
	{
		int i2;
		i2 = calculateIndex(other);
		return i2;
	}
};
int main()
{
	int dimsize[3] = { 5,3,10 };
	NDarray arr(3, dimsize);
	int indexset[3] = { 4,2,8 };
	cout << arr.calculateIndex(indexset) << endl;
	//arr.setValue(indexset, val);
	//cout << arr.getValue(indexset);
}*/
#include <iostream>
#include <math.h>
using namespace std;

class ndarray
{
	int* p;// pointer to the actual data (1D memory)
	int a;// number of dimensions
	int* dims;// array storing the size of each dimension

public:
	ndarray(int b, int* arr)
	{
		int c = 1;
		a = b;
		dims = new int[a];
		for (int i = 0; i < a; i++)
		{
			dims[i] = arr[i];
			c *= arr[i];
		}
		p = new int[c];
	}

	int calculateindex(int* ind)
	{
		int inde = 0;
		int multiplier = 1;
		for (int i = a-1; i >=0; i++)
		{
			inde += ind[i] * multiplier;
			multiplier *= p[i];
			
		}
		
		return  inde;
	}

	void setvalue(int* arr, int val)
	{
		int b = calculateindex(arr);
		p[b] = val;
	}

	int getvalue(int* arr)
	{
		int b = calculateindex(arr);
		return p[b];
	}
};

int main()
{
	int dimsize[3] = { 5, 3, 10 };
	ndarray arr(3, dimsize);
	int indexset[3] = { 4, 2, 8 };

	cout << arr.calculateindex(indexset) << "\n";

	int value = 24;
	arr.setvalue(indexset, value);
	cout << arr.getvalue(indexset) << "\n";
}
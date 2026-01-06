// piority queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Heap
{
private:
	int* data;
	int noofelements;
	int height;
public:
	Heap(int h)
	{
		height = h;
		noofelements = 0;
		data = new int [pow(2, height) - 1];
	}
	~Heap()
	{
		delete[] data;
	}
	void insert(int v)
	{
		if (noofelements < (pow(2, height) - 1))
		{
			data[noofelements] = v;
			noofelements++;
			int i = noofelements - 1;
			while (i != 0 && data[i] < data[(i - 1) / 2])
			{
				swap(data[i], data[(i - 1) / 2]);
				i = (i - 1) / 2;
			}
		}
	}
	void heapify_down(int i)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int largest = i;
		if (left < noofelements && data[left] < data[largest])
		{
			largest = left;
		}
		if (right < noofelements && data[right] < data[largest])
		{
			largest = right;
		}
		if (largest != i)
		{
			swap(data[i], data[largest]);
			heapify_down(largest);
		}
	}
	void heapify_up(int i)
	{
		while (i != 0 && data[i] < data[(i - 1) / 2])
		{
			swap(data[i], data[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}
	/*void heapify_up(int i)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int largest = i;
		if (left < noofelements && data[left] > data[largest])
		{
			largest = left;
		}
		if (right < noofelements && data[right] > data[largest])
		{
			largest = right;
		}
		if (min != 0)
		{
			swap(data[i], data[largest]);
			heapify_up(largest);
		}
	}*/
	void extract_min()
	{
		if (noofelements == 0) return;
		swap(data[0], data[noofelements - 1]);
		noofelements = noofelements - 1;
		heapify_down(0);
	}
	void remove(int i)
	{
		if (noofelements == 0 || i >= noofelements) return;
		swap(data[i], data[noofelements - 1]);
		noofelements = noofelements - 1;
		heapify_up(i);
		heapify_down(i);
	}
	void decrease(int key, int i)
	{
		data[i] = data[i] - key;
		heapify_up(i);
	}
	void build_minheap(int arr[], int n)
	{
		if (n > (pow(2, height) - 1))
		{
			cout << "given array is bigger than heap capacity" << endl;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			data[i] = arr[i];
		}
		noofelements = n;
		int start_index = (noofelements / 2) - 1;
		for (int i = start_index; i >= 0; --i)
		{
			heapify_down(i);
		}
	}
	void display()
	{
		if (noofelements != 0)
		{
			for (int i = 0; i < noofelements; i++)
			{
				cout << data[i] << " ";
			}
		}
	}
};
class Queue
{
private:
	Heap* PQ;
public:
	Queue()
	{
		PQ = nullptr;
	}
	Queue(int si)
	{
		PQ = new Heap(si);
	}
	~Queue()
	{
		delete PQ;
	}
	void enqueue(int d)
	{
		PQ->insert(d);
	}
	void dequeue()
	{
		PQ->extract_min();
	}
	void display()
	{
		PQ->display();
	}

};

int main() {
	// 1. Demonstrate Heap functionality with build_minheap
	cout << "--- Heap Test ---" << endl;
	Heap myHeap(4); // Height of 4 allows for (2^4)-1 = 15 elements
	int arr[] = { 20, 15, 30, 5, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Building heap from array: 20 15 30 5 10 40" << endl;
	myHeap.build_minheap(arr, n);

	cout << "Heap array (Level Order): ";
	myHeap.display(); // Should show the min at index 0
	cout << "\n\n";

	// 2. Demonstrate Priority Queue functionality
	cout << "--- Priority Queue Test ---" << endl;
	Queue myQueue(4);

	cout << "Enqueuing: 50, 20, 10, 40" << endl;
	myQueue.enqueue(50);
	myQueue.enqueue(20);
	myQueue.enqueue(10);
	myQueue.enqueue(40);

	cout << "Queue contents: ";
	myQueue.display();
	cout << endl;

	cout << "Dequeuing (should remove 10)..." << endl;
	myQueue.dequeue();

	cout << "Queue contents after dequeue: ";
	myQueue.display();
	cout << endl;

	// 3. Demonstrate decrease key
	cout << "\n--- Decrease Key Test ---" << endl;
	// Current state might be something like: 20 50 40
	// We decrease the value at index 1 (50) by 45, making it 5
	cout << "Decreasing value at index 1 by 45..." << endl;
	myHeap.decrease(45, 1);
	cout << "Heap after decrease and heapify-up: ";
	myHeap.display();
	cout << endl;

	return 0;
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

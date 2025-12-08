// hometask01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<array>
#include <cstdlib>  // Needed for rand()
#include <ctime>    // Needed for time()

using namespace std;
void allocateArray(int*** &arr, int n = 3)
{
    arr = new int** [n];
    for (int i = 0; i < n; i++)
    {
        *(arr+i) = new int* [n];
        for (int j = 0; j < n; j++)
        {
            *(*(arr+i)+j) = new int[n];
            for (int k = 0; k < n; k++)
            {
                *(*(*(arr + i) + j) +k) = 0;
            }
        }
    }
}
void initializeArray(int*** arr, int n = 3)
{
    for (int i = 0; i < n; i++){
    
        for (int j = 0; j < n; j++)
        {

            for (int k = 0; k < n; k++)
            {
                *(*(*(arr + i) + j) + k) = rand()%10;
            }
        }
    }
}
void printArray(int*** arr, int n = 3)
{

        for (int i = 0; i < n; i++) 
        {
            cout << "Layer" << i+1<<":" << endl;
            for (int j = 0; j < n; j++)
            {

                for (int k = 0; k < n; k++)
                {
                    cout << *(*(*(arr + i) + j) + k)<<"   ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

void deallocateArray(int*** arr, int n = 3)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delete[] * (*(arr + i) + j);
       }
    }
    delete[] arr;
    arr = nullptr;
    cout << "dying_______________";
}
int main()
{  
    int*** a=nullptr;
    int n = 3;
    allocateArray(a, 3);
    initializeArray(a, 3);
    printArray(a, 3);
   cout << "Hello World!\n";
   deallocateArray(a, n);
   return 0;
}


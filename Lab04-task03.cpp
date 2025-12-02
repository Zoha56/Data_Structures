// Lab04-task03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.cpp"
using namespace std;
struct pairs
{
    int tickets;
    int k;
};

int count(pairs* people,int si,int j)
{
    Queue<pairs> p(si);
    int c = 0;
    for (int i = 0; i < si; i++)
    {
        p.enqueue(people[i]);
    }
    while(!p.isEmpty())
    {  
        pairs d = p.dequeue();
        c++;
        d.tickets--;            
        if (d.k == j && d.tickets == 0)
        {
            return c;           // return total time
        }

        // if they still have tickets left, go back to end of the line
        if (d.tickets > 0)
        {
            p.enqueue(d);
        }
    }

    return c;
       
    }
   
 
int main()
{ 
    pairs arr[4] = { {3,0}, {5,1}, {3,2}, {7,3} };
    int c = count(arr,4,2);
    cout <<c <<endl;
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

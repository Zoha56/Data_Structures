// lab05-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
using namespace std;
int countsquare(int x,int y, int k)
{
  
    if (k < 1)
    {
        return 0;
    }
    int count = 0;
    if ((x >= (1024 - k) && x <= 1024 + k && y >= 1024 - k && y <=1024 + k))
    {
        count = 1;
    }
    if (k == 1)
    {
        return count;
    }
    else
    {
        count += countsquare(x - k, y - k, k / 2);
        count += countsquare(x + k, y - k, k / 2);
        count += countsquare(x - k, y + k, k / 2);
        count += countsquare(x + k, y + k, k / 2);


        return count;
    }
}
int main()
{
    
    int x = 113;
    int y = 941;
    int k = 500;
    cout << countsquare(x, y,k) << endl;
    cout<<countsquare(1024,1024,300)<<endl;
    cout << countsquare(100, 200, 300) << endl;
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

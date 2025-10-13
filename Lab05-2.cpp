// Lab05-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
bool isprime(int n)
{
    if (n == 2 || n == 3 || n == 5 || n == 7)//cause n is a single digit
        return true;
    else
        return false;
}
bool iseven(int n)
{
    if (n % 2 == 0)
        return true;
    else
        return false;
}
bool isgoodnumber(string& s, int index = 0)
{

    if (index == s.size())
    {
        return true;
    }
    if ((index % 2 == 0) && (!iseven(s[index] - '0')) || (index % 2 != 0) && (!isprime(s[index] - '0')))
    {
       return false;
    }
    else
    {
     return isgoodnumber(s, index + 1);

    }


}
int main()
{
    string digit_string[] = { "02468","23478","224365"};
    for (string digits : digit_string)
    {
        bool is_good = isgoodnumber(digits, 0);
        cout << "Digit string " << digits << " is " << ((is_good) ? "Good" : "Not Good") << endl;

    }
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

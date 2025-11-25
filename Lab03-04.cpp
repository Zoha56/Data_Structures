// Lab03-04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "Stack.cpp"
using namespace std;
void result(string s1, string s2)
{   
    int resultcapacity = s1.size() + s2.size();
    Stack<char> st1(s1.size());
    Stack<char> st2(s2.size());
    Stack<int> stre(resultcapacity);
    int carry = 0;
    for (int i = 0; i < s1.size(); i++)
    {
            st1.push(s1[i]);
    }
    for (int i = 0; i < s2.size(); i++)
    {
        st2.push(s2[i]);
    }
    while( !st1.isempty()||!st2.isempty())
    {
        int a = (!st1.isempty()) ? st1.pop() - '0' : 0;
        int b = (!st2.isempty()) ? st2.pop() - '0' : 0;
       
       int  sum= a + b+ carry;
        stre.push(sum%10);
  
            carry = sum / 10;

    }
    if (carry > 0)
        stre.push(carry);

   while(!stre.isempty())
   {
        cout << stre.pop();
    }

}

int main()
{
    string s1 = "529";
    string s2 = "3784";
        result(s1, s2);
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

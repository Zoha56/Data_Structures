// Lab03-02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "Stack.cpp"
using namespace std;
void isfromAnBn(string s)
{
    Stack<char> c(s.size());
    int ac = 0, bc = 0;
    for (int i = 0; i < s.size(); i++)
    {  
        if (s[i] == 'a')
        {
            ac++;
        }
        if (s[i] == 'b')
        {
            bc++;
        }
            c.push(s[i]);
    }
    if (ac == bc)
    {
        for (int j = 0; j < s.size(); j++)
        {
            char ch = c.pop();
            if (ch == 'a' && c.getStack() == 'b')
            {

                cout << "not order of a ^ " << ac << " b ^ " << bc << endl;
                exit(1);
            }
            else if (ch == 'b' && (c.getStack() == 'b' || c.getStack() == 'a'))
            {
                continue;
            }

        }
        cout << "order of a^" << ac << " b^" << bc << endl;
    }
    if (ac != bc)
    {
        cout << "not of same order "<< endl;
    }
   
}
//bool isfromAnBn(string s)
//{
//    Stack<char> c(s.size());
//
//    for (int j = 0; j < s.size(); j++)
//    {
//        char ch = s[j];
//        if (ch == 'a')
//        {
//            c.push(s[j]);
//        }
//        else if (ch == 'b')
//        {
//            if (c.isempty())
//                return false;
//            c.pop();
//        }
//
//    }
//    if (!c.isempty())
//        return false;
//    return true;
//
//
//
//}

int main()
{
    string s = "aaabbb";
    isfromAnBn(s);
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

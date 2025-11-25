// Lab03-01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "Stack.cpp"
using namespace std;
void palindrome(string s)
{   
    for (int i = 0; i < s.size(); i++)
    {  
 
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
               s[i]= tolower(s[i]);
            }
   
        
    }
    
    Stack<char> c(s.size());
   
    for (int i = 0; i < s.size(); i++)
    {  
        if (s[i] >= '1' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
        {
            c.push(s[i]);
        }
    }
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] >= '1' && s[j] <= '9' || s[j] >= 'A' && s[j] <= 'Z' || s[j] >= 'a' && s[j] <= 'z')
        {   
           
            if (s[j] == c.getStack())
            {
                c.pop();
            }
            else
            {
                cout << "not palindrome"<<endl;
                exit(1);
            }

        }
    }
    cout << "Palindrome"<<endl;
   
}

int main()
{
    string s = "Do geese see God?";
    palindrome(s);
    string s1;
    cin >> s1;
    palindrome(s1);
    return 0;
}

/*
 if (sizeof(s) % 2 == 0)
    {
        ssize = sizeof(s) % 2;
    }
   else
    {
        ssize = (sizeof(s) % 2) +1;
    }
Stack<char> c(ssize);
for (int i = 0; i < ssize; i++)
{
    c.push(s[i]);
}
// c.push(s[ssize])
for (int i = sizeof(s) - 1; i > ssize; i--)
{
    if (c.gettop() == s[i])
    {
        c.pop();
    }
    else
    {
        cout << "not a palindrome" << endl;
        exit(1);
    }

}
cout << "Palindrome";
*/
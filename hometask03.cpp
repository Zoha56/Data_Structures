
#include <iostream>
#include<string>
#include"Stack.cpp"
using namespace std;
void validbrackets(string s)
{   
    int cap = s.size();
    char c;
    Stack<char> b(cap);
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '(':
            b.push(s[i]);
            break;
        case '{':
            b.push(s[i]);
            break;
        case '[':
            b.push(s[i]);
            break;
        case ')':
            if (b.isempty())
            {
                cout << "invalid expression" << endl;
                exit(1);
            }
             c = b.pop();
            if (c == '(')
            {
                break;
            }
            else
            {
                cout << "invalid expression" << endl;
                exit(1);
            }
          
        case '}':
            if (b.isempty())
            {
                cout << "invalid expression" << endl;
                exit(1);
            }
             c = b.pop();
            if (c == '{')
            {
                break;
            }
            else
            {
                cout << "invalid expression" << endl;
                exit(1);
            }
        case ']':
            if (b.isempty())
            {
                cout << "invalid expression" << endl;
                exit(1);
            }
             c = b.pop();
            if (c == '[')
            {
                break;
            }
            else
            {
                cout << "invalid expression" << endl;
                exit(1);
            }
        default:
            continue;

       }
    }
    if (b.isempty())
    {
        cout << "valid expression" << endl;
    }
    else
    {
        cout << "invalid expression" << endl;
    }
}
bool isfromAnBn(string s)
{
    Stack<char> c(s.size());
    int ac = 0, bc = 0;
    if (s[0] == 'b')
    {
        return false;
    }
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
    }
    if (ac != bc)
    {
        return false;
    }
    int i = 0;
    if (ac == bc)
    {
        while (i < s.size() && s[i] == 'a')
        {
            c.push(s[i]);
            i++;
       }
        while (i < s.size() && s[i] == 'b')
        {
            if (c.isempty())
                return false;
            c.pop();
            i++;
        }
    }
    if (!c.isempty())
    {
        return false;
    }
    else
    {
        return true;
    }

}
bool isfromAsBt(string s)
{
    Stack<char> c(s.size());
    bool isb = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            if (isb)
            {
                return false;
            }
            c.push(s[i]);

        }
        else if (s[i] == 'b')
        {  
            isb=true;
            if (c.isempty())
            {
                return false;
            }
            c.pop();

        }
        else
        {
            return false;
        }
    }
    return true;
   

}
bool isfromAnBnCn(string s)
{
    Stack<char> c(s.size());
    int ac = 0, bc = 0,cc=0;
  
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
        if (s[i] == 'c')
        {
            cc++;
        }
    }
    if (ac == bc && ac == cc)
    {
            int i = 0;
            while (i < s.size() && s[i] == 'a')
            {
                c.push(s[i]);
                i++;
            }
            while (i < s.size() && s[i] == 'b')
            {
                if (c.isempty()) return false;
                c.pop();
                c.push(s[i]);
                i++;
            }
            while (i < s.size() && s[i] == 'c')
            {
                if (c.isempty()) return false;
                c.pop();
                i++;
            }
            return true;

    }
        if (ac != bc || ac != cc || bc != cc)
        {
            return false;
        }
    }

int main()
{ 
    string s = "(5+z";
    validbrackets(s);
    string s1 = "{(a+b)[c−d]}";
    validbrackets(s1);
    string s2 = "5+z";
    validbrackets(s2);
    string s3 = "aabbbaa";
    isfromAsBt(s3);
    string s4 = "abababa";
    bool b= isfromAsBt(s4);
    if (b == 1)
    {
        cout << s4 << "  of the order a^n b^n " << endl;
    }
    if (b == 0)
    {
        cout << s4 << " is not of the order a^n b^n " << endl;
    }

    return 0;
}


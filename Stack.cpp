#include <iostream>
#include<cstring>
#include<array>
using namespace std;
template<typename T>
class Stack
{
protected:
    T* data;
    int top;
    int capacity;
public:
    Stack(int c = 0)
    {
        capacity = c;
        top = 0;
        data = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = 0;
        }
    }
    Stack(Stack& ref)
    {
        capacity = ref.capacity;
        top = ref.top;
        data = new T[capacity];
        for (int i = 0; i < top; i++)
        {
            data[i] = ref.data[i];
        }
    }
    int getcapacity()
    {
        return capacity;
    }
    Stack operator=(const Stack& ref)
    {
        if (this != ref)
        {
            delete[] data;
            capacity = ref.capacity;
            top = ref.top;
            data = new T[capacity];
            for (int i = 0; i < top; i++)
            {
                data[i] = ref.data[i];
            }
        }
        return *this;
    }
    int gettop()
    {
        return top;
    }
    void setsize(int t)
    {
        if (t != capacity)
        {
            top = t;
        }
        else
            cout << "Stack is full";
    }
    Stack()//default
    {
        top = 0;
        capacity = 0;
    }
    bool isempty()
    {
        bool r = false;
        if (top == 0)
            r = true;
        return r;
    }
    bool isfull()
    {
        if (top == capacity)
        {
            return true;
        }
        return false;
    }
    T getStack()
    {
        if (!isempty())
        {
            return data[top - 1];
        }
        else
            throw string("empty");
    }
    void push(T v)
    {
        if (top < capacity)
        {
            data[top] = v;
            top++;
        }
        else
            throw string("Full");
    }
    T pop()
    {
        if (top != 0)
        {
            top--;
            return data[top];
        }
        else
            throw string("empty");
    }

};

/*int main0000()
{
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int tofind = 2;
   try
   {
       s.push(7);
        while (!s.isempty())
        {
            if (tofind == s.pop())
            {
                cout << "found " << endl;
                return 0;
            }

        }
        cout << "not found" << endl;
    }
   catch(string &ex)
   {
       cerr << "exception occured " << ex;
   }
    return 0;
}
*/
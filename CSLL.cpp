// CSLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(T d)
    {
        data = d;
        next = nullptr;
    }
    Node(T d, Node* p)
    {
        data = d;
        next = p;
    }
};
template<typename T>
class CSLL
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    CSLL()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertathead(T val)
    {
        Node<T>* newnode = new Node<T>(val);
        if (!head)
        {
            head = newnode;
            tail = newnode;
           newnode->next = newnode;
           
            return;
        }
        newnode->next = head;
        head = newnode;
        tail->next = newnode;
        
        

    }
    void inserattail(T val)
    {
        Node<T>* temp = new Node<T>(val);
        if (!head)
        {
            head = temp;
            temp->next = temp;
            tail = head;
            return;
        }
        tail->next = temp;
        tail = temp;
        temp->next = head;
    }
    void removeathead()
    {
        if (!head)
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node<T> *temp = head;
        head = temp->next;
        tail->next = head;
        delete temp;
    }
    void removeattail()
    {
        if (!head)
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node<T>* temp = tail;
        Node<T>* pre = head;
        while (pre->next != tail)
        {
            pre = pre->next;
        }
        tail = pre;
        tail->next = head;
        delete temp;
    }
    void dislay()
    {
        if (!head)
            return;
        Node<T>* temp = head;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != head);
    }
    int countnodes()
    {
        int count = 0;
        if (!head)
        {
            return count;
        }
        Node<T>* temp = head;
        do
        {
            count++;
            temp = temp->next;

        } while (temp != head);
        return count;
    }

};

int main()
{
    CSLL<int> c;
    c.insertathead(21);
    c.insertathead(30);
    c.inserattail(45);
    c.inserattail(12);
    c.removeathead();
    c.insertathead(0);
    c.insertathead(9);
    c.dislay();
    cout << c.countnodes() << endl;
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

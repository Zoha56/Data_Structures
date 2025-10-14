// LSLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
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
class LSLL
{

private:
    Node<T>  *head;

public:
    LSLL()
    {
        head = 0;
    }
    // Insertion functions
    void insertAtHead(T val)
    {   
            Node<T>* t=new Node<T>(val);
            t->next = head;
            head = t;
    }

    void insertAtTail(T val)
    {
        Node<T>* t = new Node<T>(val);
        if (!head)
        {
            head = t;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = t;
    }
    void insertBefore(T key, T val)
    {
        if (!head)
        {
            return;
        }
        if (head->data == key)
        {
            Node<T>* t = new Node<T>(val);
            t->next = head;
            head = t;
            return;
        }
        Node<T>* temp = head;
        Node<T>* pre = head;
        while (temp->next != nullptr)
        {
            if (temp->data == key)
            {
                Node<T>* t = new Node<T>(val);
                t->next = temp;
                pre->next = t;
                return;
            }
            pre = temp;
            temp = temp->next;

        }
        cout << "no value matches" << endl;
    }
    void insertAfter(T key, T val)
    {
        Node<T>* temp = head;
        if (head->data == key)//if key matches the head value
        {
            Node<T>* t = new Node<T>(val);
            t->next = head->next;
            head->next = t;
            return;
        }
        while (temp->next != nullptr)
        {
            if (temp->data == key)
            {
                Node<T>* t = new Node<T>(val);
                t->next = temp->next;
                temp->next = t;
                return;
            }

            temp = temp->next;
        }
        cout << "no value matches" << endl;
    }
    // Deletion functions
    void removeAtHead()
    {
        if (!head)//if list is empty
        {
            cout << "head is not pointing to any node"<<endl;
            return;
        }
        Node<T>* temp = head;
        head = temp->next;
        delete temp;
    }
    void removeAtTail()
    {
        if (!head)
        {
            cout << "head is not pointing to any node" << endl;
            return;
        }
        if (head->next == nullptr)//only one Node
        {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        Node<T>* pre = head;
        while (temp->next != nullptr)
        {   
            pre = temp;
            temp = temp->next;
        }
        pre->next = nullptr;
        delete temp;

    }
    void remove(T val)
    {
        if (!head)
        {
            cout << "head is not pointing to any node" << endl;
            return;
        }
        if (head->data == val)//if head value matches
        {   
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T>* temp = head;
        Node<T>* pre = head;
        while (temp->next != nullptr)
        {
            if (temp->data == val)
            {
                pre->next = temp->next;
                delete temp;
                return;
            }
            pre = temp;
            temp = temp->next;
        }
        cout << "no value matches" << endl;
    }
    void removeBefore(T val)
    {
        if (!head)
        {
            cout << "head is not pointing to any node" << endl;
            return;
        }
        if (head->data == val)//if head value matches
        {
            cout << "there id only one node in the list" << endl;
            return;
        }
        if (head->next->data == val)//if there are only two nodes
        {
            Node<T>* temp = head;
            head= temp->next;
            delete temp;
            return;
            
        }
      
        Node<T>* doublepre = head;
        Node<T>* pre = head->next;
        Node<T>* temp = pre->next;
       
        while (temp->next != nullptr)
        {   
            if (temp->data == val)
            {
               doublepre->next = pre->next;
                delete pre;
                return;
            }
            doublepre = pre;
            pre = temp;
            temp = temp->next;
        }
        cout << "no value matches" << endl;

    }

    void removeAfter(T val)
    {
        if (!head)
        {
            cout << "there is no node" << endl;
            return;
        }
        //if (head->data == val)//if there is only two nodes 
        //{   
        //    if (!head->next)
        //    {
        //        cout << "there is no node after key value to be delete" << endl;
        //        return;
        //    }
        //    Node<T> *temp = head->next;
        //    head->next = temp->next;
        //    delete temp;
        //    return;
        //}
        ////if (head->next && head->next->data == val)//if there is only two nodes and value matches second node;
        ////{
        ////    cout << "there is no node after key value to be delete" << endl;
        ////    return;
        ////}
        Node<T> *temp = head;
       /* Node<T> *after = temp->next;
        Node<T>* afterthat = after->next;*/
        while (temp != nullptr)
        {
            if (temp->data == val)
            {   
                if (temp->next == nullptr)
                {
                    cout << "there is no node after key value to be delete" << endl;
                         return;
                }
                Node<T>* after = temp->next;
                temp = after->next;
                delete after;
                return;
            }
            temp = temp->next;
        }
        cout << "no value matches" << endl;
    }
    // Utility functions

    int search(T key)
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
    void update(T key, T val)
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                temp->data = val;
                return;
            }
            temp = temp->next;
        }
        cout << "key not found to update" << endl;

    }
    int countNodes()
    {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display()
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }

    }
    ~LSLL()// Destructor
    {
        delete head;
    }
};

int main()
{
   
        LSLL<int> list;
        // Sample testing (You can add more)
        list.insertAtHead(10);
        list.insertAtTail(20);
        list.insertAtTail(30);
        list.insertAfter(20, 25);
        list.insertBefore(10, 5);
        list.display();
        list.remove(25);
        list.removeAtHead();
        list.removeAtTail();
        cout << "\nAfter deletions: ";
        list.display();
        list.update(20, 99);
        cout << "\nAfter update: ";
        list.display();
        if (list.search(99))
            cout << "\nElement 99 found!";
        else
            cout << "\nElement 99 not found!";
        cout << "\nTotal Nodes: " << list.countNodes();
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

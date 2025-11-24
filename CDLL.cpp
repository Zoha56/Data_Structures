// CDLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template<typename T>
class DNode
{
public:
    T data;
    DNode<T>* next;
    DNode<T>* pre;
    DNode()
    {
        next = nullptr;
        pre = nullptr;
    }
    DNode(T d)
    {
        data = d;
        next = nullptr;
        pre = nullptr;

    }
    DNode(T d, DNode* p)
    {
        data = d;
        next = p;
        pre = p;
    }
    DNode<T>* getnext()
    {
        return next;
    }

};
template<typename T>
class CDLL {
private:
    DNode<T>* head;
public:
    CDLL()
    {
        head = nullptr;
    }
    DNode<T>* gethead()
    {
        return head;
    }
    void insertathead(T value)
    {
        if (!head)
        {
            DNode<T>* temp = new DNode<T>(value);
            head = temp;
            head->pre = temp;
            head->next = temp;
            return;
        }
        DNode<T>* newnode = new DNode<T>(value);
        newnode->pre = head->pre;
        newnode->next = head;
        head->pre->next = newnode;
        head->pre = newnode;

        head = newnode;
    }
    void insertattail(T value)
    {
        if (!head)
        {
            DNode<T>* temp = new DNode<T>(value);
            head = temp;
            return;
        }

        DNode<T>* newnode = new DNode<T>(value);
        head->pre->next = newnode;
        newnode->pre = head->pre;

        head->pre = newnode;
        newnode->next = head;

    }
    void display()
    {
        if (!head)
        {
            cout << "list is empty" << endl;
            return;
        }
        DNode<T>* temp = head;
        while (temp->next != head)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << temp->data << endl<<"-----"<<endl;
    }
    void removeathead()
    {
        if (!head)
            return;
        if (head->next == head && head->pre == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        DNode<T>* temp = head;
        head->pre->next = head->next;
        head->next->pre = head->pre;
        head = head->next;
        delete temp;

    }
    void removeattail()
    {
        if (!head)
            return;
        if (head->next == head && head->pre == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        DNode<T>* tail = head->pre;
        head->pre = tail->pre;
        tail->pre->next = head;
        delete tail;

    }
    // void remove(T val)
    // {
    //     if (!head)
    //         return;
    //     if (head->data == val && head->pre == head && head->next == head)
    //     {
    //         delete head;
    //         head = nullptr;
    //         return;
    //     }
    //     if (head->data == val && head->next!=head)
    //     {
    //         DNode<T>* temp = head;
    //         head->pre->next = head->next;
    //         head->next->pre = head->pre;
    //         head = head->next;
    //         delete temp;
    //         return;
    //     }
    //     DNode<T>* tail= head->pre;
    //     if (tail->data == val)
    //     {
    //         tail->pre->next = head;
    //         head->pre = tail->pre;
    //         delete tail;
    //         return;
    //     }
    //     DNode<T>* temp = head->next;
    //     while (temp->next != head)
    //     {
    //         if (temp->data == val)
    //         {
    //             temp->next->pre = temp->pre;
    //             temp->pre->next = temp->next;
    //             delete temp;
    //             return;
    //         }
    //         temp = temp->next;
    //     }
    //    // delete temp;
    //     cout << "given value is not on the list "<<endl;
    //}
    void remove(T val)
    {
        if (!head)
            return;
        DNode<T>* temp = head;
        do
        {
            if (temp->data == val)
            {
                if (temp->next == head && temp->pre == head)
                {
                    delete temp;
                    head = nullptr;
                    return;
                }
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
                if (temp == head)
                {
                    head = head->next;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp!= head);
        cout << "value not in the list" << endl;
    }

    bool search(T val)
    {
        if (!head)
            return false;
       
        DNode<T>* temp = head;
        while (temp->next != head)
        {
            if (temp->data == val)
            {
      
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    int countnodes()
    {
        int count = 0;
        if (!head)
        {
            return count;
        }
        DNode<T>* temp = head;
        do
        {
            count = count + 1;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
    void update(T key, T val)
    {
        if (!head)
            return;
        DNode<T>* temp = head;
        do
        {
            if (temp->data == key)
            {
                if (temp->next == head && temp->pre == head)
                {
                    head->data = val;
                    delete temp;
                    return;
                }
                temp->data = val;
                //delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "key not found" << endl;
        delete temp;
    }
    void merge(CDLL& list1, CDLL& list2)
    {
        if (list1.head == nullptr && list2.head == nullptr)
        {
            return;
        }
        DNode<T>* temp3;
        if (list1.head->pre = list1.head && list1.head->next == list1.head && list2.head == nullptr)
        {
            temp3 = list1.head;
            this->head = temp3;
        }


        DNode<T>* head1 = list1.head;
        DNode<T>* head2 = list2.head;
        this->head = temp3;
        while (head1->next != list1.head)
        {
            if (head2->data <= head1->data)
            {   
                temp3->next = head2;
                head2 = head2->next;
            }
            else
            {
                temp3->next = head1;
                head1 = head->next;
            }
            temp3 = temp3->next;
        }

    }
    /*void splitList(CDLL& leftHalf, CDLL& rightHalf)
    {    
        int count = this->countnodes();
            int n = count / 2;
        if (count%2 != 0)
        {
            for (int i = 1; i <= n; i++)
            {
                lefthalf = head;
                head = head->next;
            }
        }
    }*/
    ~CDLL()
    {
        delete head;
        head = nullptr;
        cout << "destroyed";
    }

};
int main()
{
    CDLL<int> list1;
    CDLL<int> list2;
    CDLL<int> list3;
    list1.insertathead(1);
    list1.insertattail(3);
    list1.insertattail(2);
    list1.display();
    list2.insertathead(5);
    list2.insertattail(7);
    list2.insertattail(9);
    list2.display();
    list3.merge(list1,list2);
     /* c.insertathead(27);
    c.insertathead(12);
   c.insertathead(21);
   c.insertathead(32);
    c.insertattail(42);
    c.insertattail(56);
    c.insertattail(29);
    c.insertattail(76);
    c.display();
    c.removeathead();
    c.removeattail();
  c.removeattail();
    c.display();
    c.remove(21);
    c.display();
    c.remove(42);
    c.display();
    c.remove(97);
    c.display();
    cout << c.search(40) << endl;
    cout << c.countnodes() << endl;
    c.update(12, 76);
    c.display();*/
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

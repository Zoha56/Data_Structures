// binarytreeA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
#include "Queue.cpp"
using namespace std;
template<typename T>
class BinaryTree
{
private:
    int height;
    T* data;
    bool* status;
    void deletehelper(int i)
    {
        if (i >= pow(2, height) - 1 || status[i] == false)
        {
            return;
        }

        deletehelper(2 * i + 1);//for left
        deletehelper(2 * i + 2);//for right
        status[i] = false;

    }
    void desendenthelper(int i)
    {
        if (i >= pow(2, height) - 1 || status[i] == false)
        {
            return;
        }
        if (status[2 * i + 1] == true)
        {
            cout << data[2 * i + 1] << " ";
        }
        if (status[2 * i + 2] == true)
        {
            cout << data[2 * i + 2] << " ";
        }
        desendenthelper(2 * i + 1);
        desendenthelper(2 * i + 2);


    }
    int helpherheight(int i, int count = 0)
    {

        if (i >= pow(2, height) - 1 || status[2 * i + 1] == false && status[2 * i + 2] == false)
        {
            return 1;
        }

        return 1 + max(helpherheight(2 * i + 1, count), helpherheight(2 * i + 2, count));
    }

    void dis_helper(int i)
     {
         if (i >= pow(2, height) - 1 || status[i] == false)
         {
             return;
         }
         cout << data[i];
         if ((2 * i + 1 < pow(2, height) - 1 && status[2 * i + 1] == true ) || (2 * i + 2 < pow(2, height) - 1 && status[2 * i + 2] == true))
         {
             cout  << "(";
             dis_helper(2 * i + 1);
             cout << ",";
             dis_helper(2 * i + 2);
             cout << ")";
         }
     }

   

public:
    BinaryTree()
    {
        height = 0;
        data = nullptr;
        status = nullptr;
    }
    BinaryTree(int h)
    {
        height = h;
        data = new T[pow(2, h) - 1];
        status = new bool[pow(2, height) - 1];
        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            status[i] = false;
        }
    }
    void setroot(T r)

    {
        if (status[0] == false)
        {
            data[0] = r;
            status[0] = true;
        }
    }
    T getroot()
    {
        if (status[0] == true)
        {
            return data[0];
        }
    }
    void setleftchild(T p, T v)
    {
        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true && data[i] == p)
            {
                if (2 * i + 1 < pow(2, height) + 1 && status[2 * i + 1] == false)
                {
                    data[2 * i + 1] = v;
                    status[2 * i + 1] = true;
                    return;
                }
            }
        }
    }
    T getparent(T node)
    {
        if (status[0] == false)
        {
            cout << "Tree is empty" << endl;
            exit(1);
        }
        if (data[0] == node)
        {
            cout << "IT is root" << endl;
            exit(1);
        }
        T parent;
        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true && data[i] == node)
            {
                parent = (i - 1) / 2;
                return data[parent];
            }
        }
    }
    void setrightchild(T p, T v)
    {
        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true && data[i] == p)
            {
                if (2 * i + 2 < pow(2, height) + 1 && status[2 * i + 2] == false)
                {
                    data[2 * i + 2] = v;
                    status[2 * i + 2] = true;
                    return;
                }
            }
        }
    }
    void remove(T v)
    {
        int index = -1;
        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true && data[i] == v)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "no matching value found" << endl;
            return;
        }
        deletehelper(index);

    }
    void displaylevelorder()
    {

        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true)
            {
                cout << data[i] << " ";
            }

        }
    }
    void printpreorder(int i = 0)
    {
        if (i >= pow(2, height) - 1 || status[i] == false)
        {
            return;
        }
        cout << data[i] << " ";
        printpreorder(2 * i + 1);
        printpreorder(2 * i + 2);
    }
    void printpostorder(int i = 0)
    {
        if (i >= pow(2, height) - 1 || status[i] == false)
        {
            return;
        }

        printpostorder(2 * i + 1);
        printpostorder(2 * i + 2);
        cout << data[i] << " ";
    }
    void printinorder(int i = 0)
    {
        if (i >= pow(2, height) - 1 || status[i] == false)
        {
            return;
        }

        printinorder(2 * i + 1);
        cout << data[i] << " ";
        printinorder(2 * i + 2);

    }
    ~BinaryTree()
    {
        delete[] data;
        delete[] status;
        data = nullptr;
        status = nullptr;
    }
    T getleftchild(T node)
    {

        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true && data[i] == node)
            {
                if (2 * i + 1 < pow(2, height) + 1 && status[2 * i + 1] == true)
                {
                    return data[2 * i + 1];;

                }
            }
        }


    }
    T getrightchild(T node)
    {

        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true && data[i] == node)
            {
                if (2 * i + 2 < pow(2, height) + 1 && status[2 * i + 2] == true)
                {
                    return data[2 * i + 2];;

                }
            }
        }

    }
    void displayAncestors(T node)
    {
        if (data[0] == node)
        {
            return;
        }

        T parent = getparent(node);
        cout << parent << " ";
        displayAncestors(parent);
    }
    void displaylevel(int l)
    {
        int noofnodes = pow(2, l - 1);
        int i = noofnodes - 1;
        cout << "Nodes in level " << l << " are " << endl;
        for (int j = i; j < i + noofnodes; j++)
        {
            if (status[j] == true)
            {
                cout << data[j] << " ";
            }
        }
        cout << endl;
    }
    void displaydescendents(T node)
    {
        int index=-1;
        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true && data[i] == node)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            return;
        }
        desendenthelper(index);

    }
    int heightoftree()
    {  
        int i = 0;
        return helpherheight(i);
    }
    int findlevelnumber(T node)
    {
        int index = -1;
        for (int i = 0; i < pow(2, height) - 1; i++)
        {
            if (status[i] == true && data[i] == node)
            {
                index = i;
                break;
            }
        }
        for (int j = 0; j < height; j++)
        {
            if (index >= pow(2, j) - 1 && index < pow(2, j + 1)-1)
            {
                return j+1;
            }
        }
    }
    void displayParenthesizedView()
    {
        dis_helper(0);
    }
    };
   int main()
    {
       BinaryTree<int> t(4);
       t.setroot(11);
       t.setleftchild(11, 5);
       t.setrightchild(11, 7);
       t.setleftchild(5, 9);
       t.setrightchild(5, 12);
       t.setleftchild(9, 4);
       t.setrightchild(12, 8);
      
       t.setrightchild(7, 2);
       t.setleftchild(2, 3);
       cout << "level order : ";
       t.displaylevelorder();
       cout << endl;
       cout << "pre order : ";
       t.printpreorder();
       cout << endl;
       cout << "post order : ";
       t.printpostorder();
       cout << endl;
       cout << "in order : ";
       t.printinorder();
       cout << endl;
      cout<<"Parent is: "<< t.getparent(9) << endl;
      cout << "Ancestors are: " << endl;
       t.displayAncestors(12);
       cout << endl;
       cout << "Desendents are: " << endl;
       t.displaydescendents(5);
       cout << endl;
       cout << endl << "height is: " ;
       cout << t.heightoftree() << endl;
       t.displaylevel(2);
       cout << t.findlevelnumber(12) << endl;
    // t.remove(9);
      t.printpreorder();
      cout << endl;
      t.displayParenthesizedView();
       return 0;

    }

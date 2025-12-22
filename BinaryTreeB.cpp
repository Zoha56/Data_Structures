// BinaryTreeB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
#include"Queue.cpp"
using namespace std;
template<typename T>
class Node
{
public:
    T info;
    Node<T>* left;
    Node<T>* right;
    Node(T v)
    {
        info = v;
        left = nullptr;
        right = nullptr;
    }
    Node()
    {
        info = 0;
        left = nullptr;
        right = nullptr;
    }
   
};
template<typename T>
class BinaryTree
{
private:
    Node<T>* root;
    Node<T>* search(Node<T>* curr, T p)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }
        if (curr->info == p)
        {
            return curr;
        }
        Node<T>* t;
        t = search(curr->left, p);
        if (!t)
        {
            t = search(curr->right, p);
        }
        return t;
    }
    Node<T>* searchP(Node<T>* curr, T p)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }
        if (curr->left && curr->left->info == p || curr->right && curr->right->info == p)
        {
            return curr;
        }
        Node<T>* t;
        t = searchP(curr->left, p);
        if (!t)
        {
            t = searchP(curr->right, p);
        }
        return t;
    }
    void remove(Node<T>* curr)
    {
        if (curr == nullptr)
            return;
        remove(curr->left);
        remove(curr->right);
        delete curr;
    }
    void preorder(Node<T>* curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        cout << curr->info << " ";
        preorder(curr->left);
        preorder(curr->right);
    }
    void postorder(Node<T>* curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        postorder(curr->left);
        postorder(curr->right);
        cout << curr->info << " ";
    }
    void inorder(Node<T>* curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        inorder(curr->left);
        cout << curr->info << " ";
        inorder(curr->right);
       
    }
    void desen_helper(Node<T>* p)
    {
        if (!p)
            return;
        cout << p->info << " ";
        desen_helper(p->left);
        desen_helper(p->right);
       
    }
    int height_helper(Node<T>* n)
    {
        if (!n)
            return 0;
        return 1 + max(height_helper(n->left), height_helper(n->right));
    }
   /* void displaylevel_helper(Node<T>* n, int k)
    {
        if (n == nullptr)
            return;
        if (k == 1)
        {
            cout << n->info << " ";
            return;
        }
        displaylevel_helper(n->left, k - 1);
        displaylevel_helper(n->right, k - 1);

    }
    int levelnumber_helper(Node<T>* n, T c)
    {
        Queue<Node<T>*> q;
        q.enqueue(n);
        int level = 1;
        q.enqueue(nullptr);
        while (!q.isEmpty())
        {
            Node<T>* temp = q.getfront();
            q.dequeue();
            if (temp == nullptr)
            {
                if(q.getfront()!=nullptr)
                {
                    q.enqueue(nullptr);
                }
                level += 1;
            }
            else
            {
                if (temp->info == c)
                {
                    return level;
                }
                if (temp->left != nullptr)
                {
                    q.enqueue(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.enqueue(temp->right);
                }
            }
        }
        return 0;
    }
    int totalcount(Node<T>* n)
    {
        if (n == nullptr)
            return 0;
        int left = totalcount(n->left);
        int right = totalcount(n->right);
        return left + right +1;
    }
    int sum_helper(Node<T>* n)
    {
        if (n == nullptr)
            return 0;
       int left = sum_helper(n->left);
        int right = sum_helper(n->right);
        return left+right+n->info;
    }
    
    bool isidentical(Node<T>* root1, Node<T>* root2)
    {
       
        if (!root1 && !root2)
        {
            return true;
        }
        if (root1==nullptr || root2==nullptr)
        {
            return false;
        }
        if (root1->info != root2->info)
        {
            return false;
        }
        bool isleft = isidentical(root1->left, root2->left);
        bool isright= isidentical(root1->right, root2->right);
        return isleft && isright;
    }
    void invert_helper(Node<T>* n)
    {
        if (n == nullptr)
        {
            return;
        }
        swap(n->left, n->right);
        invert_helper(n->left);
        invert_helper(n->right);
    }
    bool ismirror(Node<T>* root1, Node<T>* root2)
    {

        if (!root1 && !root2)
        {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr)
        {
            return false;
        }
        if (root1->info != root2->info)
        {
            return false;
        }
        bool isleft = ismirror(root1->left, root2->right);
        bool isright = ismirror(root1->right, root2->left);
        return isleft && isright;
    }*/
    void dis_helper(Node<T> *n)
    {
        if (n==nullptr)
        {
            return;
        }
        cout << n->info;
        if ((n->left!=nullptr || n->right!=nullptr))
        {
            cout << "(";
            dis_helper(n->left);
            cout << ",";
            dis_helper(n->right);
            cout << ")";
        }
    }
    Node<T>* copy( Node<T>* n2)
    {
        if (n2 == nullptr)
        {
            return nullptr;
        }
        Node<T>* temp = new Node<T>;
        temp->info= n2->info;
       temp->left= copy( n2->left);
       temp->right=copy( n2->right);
       return temp;
    }
    Node<T>* copymirror(Node<T>* n)
    {
        if (n == nullptr)
        {
            return nullptr;
        }
        Node<T>* temp = new Node<T>;
        temp->info = n->info;
        
       temp->right= copymirror(n->left);
       temp->left= copymirror(n->right);
       return temp;
    }
   /* bool isSubtree_helper(Node<T>* root1, Node<T>* root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        if (root1 != nullptr && root2 == nullptr)
        {
            return true;
        }
        if (root1->info == root2->info)
        {
            bool checkleft = isSubtree_helper(root1->left, root2->left);
            bool checkright = isSubtree_helper(root1->right, root2->right);
            return checkleft && checkright;
        }
        else
        {
            return false;
        }
       
       
    }*/
public:
    BinaryTree()
    {
        root = nullptr;
    }
    ~BinaryTree()
    {
        remove(root);
    }
    BinaryTree<T> operator=(BinaryTree<T>& b)
    {
        if (this !=&b)
        {
            this->remove(root);
            this->root = this->copy(b.getroot());
        }
        return *this;
    }
    BinaryTree(BinaryTree<T>& b)
    {
        this->root=this->copy(b.getroot());
    }
    BinaryTree<T> getMirrorImage()
    {
        this->root=copymirror(root);
        return *this;
    }
    void setroot(T v)
    { 
        if (!root)
        {
            root = new Node<T>(v);
        }
    }
    Node<T>* getroot()
    {
        if (root)
        {
            return root;
        }
    }
    void setleftchild(T p, T v)
    {
        Node<T>* n = search(root, p);
        if (n && n->left == nullptr)
        {
            n->left = new Node<T>(v);
        }
    }
    void setrightchild(T p, T v)
    {
        Node<T>* n = search(root, p);
        if (n && n->right == nullptr)
        {
            n->right = new Node<T>(v);
        }
    }
    void Remove(T v)
    {
        Node<T>* n = searchP(root, v);
        if (n)
        {
            if (n->left && n->left->info== v)
            {
                remove(n->left);
                n->left = nullptr;
            }
            else
            {
                remove(n->right);
                n->right = nullptr;

            }
        }
    }
    Node<T>* getparent(T p)
    {
        return searchP(root, p);;
    }
   /* void displayancstors(T c)
    {
        if (c == root->info)
        {
            return;
        }
        
        Node<T>* n = getparent(c);
        cout << n->info<<" ";
        displayancstors(n->info);
        
    }*/
    void displaydesndents(T c)
    {
        Node<T>* n = search(root, c);
        if (!n)
        {
            return;
        }
        cout << "desendents are ";
        desen_helper(n->left);
        desen_helper(n->right);
    }
    void heightofTree()
    {
        cout << "height of tree is: "<<height_helper(root);
    }
    void printpreorder()
    {
        cout << "Pre order: ";
        preorder(root);
    }
    void printpostorder()
    {
        cout << "Post order: ";
        postorder(root);
    }
    void printinorder()
    {
        cout << "In order: ";
        inorder(root);
    }
    void displaylevelorder()
    {
        if (root == nullptr)
        {
            return;
        }
        cout << "Level order: ";
        Queue<Node<T>*> q;
        q.enqueue(root);
        while (!q.isEmpty())
        {
            Node<T>* curr = q.dequeue();
            cout << curr->info <<" ";
            if (curr->left)
                q.enqueue(curr->left);
            if (curr->right)
                q.enqueue(curr->right);

        }
    }
   
    int external(T n)
    {   
        Node<T>* temp = search(root, n);

        if (temp->left == nullptr && temp->right==nullptr)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    int internal(T n)
    {
        Node<T>* temp = search(root, n);

        if (temp && (temp->left !=nullptr || temp->right != nullptr))
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
  /*  void displaylevel(int k)
    {  
        cout << "level " << k << " is: ";
        displaylevel_helper(root, k);
    }
    void levelnumber(T c)
    {
        cout <<"Level number is: " <<levelnumber_helper(root, c);
    }
    void countnodes()
    {
        cout << "total nodes are: " << totalcount(root);
    }
    void sumofnodes()
    {
        cout << "sum is: " << sum_helper(root) << endl;
    }
    
    void issame(Node<T>* root2)
    {
        cout << "Is identical: " << isidentical(root, root2)<<endl;
    }
    void invert()
    {
        invert_helper(root);

    }
    void isMirror(Node<T>* root2)
    {
        cout << "is trees are mirror: " << ismirror(root, root2) << endl;
    }*/
    T findSiblings(T node)
    {
        Node<T>* temp = getparent(node);
        if (temp)
        {
            if (temp->left->info == node && temp->right)
            {

                return temp->right->info;
            }
            else if (temp->right->info == node && temp->left)
            {

                return temp->left->info;
            }
            else
            {

                return -1;
            }
        }
        else
        {

            return -1;
        }
    }
    void displayParenthesizedView()
    {
        dis_helper(root);
    }
};
int main() {
    BinaryTree<int> bt;

    bt.setroot(1);
    bt.setleftchild(1, 2);
    bt.setrightchild(1, 3);
    bt.setleftchild(2, 4);
    bt.setrightchild(2, 5);
    bt.setleftchild(3, 6);
    bt.setrightchild(3, 7);
   /* bt.setleftchild(7, 8);
    bt.setrightchild(8, 9);*/
 
    bt.printpreorder();
    cout << endl;
    bt.printinorder();    // 4 2 5 1 6 3 7
    cout << endl;
    bt.printpostorder(); // 4 5 2 6 7 3 1
    cout << endl;
    bt.displaylevelorder(); // 1 2 3 4 5 6 7
   /* cout << endl;
    cout << "Ancestors are: ";
    bt.displayancstors(7);*/
    cout << endl;
    bt.displaydesndents(3);
    cout << endl;
    bt.heightofTree();
    cout << endl;
   
    int i = bt.external(6);
    cout << "Is external node: " << (i == 1? "yes" : "No") << endl;
    int j = bt.internal(2);
   cout << "Is internal node: " << (j == 1 ? "yes" : "No") << endl;
  int sib= bt.findSiblings(2);
  cout << "sibling of given node is: " << sib << endl;
  bt.displayParenthesizedView();
  cout << endl;
  cout << "__________________________________________" << endl;
  cout << "Checking constructors" << endl;
  BinaryTree<int> bt1(bt);
  cout << "using copy constructor" << endl;
  bt1.printpreorder();
  cout << endl;
  bt1.setleftchild(7, 8);
  bt1.setrightchild(8, 9);
  bt = bt1;
  cout << "Added new values to 2nd tree and assign tree 2 to tree1" << endl;
  bt.printpreorder();   // 1 2 4 5 3 6 7 8 9
  cout << endl;
  cout << "mirror of tree 2" << endl;
  bt1.getMirrorImage();
  bt1.printpreorder();
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

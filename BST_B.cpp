// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<cmath>
#include<array>
#include "Queue.cpp"
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};
template<class T>
class BST
{
private:
    Node<T>* root;
    void inOrderHelper(Node<T>* p)
    {
        if (p != nullptr) {
            inOrderHelper(p->left);
            cout << p->data << " ";
            inOrderHelper(p->right);
        }
    }
    void preOrderHelper(Node<T>* p)
    {
        if (p != nullptr) {
            std::cout << p->data << " ";
            preOrderHelper(p->left);
            preOrderHelper(p->right);
        }
    }
    void postOrderHelper(Node<T>* p)
    {
        if (p != nullptr) {
            postOrderHelper(p->left);
            postOrderHelper(p->right);
            std::cout << p->data << " ";
        }
    }
    Node<T>* findMin(Node<T>* node) // Helper function to find the minimum node in a subtree
    {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node<T>* findMax(Node<T>* node) // Helper function to find the minimum node in a subtree
    {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    Node<T>* deleteNode(Node<T>* root, T node)  // Helper function to delete a node
    {
        if (root == nullptr) {
            return root;
        }

        if (node < root->data) {
            root->left = deleteNode(root->left, node);
        }
        else if (node > root->data) {
            root->right = deleteNode(root->right, node);
        }
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node<T>* temp = findMin(root->right);
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    void levelorderhelper(Node<T>* root)
    {
        if (root == nullptr)
            return;
        Queue<Node<T>*> Q;
        Q.enqueue(root);
        while (!Q.isEmpty())
        {
            Node<T>* temp = Q.dequeue();

            cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                Q.enqueue(temp->left);
            }
            if (temp->right != nullptr)
            {
                Q.enqueue(temp->right);
            }

        }

    }
    int heighthelper(Node<T>* p)
    {

        if (p == nullptr)
        {
            return 0;
        }
        return 1 + max(heighthelper(p->left), heighthelper(p->right));
    }
    int counthelper(Node<T>* p)
    {
        if (p == nullptr)
        {
            return 0;
        }
        return 1 + counthelper(p->left) + counthelper(p->right);
    }
    /* T kthsmallesthelper(Node<T>* p, int n,int &count)
     {
         if (p == nullptr)
             return -1;
         T left = kthsmallesthelper(p->left, n, count);
         if (left != -1)
         {
             return left;
         }
         count++;
         if (count == n)
         {
             return p->data;
         }
         return kthsmallesthelper(p->right, n, count);

     }
     T sumhelper(Node<T>* p)
     {
         if (p == nullptr)
             return 0;
         return sumhelper(p->left) + sumhelper(p->right) + p->data;
     }
     void leafnodeshelper(Node<T>* p)
     {
         if (p == nullptr)
         {
             return;
         }
         if (p->left == nullptr && p->right == nullptr)
         {
             cout << p->data << " ";
             return;
         }
         leafnodeshelper(p->left);
         leafnodeshelper(p->right);
     }
     bool isbalancehelper(Node<T>* n, int& height) {
         if (!n) {
             height = 0;
             return true;
         }

         int lh = 0, rh = 0;
         bool leftB = isbalancehelper(n->left, lh);
         bool rightB = isbalancehelper(n->right, rh);

         height = 1 + max(lh, rh);

         if (!leftB || !rightB)
             return false;

         if (abs(lh - rh) > 1)
             return false;

         return true;
     }*/
    bool recSearch_helper(Node<T>* curr, int key)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        if (curr->data == key)
        {
            return curr;
        }
        bool a = false;
        Node<T>* t = curr;
        if (key < curr->data)
        {
            a = recSearch_helper(curr->left, key);
        }
        else
        {
            a = recSearch_helper(curr->right, key);
        }
        return a;
    }
    void duplicate_helper(Node<T>* n)
    {
        if (n == nullptr)
            return;
        duplicate_helper(n->left);
        duplicate_helper(n->right);
        Node<T>* temp = new Node<T>(n->data);
        Node<T>* copy = n->left;
        n->left = temp;
        temp->left = copy;

    }
    void allpath_helper(Node<T>* n, int path[], int k)
    {
        if (n == nullptr)
            return;
        path[k] = n->data;
        if (n->left == nullptr && n->right == nullptr)
        {
            for (int i = 0; i <= k; i++)
            {
                cout << path[i];
                if (i < k) cout << " -> ";
            }
            cout << endl;
            return;
        }
        allpath_helper(n->left, path, k + 1);
        allpath_helper(n->right, path, k + 1);
    }
    void createBackBone(Node<T>* r)
    {
        Node<T>* temp = r;
        Node<T>* par = r;
        while (temp != nullptr)
        {
            if (temp->left != nullptr)
            {  
                par->right = temp->left;
                temp=rightRotation(temp);
                temp = par;
            }
            else
            {
                par = temp;
                temp = temp->right;
                
            }
        }
    }
 /*   void construct_helper(int inorder[], int preorder[], int insi, int prsi)
    {
        if (int insi == 0 && int prsi == 0)
        {
            return;
        }
    }*/

public:
    BST() : root(nullptr) {}
    void insert(T node);
    bool search(T node);
    void inOrder();
    void preOrder();
    void postOrder();
    void deleteMethod(T p);
    Node<T>* leftRotation(Node<T>* temp)
    {
        Node<T>* temp_right = temp->right;
        temp->right = temp_right->left;
        temp_right->left = temp;
        temp = temp_right;
        return temp;
    }
    Node<T>* rightRotation(Node<T>* temp) {
        Node<T>* temp_left = temp->left;
        temp->left = temp_left->right;
        temp_left->right = temp;
        temp = temp_left;
        return temp;
    }
    void printAllPaths()
    {

        int path[100], k = 0;
        allpath_helper(root, path, k);
    }
    void minimum()
    {
        Node<T>* min = findMin(root);
        cout << "Minimum Node is: " << min->data << endl;
    }
    void maximum()
    {
        Node<T>* max = findMax(root);
        cout << "Maximum Node is: " << max->data << endl;
    }
    void levelorder()
    {
        levelorderhelper(root);
        cout << endl;
    }
    void heightofBST()
    {
        cout << "Height is: " << heighthelper(root) << endl;

    }
    void totalnodes()
    {
        cout << "Total nodes are: " << counthelper(root) << endl;
    }
    /* void kthsmallest(int k)
     {
         int count = 0;
         cout << k << " smallest element is: " << kthsmallesthelper(root, k, count) << endl;
     }
     void sumofallNodes()
     {
         cout << "sum is: " << sumhelper(root) << endl;
     }
     void printleaf()
     {
         cout << "leaf nodes are: ";
         leafnodeshelper(root);
         cout << endl;
     }
     bool isBalance()
     {
         int height = 0;
         isbalancehelper(root);
     }*/
    bool recSearch(int key)
    {
        return recSearch_helper(root, key);
    }
    void doubletree()
    {
        duplicate_helper(root);
    }
    /* void construct_from_traversals(int in_order[], int pre_order[], int si)
     {
         int k = 0;
         construct_helper(in_order, pre_order, k, si, root);
     }*/
    void createBalanceTree(T arr[], int k, int n)
    {
        if (k > n)
            return;
        int mid = (k +n) / 2;
         insert(arr[mid]);
        createBalanceTree(arr, k, mid - 1);
        createBalanceTree(arr, mid + 1, n);

    }
    void convert_to_backbone()
    {
        createBackBone(root);
    }
    //void createperfecttree()
    //{
    //    int n = counthelper(root);
    //    int lg = int(log2(n + 1));
    //    int m = pow(2, lg) - 1;
    //    int n_m = n - m;
    //    Node<T>* temp = root;
    //    for (int i = 0; i < n_m; i++)
    //    {
    //                   
    //        root = leftRotation(temp); // rotate temp
    //        temp = root->right;
    //    }
    //    while (m > 1)
    //    {
    //        m = m / 2;
    //        temp = root;
    //        for (int i = 0; i < m; i++)
    //        {    
    //            if (temp == nullptr || temp->right == nullptr) break;
    //            temp->right= leftRotation(temp);
    //            temp = temp->right->right;
    //        }
    //    }
    //}
    void createperfecttree() {
        if (root == nullptr)
            return;

        // Step 1: Convert to backbone
        createBackBone(root);

        // Step 2: Count nodes
        int n = counthelper(root);

        // Step 3: Compute m
        int  lg = float(log2(n + 1));
        int m = pow(2, lg) - 1;

        // Step 4: First n-m rotations
        Node<T>* temp = root;
        for (int i = 0; i < n - m; i++) {
            root = leftRotation(temp); // rotate top node
            temp = root->right;
        }

        // Step 5: Iteratively balance
        while (m > 1) {
            m /= 2;
            //temp = root;
            for (int i = 0; i < m; i++) {
                if (temp == nullptr || temp->right == nullptr)
                    break;
                root = leftRotation(temp);
                temp = root->right;
            }
        }
    }

};
template<class T>
void BST<T>::insert(T node) {
    Node<T>* newNode = new Node<T>(node);

    if (root == nullptr) {
        root = newNode;
    }
    else {
        Node<T>* current = root;
        Node<T>* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (node < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (node < parent->data) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }
}

// Public function
template<class T>
void BST<T>::deleteMethod(T node) {
    root = deleteNode(root, node);
}
template<class T>
bool BST<T>::search(T node) {
    Node<T>* current = root;
    while (current != nullptr) {
        if (current->data == node) {
            return true;
        }
        else if (node < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}


// Public function
template<class T>
void BST<T>::inOrder() {
    inOrderHelper(root);
    std::cout << std::endl;
}


// Public function
template<class T>
void BST<T>::preOrder() {
    preOrderHelper(root);
    std::cout << std::endl;
}


// Public function
template<class T>
void BST<T>::postOrder() {
    postOrderHelper(root);
    std::cout << std::endl;
}
int main1() {
    BST<int> bst;
    int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 0;
    bst.createBalanceTree(arr, k, n - 1);
    cout << "Pre-order: ";
    bst.preOrder();
    cout << "In-order: ";
    bst.inOrder();
    cout << "Post-order: ";
    bst.postOrder();
    return 0;
}
int main()
{
    BST<int> bst;
    bst.insert(5);
    bst.insert(10);
    bst.insert(20);
    bst.insert(15);
    bst.insert(30);
    bst.insert(25);
    bst.insert(40);
    bst.insert(23);
    bst.insert(28);
    bst.levelorder();
    
    bst.convert_to_backbone();
    bst.levelorder();
    bst.createperfecttree();
    bst.levelorder();   
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window o connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
//if (k > si)
//{
//    return;
//}
//n = new Node<T>(preorder[k]);
//int mid = (k + (si - 1)) / 2;
//if (n->data == inorder[mid])
//return mid;
//else if (n->data > preorder[mid])
//construct_helper(inorder, preorder, k, mid - 1, n->left);
//else
//construct_helper(inorder, preorder, mid + 1, si, n->right);
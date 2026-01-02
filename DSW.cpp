#include <iostream>
#include<vector>
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
    int heighthelper(Node<T>* p)
    {

        if (p == nullptr)
        {
            return 0;
        }
        return 1 + max(heighthelper(p->left), heighthelper(p->right));
    }
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
  /*  void createBackBone(Node<T>* r)
    {
        Node<T>* temp = r;
        Node<T>* par = r;
        Node<T>* rotate = nullptr;
        while (temp != nullptr)
        {  
            par = temp;
            if (temp->left != nullptr)
            {
               par->right = temp->left;
               rotate= rightRotation(temp);
               temp = par;
            }
            else
            {
                temp=temp->right;
            }
        }
    }*/
   
    void construct_from_traversals_help(Node<T>*& curr, vector<int> in_order, vector<int> pre_order)
    {
        if (pre_order.empty() || in_order.empty()) {
            curr = nullptr;
            return;
        }
        vector<int> P_R;
        vector<int> P_L;
        vector<int> I_R;
        vector<int> I_L;
        curr = new Node<T>(pre_order[0]);
        int i = 0;
        for (i = 0; i < in_order.size(); i++)
        {
            if (in_order[i] == pre_order[0])
            {
                break;
            }
        }
        for (int j = 0; j < i; j++)
        {
            I_L.push_back(in_order[j]);
            P_L.push_back(pre_order[j + 1]);
        }
        for (int j = i + 1; j < in_order.size(); j++)
        {
            I_R.push_back(in_order[j]);
            P_R.push_back(pre_order[j]);
        }
        construct_from_traversals_help(curr->left, I_L, P_L);
        construct_from_traversals_help(curr->right, I_R, P_R);

    }
public:
    BST() : root(nullptr) {}
    void insert(T node);
    bool search(T node);
    void inOrder();
    void preOrder();
    void postOrder();
    void deleteMethod(T p);
    void heightofBST()
    {
        cout << "Height is: " << heighthelper(root) << endl;

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
    bool recSearch(int key)
    {
        return recSearch_helper(root, key);
    }
    void doubletree()
    {
        duplicate_helper(root);
    }
    void createBalanceTree(T arr[], int k, int n)
    {
        if (k > n)
            return;
        int mid = (k + n) / 2;
        insert(arr[mid]);
        createBalanceTree(arr, k, mid - 1);
        createBalanceTree(arr, mid + 1, n);

    }
 /*   void convert_to_backbone()
    {
        createBackBone(root);
    }
   */
    void construct_from_posttraversals(Node<T>*& curr, vector<int> in_order, vector<int> post_order)
    {
        // 1. Base Case
        if (post_order.empty() || in_order.empty()) {
            curr = nullptr;
            return;
        }

        // 2. The Root is the LAST element of post_order
        int rootVal = post_order.back();
        curr = new Node<T>(rootVal);

        // 3. Find the root index in in_order
        int i = 0;
        for (i = 0; i < in_order.size(); i++) {
            if (in_order[i] == rootVal) break;
        }

        // 4. Split vectors based on 'i' (the number of nodes in the left subtree)
        vector<int> I_L, I_R, P_L, P_R;

        // Fill In-Order Left and Right
        for (int j = 0; j < i; j++)
        {
            I_L.push_back(in_order[j]);
            P_L.push_back(post_order[j]);
        }
        for (int j = i + 1; j < in_order.size(); j++)
        {
            I_R.push_back(in_order[j]);
        }
        for (int j = i; j < post_order.size() - 1; j++) { // Stop before the last element (root)
            P_R.push_back(post_order[j]);
        }

        // 5. Recursively build
        construct_from_posttraversals(curr->left, I_L, P_L);
        construct_from_posttraversals(curr->right, I_R, P_R);
    }
    void construct_from_traversals(vector<int> in_order, vector<int> pre_order)
    {
        construct_from_traversals_help(root, in_order, pre_order);
    }
    void createBackBone() {
        if (root == nullptr) return;
        Node<T>* dummy = new Node<T>(0);
        dummy->right = root;

        Node<T>* prev = dummy;
        Node<T>* curr = dummy->right;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                curr = rightRotation(curr);
                prev->right = curr;
            }
            else {
                prev = curr;
                curr = curr->right;
            }
        }

        root = dummy->right;
        delete dummy;
    }
    void createPerfectTree() {
        int n = 0;
        Node<T>* temp = root;
        while (temp != nullptr) {
            n++;
            temp = temp->right;
        }

        if (n < 3) return;
        int h = floor(std::log2(n + 1));
        int m = pow(2, h) - 1;

        Node<T>* dummy = new Node<T>(0);
        dummy->right = root;

        Node<T>* prev = dummy;
        Node<T>* curr = dummy->right;
        for (int i = 0; i < (n - m); i++) {
            prev->right = leftRotation(curr); // Use your leftRotation
            prev = prev->right;               // Move to the next node in the vine
            curr = prev->right;
        }

        while (m > 1) {
            m = m / 2;
            prev = dummy;
            curr = dummy->right;
            for (int i = 0; i < m; i++) {
                prev->right = leftRotation(curr); // Use your leftRotation
                prev = prev->right;
                curr = prev->right;
            }
        }

        root = dummy->right;
        delete dummy;
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
int main() {
    BST<int> bst;
    vector<int> in1 = { 1, 2, 3, 4, 5, 6 };
    vector<int> pre1 = { 3, 1, 2, 5, 4, 6 };
    bst.construct_from_traversals(in1, pre1);
    cout << "In-order traversal (Example 1): ";
    bst.inOrder();
    cout << "Post-order traversal (Example 1): ";
    bst.postOrder();
    bst.preOrder();
    BST<int> bst2;
    vector<int> in2 = { 5,10,15,25,27,30,35,40,45,50,52,55,60,65,70,75,80,85,90,100 };
    vector<int> pre2 = { 50,25,10,5,15,40,30,27,35,45,75,60,55,52,65,70,90,80,85,100 };
    bst2.construct_from_traversals(in2, pre2);
    cout << "\nIn-order traversal (Example 2): ";
    bst2.inOrder();
    cout << "Post-order traversal (Example 2): ";
    bst2.postOrder();
  /*  bst.convert_to_backbone();
    bst.preOrder();*/
    bst.createBackBone();
    bst.preOrder();
    bst.createPerfectTree();
    bst.preOrder();
    return 0;
}
// graph-link list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
    Node()
    {
        data = NULL;
        next = nullptr;
    }
};
class Graph
{
private:
    Node** adjList;
    int maxVer;
    int n;
    bool* visited;
    void DFS(int v)
    {
        cout << v << endl;
        visited[v] = true;
        Node* temp = adjList[v];
        while (temp != nullptr)
        {
            int neighbour = temp->data;
            if (!visited[neighbour])
            {
                DFS(neighbour);
            }
            temp = temp->next;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i);
            }
        }
    }
    bool iscycleDFS(int v, int par)
    {
        visited[v] = true;
        Node* temp = adjList[v];
        while (temp != nullptr)
        {
            if (!visited[temp->data])
            {
                if (iscycleDFS(temp->data, v))
                {
                    return true;
                }
            }
            else if (temp->data != par)
            {
                return true;
            }
            temp = temp->next;
        }
       /* for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (iscycleDFS(i, -1))
                    return true;
            }
        }*/
        return false;
    }
public:
    Graph()
    {
        maxVer = 0;
        n = 0;
        adjList = nullptr;
        visited = nullptr;
    }
    Graph(int m)
    {
        maxVer = m;
        n = 0;
        adjList = new Node * [maxVer];
        visited = new bool[maxVer];
        for (int i = 0; i < maxVer; i++)
        {
            adjList[i] = nullptr;
            visited[i] = false;
        }
       
    }
    ~Graph()
    {
        for (int i = 0; i < n; i++) {
            Node* curr = adjList[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] adjList;
        delete[] visited;
    }
    bool addvertex()
    {
        if (n >= maxVer)
        {
            return false;
        }
        adjList[n] = nullptr;
        n = n + 1;
        return true;
    }
    bool addedge(int u, int v)
    {
        if (u < 0 || v < 0 || u >= n || v >= n)
        {
            return false;
        }
        Node* newnode1 = new Node(v);
        Node* newnode2 = new Node(u);
        if (adjList[u] == nullptr)
        {
            adjList[u]= newnode1;
        }
        else
        {  
            Node* temp = adjList[u];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode1;
        }
        if (adjList[v] == nullptr)
        {
            adjList[v] = newnode2;
        }
        else
        {
            Node* temp = adjList[v];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode2;
        }
        return true;
    }
    bool removeedge(int u, int v) {
        if (u < 0 || v < 0 || u >= n || v >= n) return false;

        if (adjList[u] != nullptr) {
            if (adjList[u]->data == v) { 
                Node* toDelete = adjList[u];
                adjList[u] = adjList[u]->next;
                delete toDelete;
            }
            else { 
                Node* curr = adjList[u];
                while (curr->next != nullptr && curr->next->data != v) {
                    curr = curr->next;
                }
                if (curr->next != nullptr) { 
                    Node* toDelete = curr->next;
                    curr->next = toDelete->next; 
                    delete toDelete;
                }
            }
        }

        if (adjList[v] != nullptr) {
            if (adjList[v]->data == u) {
                Node* toDelete = adjList[v];
                adjList[v] = adjList[v]->next;
                delete toDelete;
            }
            else {
                Node* curr = adjList[v];
                while (curr->next != nullptr && curr->next->data != u) {
                    curr = curr->next;
                }
                if (curr->next != nullptr) {
                    Node* toDelete = curr->next;
                    curr->next = toDelete->next;
                    delete toDelete;
                }
            }
        }
        return true;
    }
    bool isempty()
    {
        if (n == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool iscomplete()
    {
        if (n <= 1)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            Node* temp = adjList[i];
            while (temp != nullptr)
            {
                count++;
                temp = temp->next;
            }
            if (count != (n - 1))
            {
                return false;
            }
        }
        return true;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";
            Node* temp = adjList[i];
            while (temp != nullptr)
            {
                cout << temp->data;
                if (temp->next != nullptr)
                {
                    cout << " ->";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void DFS()
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        int v;
        cout << "enter a vertex you want to start with" << endl;
        cin >> v;
        if (v < 0 || v >= n)
        {
            cout << "vertex don't exist in graph" << endl;
            return;
        }
        DFS(v);
    }
    void BFS()
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        int v;
        cout << "enter a vertex you want to start with" << endl;
        cin >> v;
        if (v < 0 || v >= n)
        {
            cout << "vertex don't exist in graph" << endl;
            return;
        }
        queue<int> Q;
        Q.push(v);
        visited[v] = true;
        while (!Q.empty())
        {
            int d = Q.front();
            Q.pop();
            cout << d << " ";
            Node* temp = adjList[d];
            while (temp!= nullptr)
            {
                if (!visited[temp->data])
                {
                    Q.push(temp->data);
                    visited[temp->data] = true;
                }
                temp = temp->next;
            }
        }
    }
    bool iscycle()
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        int v;
        cout << "enter a vertex you want to start with" << endl;
        cin >> v;
        if (v < 0 || v >= n)
        {
            cout << "vertex don't exist in graph" << endl;
            return false;
        }
      return  iscycleDFS(v, -1);
    }
};

int main() {
    int maxVertices, choice, u, v;
    cout << "--- Graph Adjacency List System ---" << endl;
    cout << "Enter maximum number of vertices: ";
    cin >> maxVertices;

    Graph g(maxVertices);

    do {
        cout << "\n------- MENU -------" << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Remove Edge" << endl;
        cout << "4. Display Graph" << endl;
        cout << "5. BFS Traversal" << endl;
        cout << "6. DFS Traversal" << endl;
        cout << "7. Check if Complete" << endl;
        cout << "8. Check for Cycle" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (g.addvertex()) cout << "Vertex added successfully." << endl;
            else cout << "Graph is full!" << endl;
            break;

        case 2:
            cout << "Enter source and destination (u v): ";
            cin >> u >> v;
            if (g.addedge(u, v)) cout << "Edge added." << endl;
            else cout << "Invalid vertices!" << endl;
            break;

        case 3:
            cout << "Enter edge to remove (u v): ";
            cin >> u >> v;
            if (g.removeedge(u, v)) cout << "Edge removed (if it existed)." << endl;
            else cout << "Invalid vertices!" << endl;
            break;

        case 4:
            g.display();
            break;

        case 5:
            g.BFS();
            cout << endl;
            break;

        case 6:
            g.DFS();
            cout << endl;
            break;

        case 7:
            if (g.iscomplete()) cout << "The graph is a Complete Graph." << endl;
            else cout << "The graph is NOT complete." << endl;
            break;

        case 8:
            if (g.iscycle()) cout << "Cycle detected in the graph!" << endl;
            else cout << "No cycle found." << endl;
            break;

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

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

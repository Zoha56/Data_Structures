// graphmatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
class Graph {
private:
    int** adjMatrix; // Adjacency matrix of the graph
    int maxVertices; // Max number of vertices which can be present in the graph
    int n; // Current number of vertices present in the graph
    bool* visited; // Array to keep track of visited/unvisited vertices
    void DFS(int v)
    {
        cout << v << " ";
        visited[v] = true;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false && adjMatrix[v][i] == 1)
            {
                DFS(i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS(i); //if not connected
            }
        }
    }
    bool iscycle(int par,int v)
    {
        visited[v] = true;
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[v][i] == 1 )
            { 
              if(visited[i] == false)
              {
                if (iscycle(v, i))
                {
                    return true;
                }
              }
              else if(i!=par)
              {
                    return true;
              }
            }
        }
     
        return false;
    }
public:
    Graph(int maxV, int currV)
    {
        maxVertices = maxV;
        n = currV;
        adjMatrix = new int*[maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            adjMatrix[i] = new int[maxVertices];
        }
        visited = new bool[maxVertices] {false};
    }
    Graph(const Graph& obj)
    {
        maxVertices = obj.maxVertices;
        n = obj.n;
        adjMatrix = new int* [maxVertices];
        for (int i = 0; i < maxVertices; i++)
        {
            adjMatrix[i] = new int[maxVertices];

            for (int j = 0; j < maxVertices; j++)
            {
                adjMatrix[i][j] = obj.adjMatrix[i][j];
            }
        }
        visited = new bool[maxVertices] {false};//for fresh start

        /*for (int j = 0; j < maxVertices; j++)
        {
            visited[j] = obj.visited[j];
        }*/
    }
    // Constructor to allocate and initialize an empty graph of the specified size. Here,
    // maxV indicates the max # of vertices and currV indicates the current # of vertices
    ~Graph() // Destructor
    {
        for (int i = 0; i < maxVertices; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] visited;
    }
    bool addVertex(int& v)
        // Adds a new vertex to the graph. This function should store the number of the //
    {
        if (n >= maxVertices)
        {
            cout << "graph is full" << endl;
            return false;
        }
        v = n;
        for (int i = 0; i < maxVertices; i++)
        {
            adjMatrix[v][i] = 0;
            adjMatrix[i][v] = 0;
        }
        n= n+1;
        visited[v] = false;
        return true;
    }
    bool addEdge(int u, int v) // Adds the edge <u,v> to the graph
    {
        if (u < 0 || v < 0 || u >= n || v >= n)
        {
            return false;
        }
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        return true;
    }
    bool removeEdge(int u, int v) // Removes the edge <u,v> from the graph
    {
        if (u < 0 || v < 0 || u >= n || v >= n)
        {
            return false;
        }
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
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
            for (int j = 0; j < n; j++)
            {
                if (i!=j && adjMatrix[i][j] == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void clear()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<< adjMatrix[i][j] <<" ";
            }
            cout << endl;
        }
    }
    int Degree(int v)
    { 
        if (v < 0 || v >= n)
        {
            return -1;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[v][i] == 1)
            {
                count += 1;
            }
        }
        return count;
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
        queue<int> q;
        bool finished = false;
        while (!finished)
        {
            q.push(v);
            visited[v] = true;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                cout << temp << " ";
                for (int i = 0; i < n; i++)
                {
                    if (visited[i] == false && adjMatrix[temp][i] == 1)
                    {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
            finished = true;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    v = i;
                    finished = false;
                    break;
                }
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
       return iscycle(-1, v);
    }
    bool iscycleBFS()
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
        queue<pair<int, int>> Q;
        Q.push({ v,-1 });
        visited[v] = true;
        while (!Q.empty())
        {
            int tempV = Q.front().first;
            int par = Q.front().second;
            Q.pop();
            for (int i = 0; i < n; i++)
            {
                if (adjMatrix[tempV][i] == 1)
                {
                    if (visited[i] == false)
                    {
                        Q.push({ i,tempV });
                        visited[i] = true;
                    }
                    else if (i != par)
                    {
                        return true;
                    }
                }
            }
        }
        return false;

    }
};
int main() {
    int maxV, initialV;
    cout << "--- Graph Matrix Setup ---" << endl;
    cout << "Enter maximum capacity of vertices: ";
    cin >> maxV;
    cout << "Enter current number of vertices: ";
    cin >> initialV;

    Graph g(maxV, initialV);

    int choice;
    do {
        cout << "\n--- Graph Operations Menu ---" << endl;
        cout << "1. Add Edge" << endl;
        cout << "2. Remove Edge" << endl;
        cout << "3. Display Adjacency Matrix" << endl;
        cout << "4. Perform DFS" << endl;
        cout << "5. Perform BFS" << endl;
        cout << "6. Check Cycle (DFS)" << endl;
        cout << "7. Check Cycle (BFS)" << endl;
        cout << "8. Get Vertex Degree" << endl;
        cout << "9. Check if Complete" << endl;
        cout << "10. Add New Vertex" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        int u, v;
        switch (choice) {
        case 1:
            cout << "Enter u and v: ";
            cin >> u >> v;
            if (g.addEdge(u, v)) cout << "Edge added." << endl;
            else cout << "Failed to add edge." << endl;
            break;
        case 2:
            cout << "Enter u and v: ";
            cin >> u >> v;
            if (g.removeEdge(u, v)) cout << "Edge removed." << endl;
            break;
        case 3:
            cout << "Adjacency Matrix:" << endl;
            g.display();
            break;
        case 4:
            cout << "DFS Traversal: ";
            g.DFS();
            cout << endl;
            break;
        case 5:
            cout << "BFS Traversal: ";
            g.BFS();
            cout << endl;
            break;
        case 6:
            if (g.iscycle()) cout << "Cycle detected via DFS!" << endl;
            else cout << "No cycle detected." << endl;
            break;
        case 7:
            if (g.iscycleBFS()) cout << "Cycle detected via BFS!" << endl;
            else cout << "No cycle detected." << endl;
            break;
        case 8:
            cout << "Enter vertex: ";
            cin >> v;
            cout << "Degree of " << v << " is: " << g.Degree(v) << endl;
            break;
        case 9:
            if (g.iscomplete()) cout << "The graph is complete." << endl;
            else cout << "The graph is NOT complete." << endl;
            break;
        case 10:
            int newV;
            if (g.addVertex(newV)) cout << "Vertex added at index: " << newV << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
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

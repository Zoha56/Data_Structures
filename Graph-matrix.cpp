#include<iostream>
#include"Queue.cpp"
#include "piority queue.cpp"
#define INF 999
using namespace  std;
class Graph {
private:
	int** adjMatrix; // Adjacency matrix of the graph
	int maxVertices; // Max number of vertices which can be present in the graph
	int n; // Current number of vertices present in the graph
	bool* visited; // Array to keep track of visited/unvisited vertices
	void DFS(int v)
	{
		if (v < 0 || v >= n)
		{
			return;
		}
		visited[v] = true;
		cout << v << " ";
		for (int i = 0; i < n; i++)
		{
			if (adjMatrix[v][i] != 0 && visited[i] == false)
			{
				DFS(i);
			}
		}
	}
public:
	Graph(int maxV, int currV)
	{
		maxVertices = maxV;
		n = currV;
		adjMatrix = new int* [maxVertices];
		for (int i = 0; i < maxVertices; i++)
		{
			adjMatrix[i] = new int[maxVertices];
			for (int j = 0; j < maxVertices; j++)
				adjMatrix[i][j] = 0;
		}
		visited = new bool[maxVertices] {false};
	}

	// Constructor to allocate and initialize an empty graph of the specified size. Here,
	// maxV indicates the max # of vertices and currV indicates the current # of vertices
	~Graph()// Destructor
	{
		for (int i = 0; i < maxVertices; i++)
		{
			delete[] adjMatrix[i];
		}
		delete[] adjMatrix;
		adjMatrix = nullptr;
		delete[] visited;
		visited = nullptr;
	}
	//constructor
	Graph(const Graph& g)
	{
		maxVertices = g.maxVertices;
		n = g.n;
		adjMatrix = new int* [maxVertices];
		for (int i = 0; i < maxVertices; i++)
		{
			adjMatrix[i] = new int[maxVertices];
			for (int j = 0; j < maxVertices; j++)
				adjMatrix[i][j] = g.adjMatrix[i][j];
		}
		visited = new bool[maxVertices];
		for (int i = 0; i < maxVertices; i++)
		{
			visited[i] = g.visited[i];
		}
	}

	bool addVertex(int& v)// Adds a new vertex to the graph. This function should store the number of the newly inserted vertex into the reference parameter v
	{
		if (n >= maxVertices)
		{
			cout << "matrix is full" << endl;
			return false;
		}
		v = n;
		for (int i = 0; i < maxVertices; i++)
		{
			adjMatrix[v][i] = 0;
			adjMatrix[i][v] = 0;
		}
		visited[v] = false;
		n++;
		return true;
	}
	bool addEdge(int u, int v, int weight) // Adds the edge <u,v> to the graph
	{
		if (u < 0 || v < 0 || u >= n || v >= n)
		{
			return false;
		}

		adjMatrix[u][v] = weight;
		adjMatrix[v][u] = weight;

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
	bool isEmpty()
	{
		if (n == 0)
		{
			return true;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (adjMatrix[i][j] != 0)
					return false;
			}
		}
		return true;
	}
	bool isComplete()
	{
		if (n <= 1)
			return true;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j && adjMatrix[i][j] == 0)
					return false;
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
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	int Degree(int v)//This function will determine and return the degree of the vertex v.It will return ?1 if v is invalid.
	{
		if (v < 0 || v >= n)
		{
			return -1;
		}

		int d = 0;

		for (int j = 0; j < n; j++)
		{
			if (adjMatrix[v][j] != 0)
			{
				d++;
			}
		}
		return d;
	}
	void DFS()
	{
		for (int i = 0; i < n; i++)
			visited[i] = false;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == false)
			{
				DFS(i);
			}
		}
		cout << endl;
	}
	void BFS()
	{
		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
		}
		int v;
		cout << "enter the vertex from where you want to traverse: ";
		cin >> v;
		if (v < 0 || v >= n)
		{
			cout << "enter vertex is not in graph " << endl;
			return;
		}
		Queue<int> q;
		q.enqueue(v);
		visited[v] = true;
		while (!q.isEmpty())
		{
			int node = q.dequeue();
			cout << node << endl;
			for (int i = 0; i < n; i++)
			{
				if (adjMatrix[node][i] != 0 && visited[i] == false)
				{
					visited[i] = true;
					q.enqueue(i);
				}

			}

		}
	}
	/*Graph MST()
	{
		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
		}
		int v;
		cout << "enter the vertex from where you want to traverse: ";
		cin >> v;
		if (v < 0 || v >= n)
		{
			cout << "enter vertex is not in graph " << endl;
			return;
		}
		int* key = new int[n] {INF};
		key[v] = 0;
		PQueue* par = new PQueue[n]{ NULL };
		par->enqueue(v);
		while (!par->isempty())
		{
			int temp = par->getfront();
			par->dequeue();
			cout << temp

		}
	}*/
	void MST() {
		int v;
		cout << "Enter the starting vertex: ";
		cin >> v;

		int* key = new int[n];
		int* parent = new int[n];
		bool* visited = new bool[n];

		for (int i = 0; i < n; i++) {
			key[i] = INF;
			visited[i] = false;
			parent[i] = -1;
		}

		PQueue pq(n); // Using the modified Heap
		key[v] = 0;
		pq.enqueue(v, 0); // (Vertex, Weight)

		while (!pq.isempty()) {
			Node temp = pq.dequeue();;

			int u = temp.vertex;

			if (visited[u]) continue;
			visited[u] = true;

			// Traverse neighbors in Adjacency Matrix
			for (int neighbor = 0; neighbor < n; neighbor++) {
				int weight = adjMatrix[u][neighbor];

				// If edge exists and neighbor is not in MST
				if (weight != 0 && weight != INF && !visited[neighbor]) {
					if (weight < key[neighbor]) {
						key[neighbor] = weight;
						parent[neighbor] = u;
						pq.enqueue(neighbor, key[neighbor]);
					}
				}
			}
		}

		// Print the MST
		cout << "\nEdge \tWeight" << endl;
		for (int i = 0; i < n; i++) {
			if (parent[i] != -1)
				cout << parent[i] << " - " << i << " \t" << key[i] << endl;
		}
	}

	void Dijsktra() {
		int v;
		cout << "Enter the starting vertex: ";
		cin >> v;

		int* key = new int[n];
		int* parent = new int[n];
		bool* visited = new bool[n];

		for (int i = 0; i < n; i++) {
			key[i] = INF;
			visited[i] = false;
			parent[i] = -1;
		}

		PQueue pq(n); // Using the modified Heap
		key[v] = 0;
		pq.enqueue(v, 0); // (Vertex, Weight)

		while (!pq.isempty()) {
			Node temp = pq.dequeue();;

			int u = temp.vertex;

			if (visited[u]) continue;
			visited[u] = true;

			// Traverse neighbors in Adjacency Matrix
			for (int neighbor = 0; neighbor < n; neighbor++) {
				int weight = adjMatrix[u][neighbor];

				// If edge exists and neighbor is not in MST
				if (weight != 0 && weight != INF && !visited[neighbor]) {
					if (key[u]+weight < key[neighbor]) {
						key[neighbor] = weight+key[u];
						parent[neighbor] = u;
						pq.enqueue(neighbor, key[neighbor]);
					}
				}
			}
		}

		// Print the Dijsktra
		cout << "\nEdge \tWeight" << endl;
		for (int i = 0; i < n; i++) {
			if (parent[i] != -1)
				cout << parent[i] << " - " << i << " \t" << key[i] << endl;
		}
	}
	
};

int main() {
	int maxV = 5;
	Graph g(maxV, 0); // Create empty graph with max 5 vertices

	cout << "Adding vertices...\n";
	int v;
	for (int i = 0; i < 4; i++) {
		if (g.addVertex(v)) {
			cout << "Vertex added: " << v << endl;
		}
	}

	cout << "\nAdding edges...\n";
	g.addEdge(0, 1,5);
	g.addEdge(0, 2,7);
	g.addEdge(1, 3,2);
	g.addEdge(2, 3,4);

	cout << "\nAdjacency Matrix:\n";
	g.display();

	cout << "\nDFS traversal:\n";
	g.DFS();

	cout << "\nBFS traversal:\n";
	g.BFS();

	cout << "\nDegrees of vertices:\n";
	for (int i = 0; i < 4; i++) {
		cout << "Degree of vertex " << i << " = " << g.Degree(i) << endl;
	}

	/*cout << "\nRemoving edge (0,2)...\n";
	g.removeEdge(0, 2);
	g.display();

	cout << "\nClearing all edges...\n";
	g.clear();
	g.display();

	cout << "\nIs graph empty? " << (g.isEmpty() ? "Yes" : "No") << endl;*/
	cout << "Is graph complete? " << (g.isComplete() ? "Yes" : "No") << endl;
 g.MST();
 cout << "_________________________________" << endl << endl;
 g.Dijsktra();

	return 0;
}
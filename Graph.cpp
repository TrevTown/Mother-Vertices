#include <iostream>

#include "Graph.h"

using namespace std;



Graph::Graph(int vertices)

{

	this->numVertices = vertices;

	adjacents = new list<int>[numVertices];

}



void Graph::addEdge(int vertex, int adjacentVertex)

{

	adjacents[vertex].push_back(adjacentVertex);

	// adjacents[adjacentVertex].push_back(vertex);// this statement makes the graph undirected. 

}



void Graph::BFS(int start)

{

	bool* visited = new bool[numVertices];

	for (int i = 0; i < numVertices; i++)

	{

		visited[i] = false;

	}

	list <int> queue;



	visited[start] = true;

	queue.push_back(start);



	while (!queue.empty())

	{

		start = queue.front();

		cout << start << " ";

		queue.pop_front();



		for (auto vertex : adjacents[start])

		{

			if (!visited[vertex])

			{

				visited[vertex] = true;

				queue.push_back(vertex);

			}

		}

	}

}

// I worked on this for quite a while without consulting Google. But due to time, I pulled this code off of GeeksforGeeks at: https://www.geeksforgeeks.org/check-given-directed-graph-strongly-connected-set-2-kosaraju-using-bfs/

bool Graph::isStronglyConnected()

{

	bool* visited = new bool[numVertices];

	for (int i = 0; i < numVertices; i++)

	{

		visited[i] = false;

	}

	BFSUtil(0, visited);

	

	for (int i = 0; i < numVertices; ++i)

	{

		if (visited[i] == false)

		{

			return false;

		}

	}

	Graph gr = getTranspose();

	for (int i = 0; i < numVertices; ++i)

	{

		visited[i] = false;

	}

	gr.BFSUtil(0, visited);

	for (int i = 0; i < numVertices; ++i)

	{

		if (visited[i] == false)

		{

			return false;

		}

	}

	return true;

}

void Graph:: BFSUtil(int v, bool visited[])

{

	list<int> queue;

	visited[v] = true;

	queue.push_back(v);



	list<int>::iterator i;



	while (!queue.empty())

	{

		v = queue.front();

		queue.pop_front();

		for (i = adjacents[v].begin(); i != adjacents[v].end(); ++i)

		{

			if (!visited[*i])

			{

				visited[*i] = true;

				queue.push_back(*i);

			}

		}

	}

}

Graph Graph::getTranspose()

{

	Graph g(numVertices);

	for (int v = 0; v < numVertices; ++v)

	{

		list<int>::iterator i;

		for (i = adjacents[v].begin(); i != adjacents[v].end(); ++i)

		{

			g.adjacents[*i].push_back(v);

		}	

	}

	return g;

}

bool Graph::isWeaklyConnected()

{

	Graph g(numVertices); // created a separate adjacency list 

	for (int v = 0; v < numVertices; ++v)

	{

		list<int>::iterator i;

		for (i = adjacents[v].begin(); i != adjacents[v].end(); ++i)

		{

			g.adjacents[*i].push_back(v);

			g.adjacents[v].push_back(*i); // this replaces directed edges with undirected edges

		}

	}

	bool* visited = new bool[numVertices];

	for (int i = 0; i < numVertices; i++)

	{

		visited[i] = false;

	}

	BFSUtil(0, visited);



	for (int i = 0; i < numVertices; ++i)

	{

		if (visited[i] == false)

		{

			return false;

		}

	}

	Graph gr = getTranspose();

	for (int i = 0; i < numVertices; ++i)

	{

		visited[i] = false;

	}

	gr.BFSUtil(0, visited);

	for (int i = 0; i < numVertices; ++i)

	{

		if (visited[i] == false)

		{

			return false;

		}

	}

	return true;

}

// This code was also pulled from Geeks for Geeks at:https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

// 

std::vector<int> Graph::motherVertices()

{

	vector<bool> visited(numVertices, false);



	// To store last finished vertex (or mother vertex) 

	vector<int> * motherVertexArray = new vector<int>;

	int v = 0;

	// Do a DFS traversal and find the last finished 

	// vertex   

	for (int i = 0; i < numVertices; i++)

	{

		if (visited[i] == false)

		{

			DFSUtil(i, visited);

			v = i;

		}

	}



	// If there exist mother vertex (or vertices) in given 

	// graph, then v must be one (or one of them) 



	// Now check if v is actually a mother vertex (or graph 

	// has a mother vertex).  We basically check if every vertex 

	// is reachable from v or not. 



	// Reset all values in visited[] as false and do  

	// DFS beginning from v to check if all vertices are 

	// reachable from it or not. 

	fill(visited.begin(), visited.end(), false);

	DFSUtil(v, visited);

	for (int i = 0; i < numVertices; i++)

	{

		if (visited[i] == false)

		{

			return motherVertexArray[v];

		}

	}

	return motherVertexArray[v];

}

void Graph::DFSUtil(int v, vector<bool> &visited)

{

	// Mark the current node as visited and print it 

	visited[v] = true;



	// Recur for all the vertices adjacent to this vertex 

	list<int>::iterator i;

	for (i = adjacents[v].begin(); i != adjacents[v].end(); ++i)

	{

		if (!visited[*i])

		{

			DFSUtil(*i, visited);

		}

	}

}

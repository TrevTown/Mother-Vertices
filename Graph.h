#ifndef GRAPH_H

#define GRAPH_H

#include <list>

#include<vector>



class Graph

{

public:

	Graph(int vertices);



	void addEdge(int vertex, int adjacentVertex);

	

	void BFS(int start);

	bool isStronglyConnected();

	bool isWeaklyConnected();

	

	Graph getTranspose();

	int numVertices;

	std::vector<int> motherVertices();



private:

	void BFSUtil(int, bool[]);

	void DFSUtil(int v, std::vector<bool> &visited);

	std::list<int>* adjacents;

	

};

#endif // !GRAPH_H

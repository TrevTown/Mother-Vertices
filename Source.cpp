#include "Graph.h"

#include <string>

#include <iostream>

#include <vector>



int main()

{

	const int NUMNODES = 5;

	Graph graph(NUMNODES);

	std::vector<int> motherVec;

	

	graph.addEdge(0, 1);

	graph.addEdge(1, 2);

	graph.addEdge(0, 2);

    graph.addEdge(3, 0);

	graph.addEdge(2, 4);

//	graph.addEdge(4, 2);

	graph.BFS(1);

	std::cout << std:: endl;

	if (graph.isStronglyConnected())

	{

		std::cout << "Graph is Strongly Connected" << std::endl;

	}

	else

	{

		std::cout << "Graph is not Strongly Connected" << std::endl;	

	}



	if (graph.isWeaklyConnected())

	{

		std::cout << "Graph is Weakly Connected" << std::endl;

	}

	else

	{

		std::cout << "Graph is not Weakly Connected" << std::endl;

	}



	system("PAUSE");

	return 0;

}

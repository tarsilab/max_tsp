#include "baseline.h"
#include <limits>
#include <utility>
#include <iostream>

void furthestNeighbor(Graph &g, int source) {
	int numVertices = g.getNumVertices();
	int visitedVertices = 0;
	int newSource = 0;
	std::vector < std::vector < std::pair<int, int> > > adjList = g.getAdjList();
	std::vector<bool> visited(numVertices);

	visitedVertices = 1;
	int sum = 0;

	while (visitedVertices != numVertices) {
		int large = std::numeric_limits<int>::min();
		//std::cout << (source + 1) << " -> ";
		visited[source] = true;
		
		for (auto &i : adjList[source]) {
			if (i.second > large && (visited[i.first] == false)) {
				large = i.second;
				newSource = i.first;
			
			}
		}

		if (source == newSource) {
			//std::cout << "Couldn't find an hamiltonian cycle";
			sum = 0;
			break;
		}
		
		sum += large;
		source = newSource;
		visitedVertices++;
	}  

	//std::cout << (source + 1) << "\n";
	std::cout << sum << "\n";

}
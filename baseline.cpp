#include "baseline.h"
#include <set>
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

void greedy(Graph &g) {
	int numVertices = g.getNumVertices();
	std::vector < std::vector < std::pair<int, int> > > adjList = g.getAdjList();
	std::vector <int> degrees(numVertices, 0); 
	std::set < std::pair<int, std::pair<int, int> > > heap;
	int sum = 0;

	for (int i = 0; i < numVertices; ++i) {
		for (auto &j : adjList[i]) {
			heap.insert(std::make_pair(j.second, std::make_pair(i, j.first)));
		}
	}

	while (!heap.empty()) {
		std::pair < int, std::pair<int, int> > currentEdge = *(heap.rbegin());
		//std::cout << currentEdge.first << "\n";
		heap.erase(std::prev(heap.end()));
		
		if (degrees[currentEdge.second.second] < 2 && degrees[currentEdge.second.first] < 2) {
			degrees[currentEdge.second.first]++;
			degrees[currentEdge.second.second]++;
			//std::cout << currentEdge.second.first + 1 << " " << currentEdge.second.second + 1 << " " << currentEdge.first << "\n";
			sum += currentEdge.first;
		}
		
	}

	std::cout << sum << "\n";
}
#include "baseline.h"
#include <set>
#include <limits>
#include <utility>
#include <iostream>

void furthestNeighbor(Graph &g, int source) {
	int original_source = source;
	int numVertices = g.getNumVertices();
	int visitedVertices = 0;
	int newSource = 0;
	std::vector < std::vector < std::pair<int, int> > > adjList = g.getAdjList();
	std::vector<bool> visited(numVertices);

	visitedVertices = 1;
	int sum = 0;

	while (visitedVertices != numVertices) {
		int large = std::numeric_limits<int>::min();
		visited[source] = true;
		
		for (auto &i : adjList[source]) {
			if (i.second > large && (visited[i.first] == false)) {
				large = i.second;
				newSource = i.first;
			}
		}

		if (source == newSource) {
			sum = 0;
			break;
		}
		
		sum += large;
		source = newSource;
		visitedVertices++;
	}  

	if (sum != 0) {
		for (auto &i : adjList[source])	if (i.first == original_source) sum += i.second;
	}
	std::cout << sum << "\n";

}

void greedy(Graph &g) {
	int numVertices = g.getNumVertices();
	std::vector < std::vector < std::pair<int, int> > > adjList = g.getAdjList();
	std::vector<int> degree(numVertices, 0);
	std::set < std::pair<int, std::pair<int, int> > > heap;
	int sum = 0;

	for (int i = 0; i < numVertices; ++i) {
		for (auto &j : adjList[i]) {
			if (j.first > i) heap.insert(std::make_pair(j.second, std::make_pair(i, j.first)));
		}
	}

	//for (auto &i : heap) std::cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
	int currColor = 0;
	std::vector<int> colors(numVertices, -1);
	int numEdges = 0;

	bool hasCycle = false;

	while (!heap.empty()) {
		std::pair < int, std::pair<int, int> > currentEdge = *(heap.rbegin());
		heap.erase(std::prev(heap.end()));

		if (numEdges == numVertices - 1) {
			if (degree[currentEdge.second.second] == 1 && degree[currentEdge.second.first] == 1) {
				sum += currentEdge.first;
				numEdges++;			
				hasCycle = true;	
			}
		}

		if ((degree[currentEdge.second.second] < 2 && degree[currentEdge.second.first] < 2) && (numEdges < numVertices - 1)) { 
			if (colors[currentEdge.second.first] == -1 && colors[currentEdge.second.second] == -1) {
				degree[currentEdge.second.second]++;
				degree[currentEdge.second.first]++;
				colors[currentEdge.second.first] = currColor;
				colors[currentEdge.second.second] = currColor;
				currColor++;
				numEdges++;
				sum += currentEdge.first;
			}	

			else if (colors[currentEdge.second.first] == -1) {
				degree[currentEdge.second.second]++;
				degree[currentEdge.second.first]++;
				colors[currentEdge.second.first] = colors[currentEdge.second.second];
				sum += currentEdge.first;
				numEdges++;
			}

			else if (colors[currentEdge.second.second] == -1) {
				degree[currentEdge.second.second]++;
				degree[currentEdge.second.first]++;
				colors[currentEdge.second.second] = colors[currentEdge.second.first];
				sum += currentEdge.first;
				numEdges++;
			}

			else if (colors[currentEdge.second.second] != colors[currentEdge.second.first]) {
				degree[currentEdge.second.second]++;
				degree[currentEdge.second.first]++;
				colors[currentEdge.second.second] = colors[currentEdge.second.first];
				sum += currentEdge.first;
				numEdges++;	
			}
		}
	}

	if (!hasCycle) sum = 0;
	std::cout << sum << "\n";
}
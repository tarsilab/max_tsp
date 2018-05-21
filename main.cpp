#include <iostream>
#include "graph.h"
#include "baseline.h"

int main() {

	long long source, destination, time;
	int weight;
	int vertices;

	std::cin >> vertices;

	Graph graph(vertices);

	while (std::cin >> source >> destination >> weight) {
		graph.addEdge(source - 1, destination - 1, weight);
	}

	//graph.printGraph();
	
	furthestNeighbor(graph, 0);
	//std::cout << "\n";

	greedy(graph);
	return 0;
}  
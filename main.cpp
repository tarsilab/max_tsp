#include <iostream>

#include "graph.h"

int main() {

	long long source, destination, time;
	int weight;

	
	Graph graph(7604);

	while (std::cin >> source >> destination >> weight >> time) {
		//std::cout << source << " " << destination << " " << weight << "\n";
		graph.addEdge(source - 1, destination - 1, weight);
	}

	graph.printGraph();
	
	return 0;
}  
#include "graph.h"
#include <iostream>

Graph::Graph(long long v): adj_list(v) {
	num_vertices = v;
	num_edges = 0;
}

Graph::~Graph() {}

void Graph::addEdge(long long s, long long d, int w) {
	adj_list[s].push_back(std::make_pair(d, w));
	num_edges++;
}

/* Function created just for debugging. */
void Graph::printGraph() {
	for (int i = 0; i < this->num_vertices; ++i) {
		std::cout << i + 1 << " -> ";
		for (auto &j : this->adj_list[i]) {
			std::cout << "{" << j.first + 1 << "," << j.second << "} ";
		}
		std::cout << "\n";
	}
}

std::vector < std::vector< std::pair<long long, long long> > > Graph::getAdjList() {
	return adj_list;
}

long long Graph::getNumVertices() {
	return num_vertices;
}

long long Graph::getNumEdges() {
	return num_edges;
}
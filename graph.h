#include <vector>
#include <utility>

#ifndef GRAPH_H
#define GRAPH_H

class Graph {

	long long num_vertices;
	long long num_edges;
	std::vector < std::vector< std::pair<long long, long long> > > adj_list;

	public:
		Graph(long long v);
		~Graph();
		void addEdge(long long s, long long d, int w);
		void printGraph();	
		std::vector < std::vector< std::pair<long long, long long> > > getAdjList();
		long long getNumVertices();
		long long getNumEdges();
};

#endif
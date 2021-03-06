#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <fstream>
#include <sstream>

/* Find minimum distance value from vertices not yet checked */
int minDistance(std::vector<int> dist, std::vector<bool> sptSet)
{
	int min = INT_MAX;
	int min_index = -1;

	for (uint v = 0; v < dist.size(); v++) {
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}

	return min_index;
}

/* Dijkstra's algorithm from an adjacency matrix */
int dijkstra(std::vector<std::vector<int>> graph, int src)
{
	/* The output array.  dist[i] will hold the shortest distance from src to i */
	std::vector<int> dist(graph.size(), INT_MAX);

	/* sptSet[i] will true if vertex i is included in shortest path tree or
	 * shortest distance from src to i is finalized */
	std::vector<bool> sptSet(graph.size(), false);

	dist[src] = 0; // Distance of source vertex from itself is always 0

	/* Find shortest path for all vertices */
	for (uint count = 0; count < graph.size() - 1; count++) {
		/* Pick the minimum distance vertex from the set of vertices not
		 * yet processed. (src == u in first iteration) */
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		/* Update dist value of the adjacent vertices of the picked vertex. */
		for (uint v = 0; v < graph.size(); v++) {
			/* Update dist[v] only if is not in sptSet, there is an edge from
			 * u to v, and total weight of path from src to v through u is
			 * smaller than current value of dist[v] */
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
			    && dist[u]+graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}

	return dist[dist.size() - 1];
}

int main()
{
	std::ifstream nums_file("assets/p083_matrix.txt");
	std::vector<std::vector<int>> nums;
	std::string line;
	while (std::getline(nums_file, line)) {
		std::stringstream tmp(line);
		std::vector<int> num_line;
		std::string num_str;
		while (std::getline(tmp, num_str, ',')) {
			num_line.push_back(std::stoi(num_str));
		}
		nums.push_back(num_line);
	}

	std::vector<std::vector<int>> graph(nums.size() * nums.size(), std::vector<int>(nums.size() * nums.size(), 0));

	/* Build adjacency matrix from initial grid */
	for (uint i = 0; i < nums.size(); i++) {
		for (uint j = 0; j < nums[i].size(); j++) {
			if (j % nums.size() != nums.size() - 1) {
				graph[nums.size() * i + j][nums.size() * i + j + 1] = nums[i][j];
			}
			if (j % nums.size() != 0) {
				graph[nums.size() * i + j][nums.size() * i + j - 1] = nums[i][j];
			}
			if (i % nums.size() != nums.size() - 1) {
				graph[nums.size() * i + j][nums.size() * i + j + nums.size()] = nums[i][j];
			}
			if (i % nums.size() != 0) {
				graph[nums.size() * i + j][nums.size() * i + j - nums.size()] = nums[i][j];
			}
		}
	}

	int dist = dijkstra(graph, 0);
	std::cout << "Minimal path sum from top-left to bottom-right: ";
	std::cout << dist + nums[nums.size() - 1][nums.size() - 1] << std::endl;
	return 0;
}

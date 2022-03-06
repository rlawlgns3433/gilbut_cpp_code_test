#pragma once
#include <iostream>
#include "kruscal.h"
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<unsigned, string> color_map{
	{1, "RED"},{2, "BLUE"},{3, "GREEN"},
	{4, "YELLOW"},{5, "BLACK"},{6, "WHITE"}
};

template<typename T>
auto greedy_coloring(const Graph<T>& G) {
	auto size = G.vertices();
	vector<unsigned> assigned_colors(size);

	for (unsigned i = 1; i < size; i++) {
		auto outgoing_edges = G.edges(i);
		
		set<unsigned> neighbours;

		for (auto& e : outgoing_edges)
			neighbours.insert(assigned_colors[e.dst]);

		auto smallest = 1;
		for (; smallest <= color_map.size(); smallest++) {
			if (neighbours.find(smallest) == neighbours.end())
				break;
		}

		assigned_colors[i] = smallest;
	}
	return assigned_colors;
}

template<typename T>
void print_colors(vector<T>& colors) {
	for (auto i = 1; i < colors.size(); i++) {
		cout << i << ": " << color_map[colors[i]] << endl;
	}
}

int main()
{
	using T = unsigned;
	Graph<T> G(9);

	map<unsigned, vector<pair<unsigned, T>>> edge_map;
	edge_map[1] = { {2,0},{5,0} };
	edge_map[2] = { {1,0},{5,0 },{4,0} };
	edge_map[3] = { {4,0},{7,0} };
	edge_map[4] = { {2,0},{3,0},{5,0},{6,0},{8,0} };
	edge_map[5] = { {1,0},{2,0},{4,0},{8,0} };
	edge_map[6] = { {4,0},{7,0},{8,0} };
	edge_map[7] = { {3,0},{6,0} };
	edge_map[8] = { {4,0},{5,0},{6,0} };

	for (auto& i : edge_map)
		for (auto& j : i.second)
			G.add_edge(Edge<T>{i.first, j.first, j.second});

	cout << "[입력 그래프]" << endl;
	cout << G << endl;

	auto colors = greedy_coloring<T>(G);
	cout << "[그래프 컬러링]" << endl;
	print_colors(colors);
}
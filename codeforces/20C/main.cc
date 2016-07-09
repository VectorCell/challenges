/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 3 - Codeforces 20C
 * 
 * compile for C++11
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#include <cstdio>

using namespace std;

typedef struct edge_type {
	int dest;
	int weight;
} edge_type;
typedef vector<vector<edge_type>> graph_type;

int get_dest (const edge_type& e)
{
	return e.dest;
}

int get_weight (const edge_type& e)
{
	return e.weight;
}

edge_type make_edge(int node, int weight)
{
	edge_type e;
	e.dest = node;
	e.weight = weight;
	return e;
}

int get_vertex_name (int v)
{
	return v + 1;
}

// order edges by weight, from smallest to largest
bool edge_less_weight (const edge_type& a, const edge_type& b)
{
	return get_weight(a) < get_weight(b);
}

//void print_graph (const graph_type& g)
//{
//	for (size_t v = 0; v < g.size(); ++v) {
//		printf("%lu :: ", v);
//		for (size_t e = 0; e < g[v].size(); ++e) {
//			printf("(%d, %d) ", get_dest(g[v][e]), get_weight(g[v][e]));
//		}
//		printf("\n");
//	}
//}

bool find_best_path (graph_type& g, vector<int>& path, int src, int dest)
{
	vector<int> from(g.size(), -1);
	vector<bool> visited(g.size(), false);
	vector<int> dist(g.size(), (unsigned int)(-1) >> 1);
	dist[src] = 0;
	set<pair<int,int>> act;
	act.insert({0, src});
	while (act.size() > 0) {
		int where = act.begin()->second;
		visited[where] = true;
		if (where == dest) {
			int v = dest;
			while (v != src) {
				path.push_back(v);
				v = from[v];
			}
			path.push_back(src);
			reverse(path.begin(), path.end());
			return true;
		}
		act.erase(act.begin());
		for (edge_type& e : g[where]) {
			if (!visited[get_dest(e)]) {
				if (dist[get_dest(e)] > dist[where] + get_weight(e)) {
					from[get_dest(e)] = where;
					act.erase({dist[get_dest(e)], get_dest(e)});
					dist[get_dest(e)] = dist[where] + get_weight(e);
					act.insert({dist[get_dest(e)], get_dest(e)});
				}
			}
		}
	}
	return false;
}

int main (int argc, char *argv[])
{
	int n_vertices, n_edges;
	cin >> n_vertices >> n_edges;
	graph_type graph(n_vertices);
	for (int edge = 0; edge < n_edges; ++edge) {
		int a, b, w;
		cin >> a >> b >> w;
		--a;
		--b;
		graph[a].push_back(make_edge(b, w));
		graph[b].push_back(make_edge(a, w));
	}

	for (vector<edge_type>& edges : graph) {
		sort(edges.begin(), edges.end(), edge_less_weight);
	}

	vector<int> path;
	if (find_best_path(graph, path, 0, n_vertices - 1)) {
		for (auto& v : path) {
			cout << get_vertex_name(v) << " ";
		}
		cout << endl;
	} else {
		cout << "-1" << endl;
	}

	return 0;
}

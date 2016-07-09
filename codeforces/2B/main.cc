/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 6 - Codeforces 2B
 * 
 * compile for C++11
 */

#include <iostream>
#include <list>
#include <vector>

#include <cstdio>

using namespace std;

typedef vector<int> row_type;
typedef vector<row_type> matrix_type;

int n_factor_n (int x, int n)
{
	int n_factor = 0;
	while (x % n == 0) {
		x /= n;
		++n_factor;
	}
	return n_factor;
}

int n_factor_2 (int x)
{
	return n_factor_n(x, 2);
}

int n_factor_5 (int x)
{
	return n_factor_n(x, 5);
}

int pair_min(const pair<int,int>& p) {
	if (p.first <= p.second) {
		return p.first;
	} else {
		return p.second;
	}
}

int pair_max(const pair<int,int>& p) {
	if (pair_min(p) == p.first) {
		return p.second;
	} else {
		return p.first;
	}
}

void build_path(const matrix_type& m, list<char>& path)
{

}

int solve (matrix_type& m, list<char>& path)
{
	const int last = (int)m.size() - 1;

	vector<vector<pair<char,char>>> opt(m.size(), vector<pair<char,char>>(m.size(), make_pair('-','-')));
	vector<vector<pair<int,int>>> over(m.size(), vector<pair<int,int>>(m.size()));

	bool has_zero = false;
	int zero_x = -1;
	int zero_y = -1;
	for (int x = 0; x < (int)m.size(); ++x) {
		for (int y = 0; y < (int)m[x].size(); ++y) {
			if (m[x][y] == 0) {
				has_zero = true;
				zero_x = x;
				zero_y = y;
				m[x][y] = 10;
			}
		}
	}

	over[0][0] = make_pair(n_factor_2(m[0][0]), n_factor_5(m[0][0]));

	// first column and row
	for (int k = 1; k < (int)m.size(); ++k) {
		over[0][k] = make_pair(n_factor_2(m[0][k]), n_factor_5(m[0][k]));
		over[0][k].first += over[0][k-1].first;
		over[0][k].second += over[0][k-1].second;
		over[k][0] = make_pair(n_factor_2(m[k][0]), n_factor_5(m[k][0]));
		over[k][0].first += over[k-1][0].first;
		over[k][0].second += over[k-1][0].second;
		opt[0][k].first = opt[0][k].second = 'R';
		opt[k][0].first = opt[k][0].second = 'D';
	}

	for (int x = 1; x < (int)m.size(); ++x) {
		for (int y = 1; y < (int)m[x].size(); ++y) {
			int p2_0 = over[x][y-1].first;
			int p5_0 = over[x][y-1].second;
			int p2_1 = over[x-1][y].first;
			int p5_1 = over[x-1][y].second;
			int c2 = n_factor_2(m[x][y]);
			int c5 = n_factor_5(m[x][y]);
			p2_0 += c2;
			p2_1 += c2;
			p5_0 += c5;
			p5_1 += c5;
			if (p2_0 < p2_1) {
				over[x][y].first = p2_0;
				opt[x][y].first = 'R';
			} else {
				over[x][y].first = p2_1;
				opt[x][y].first = 'D';
			}
			if (p5_0 < p5_1) {
				over[x][y].second = p5_0;
				opt[x][y].second = 'R';
			} else {
				over[x][y].second = p5_1;
				opt[x][y].second = 'D';
			}
		}
	}

	int cost = pair_min(over[last][last]);
	bool route_2 = (over[last][last].first < over[last][last].second);



//	printf("\n");
//	for (int x = 0; x <= last; ++x) {
//		for (int y = 0; y <= last; ++y) {
//			printf("%5d", m[x][y]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for (int x = 0; x <= last; ++x) {
//		for (int y = 0; y <= last; ++y) {
//			printf("[%d %d] ", over[x][y].first, over[x][y].second);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("%s\n", route_2 ? "route for 2" : "route for 5");
//	for (int x = 0; x <= last; ++x) {
//		for (int y = 0; y <= last; ++y) {
//			printf("%c ", route_2 ? opt[x][y].first : opt[x][y].second);
//		}
//		printf("\n");
//	}
//	printf("\n");



	// there is a zero and the min cost is not zero
	if (has_zero && cost > 0) {
		cost = 1;
		for (int k = 0; k < zero_x; ++k) {
			path.push_back('D');
		}
		for (int k = 0; k < zero_y; ++k) {
			path.push_back('R');
		}
		for (int k = 0; k < last - zero_x; ++k) {
			path.push_back('D');
		}
		for (int k = 0; k < last - zero_y; ++k) {
			path.push_back('R');
		}
	} else {
		int x, y;
		x = y = last;
		while (x >= 0 && y >= 0) {
			char ch = (route_2 ? opt[x][y].first : opt[x][y].second);
			path.push_front(ch);
			if (ch == 'D') {
				--x;
			} else {
				--y;
			}
		}
		path.pop_front();
	}

	return cost;
}

void print_answer (matrix_type& m)
{
	list<char> path;
	cout << solve(m, path) << endl;
	for (char ch : path)
		cout << ch;
	cout << endl;
}

int main (int argc, char *argv[])
{
	int n;
	cin >> n;
	matrix_type m(n, row_type(n));
	for (int x = 0; x < (int)m.size(); ++x) {
		for (int y = 0; y < (int)m[x].size(); ++y) {
			cin >> m[x][y];
		}
	}
	print_answer(m);

	return 0;
}

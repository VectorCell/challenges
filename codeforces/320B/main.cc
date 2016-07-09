/*
**  Brandon Smith
**  CS 109 - Competitive Programming - Spring 2016
**  
**  Problem Set 8 - Codeforces 320B
**  
**  compile for C++11
*/

#include <iostream>
#include <vector>
#include <utility>

#include <cstdio>
#include <cstring>

using namespace std;

typedef struct interval_struct {
	int x, y;
} interval_type;

int n_ints = 0;
interval_type ints[101];

bool paths[101][101];

void add_interval (int x, int y)
{
	++n_ints;
	ints[n_ints] = {x, y};
}

void recalculate ()
{
	int n = n_ints;
	for (int k = 1; k < n; ++k) {
		paths[n][k] = ((ints[k].x < ints[n].x) && (ints[n].x < ints[k].y)) ||
		              ((ints[k].x < ints[n].y) && (ints[n].y < ints[k].y));
		paths[k][n] = ((ints[n].x < ints[k].x) && (ints[k].x < ints[n].y)) ||
		              ((ints[n].x < ints[k].y) && (ints[k].y < ints[n].y));
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (paths[i][k] && paths[k][j]) {
					paths[i][j] = 1;
				}
			}
		}
	}
}

int main (int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<interval_type> intervals;
	for (int query = 0; query < n; ++query) {
		int type, a, b;
		cin >> type >> a >> b;
		if (type == 2) {
			cout << (paths[a][b] ? "YES" : "NO") << endl;
		} else {
			add_interval(a, b);
			recalculate();
		}
	}
	return 0;
}

/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 2 - Codeforces 378C
 * 
 * compile for C++11
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdint>

using namespace std;

typedef vector<vector<char>> maze_type;

void clear_island (maze_type& m, int x, int y)
{
	for (int off_x = -1; off_x <= 1; ++off_x) {
		if ((x + off_x) >= 0 && (x + off_x) < (int)m.size()) {
			for (int off_y = -1; off_y <= 1; ++off_y) {
				if ((y + off_y) >= 0 && (y + off_y) < (int)m[x].size()) {
					if (m[x + off_x][y + off_y] == '.') {
						m[x + off_x][y + off_y] = ' ';
						clear_island(m, x + off_x, y + off_y);
					}
				}
			}
		}
	}
}

bool is_continuous (maze_type& m)
{
	uint32_t n_islands = 0;
	for (int x = 0; x < (int)m.size(); ++x) {
		for (int y = 0; y < (int)m[x].size(); ++y) {
			if (m[x][y] == '.') {
				m[x][y] = ' ';
				clear_island(m, x, y);
				++n_islands;
			}
		}
	}
	for (int x = 0; x < (int)m.size(); ++x) {
		for (int y = 0; y < (int)m[x].size(); ++y) {
			if (m[x][y] == ' ') {
				m[x][y] = '.';
			}
		}
	}

	return n_islands == 1;
}

void add_walls (maze_type& m, int walls)
{
	int placed = 0;
	for (int x = 0; x < (int)m.size(); ++x) {
		for (int y = 0; y < (int)m[x].size(); ++y) {
			if (m[x][y] == '.') {
				m[x][y] = 'X';
				if (is_continuous(m)) {
					++placed;
					if (placed == walls) {
						return;
					}
				} else {
					m[x][y] = '.';
				}
			}
		}
	}
}

int main (int argc, char *argv[])
{
	int height, width, walls;
	cin >> height >> width >> walls;
	// skip to next line
	cin.ignore (numeric_limits<streamsize>::max(), '\n');

	maze_type maze;
	string line;
	for (int x = 0; x < height; ++x) {
		getline(cin, line);
		maze.push_back(vector<char>(width));
		for (int y = 0; y < width; ++y) {
			maze[x][y] = line[y];
		}
	}
	// BAD
	if (walls == height * width - 1) {
		for (int x = 0; x < (int)maze.size(); ++x) {
			for (int y = 0; y < (int)maze[x].size(); ++y) {
				if (x == 0 && y == 0)
					cout << '.';
				else
					cout << 'X';
			}
			cout << endl;
		}
		return 0;
	}
	if (walls > 0) {
		add_walls(maze, walls);
	}
	for (int x = 0; x < (int)maze.size(); ++x) {
		for (int y = 0; y < (int)maze[x].size(); ++y) {
			cout << maze[x][y];
		}
		cout << endl;
	}

	return 0;
}

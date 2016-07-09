/*
**  Brandon Smith
**  CS 109 - Competitive Programming - Spring 2016
**  
**  Problem Set 13 - Codeforces 52B
**  
**  compile for C++11
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

#include <cstdint>

using namespace std;

const char VERTEX = '*';

uint64_t solve (const vector<vector<char>>& m)
{
	vector<int> row_cnt(m.size());
	vector<int> col_cnt(m[0].size());
	for (size_t row = 0; row < m.size(); ++row) {
		for (size_t col = 0; col < m[row].size(); ++col) {
			if (m[row][col] == VERTEX) {
				++row_cnt[row];
			}
		}
	}
	for (size_t col = 0; col < m[0].size(); ++col) {
		for (size_t row = 0; row < m.size(); ++row) {
			if (m[row][col] == VERTEX) {
				++col_cnt[col];
			}
		}
	}

	uint64_t ans = 0;
	for (size_t row = 0; row < m.size(); ++row) {
		for (size_t col = 0; col < m[row].size(); ++col) {
			if (m[row][col] == VERTEX) {
				ans += (row_cnt[row] - 1) * (col_cnt[col] - 1);
			}
		}
	}
	return ans;
}

int main (int argc, char *argv[])
{
	int rows, cols;
	cin >> rows >> cols;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<char>> m(rows, vector<char>(cols));
	for (int row = 0; row < rows; ++row) {
		string line;
		getline(cin, line);

		for (int col = 0; col < cols; ++col) {
			m[row][col] = line[col];
		}
	}

	cout << solve(m) << endl;
	
	return 0;
}

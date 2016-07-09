/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 4 - Codeforces 7A
 * 
 * compile for C++11
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <cstdio>
#include <cstdint>

using namespace std;

const char painted = 'B';

typedef string row_type;
typedef vector<row_type> board_type;

int get_num_strokes (const board_type& board)
{
	bool full = true;
	for (int row = 0; row < (int)board.size(); ++row) {
		for (int col = 0; col < (int)board[row].size(); ++col) {
			full = full && (board[row][col] == painted);
			if (!full)
				break;
		}
	}
	if (full)
		return 8;

	int n_strokes = 0;

	for (int row = 0; row < (int)board.size(); ++row) {
		full = true;
		for (int col = 0; col < (int)board[row].size(); ++col) {
			full = full && (board[row][col] == painted);
			if (!full)
				break;
		}
		if (full)
			++n_strokes;
		full = true;
		for (int col = 0; col < (int)board[row].size(); ++col) {
			full = full && (board[col][row] == painted);
			if (!full)
				break;
		}
		if (full)
			++n_strokes;
	}
	return n_strokes;
}

int main (int argc, char *argv[])
{
	board_type board(8);
	for (string& row : board)
		getline(cin, row);
	cout << get_num_strokes(board) << endl;
	return 0;
}

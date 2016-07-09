/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 3 - Codeforces 60B
 * 
 * compile for C++11
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdio>
#include <cstdint>

using namespace std;

typedef vector<vector<char>> layer_type;
typedef vector<layer_type> box_type;
typedef vector<int> coord_type;

const coord_type dx = {-1,  0,  0,  1,  0,  0};
const coord_type dy = { 0, -1,  0,  0,  1,  0};
const coord_type dz = { 0,  0, -1,  0,  0,  1};

//void print_box (const box_type& b)
//{
//	for (size_t layer = 0; layer < b.size(); ++layer) {
//		printf("layer %lu\n", layer);
//		printf("--------------\n");
//		for (size_t row = 0; row < b[layer].size(); ++row) {
//			for (size_t col = 0; col < b[layer][row].size(); ++col) {
//				printf("%c", b[layer][row][col]);
//			}
//			printf("\n");
//		}
//		printf("--------------\n");
//	}
//}

const char& value_at (const box_type& b, const coord_type& c)
{
	return b[c[0]][c[1]][c[2]];
}

char& value_at (box_type& b, const coord_type& c)
{
	return b[c[0]][c[1]][c[2]];
}

bool in_bounds (const box_type& b, const coord_type& c)
{
	if (c[0] < 0 || c[0] >= (int)b.size())
		return false;
	if (c[1] < 0 || c[1] >= (int)b[c[0]].size())
		return false;
	if (c[2] < 0 || c[2] >= (int)b[c[0]][c[1]].size())
		return false;
	return true;
}

bool can_travel (const box_type& b, const coord_type& c)
{
	return in_bounds(b, c) && value_at(b, c) == '.';
}

int propogate_water (box_type& b, int wr, int wc)
{
	int n_filled = 0;
	vector<coord_type> travelers = {{-1, wr, wc}};
	while (travelers.size() > 0) {
		vector<coord_type> next_gen;
		for (coord_type& t : travelers) {
			for (int k = 0; k < (int)dx.size(); ++k) {
				coord_type next_coord = {t[0] + dx[k], t[1] + dy[k], t[2] + dz[k]};
				if (can_travel(b, next_coord)) {
					++n_filled;
					value_at(b, next_coord) = 'w';
					next_gen.push_back(next_coord);
				}
			}
		}
		travelers = next_gen;
	}
	return n_filled;
}

int main (int argc, char *argv[])
{
	int n_layers, n_rows, n_cols;
	cin >> n_layers >> n_rows >> n_cols;
	
	box_type box(n_layers, layer_type(n_rows, vector<char>(n_cols)));

	for (layer_type& layer : box) {
		for (vector<char>& line : layer) {
			for (int k = 0; k < n_cols; ++k) {
				cin >> line[k];
			}
		}
	}

	int water_row, water_col;
	cin >> water_row >> water_col;
	--water_row;
	--water_col;

	cout << propogate_water(box, water_row, water_col) << endl;

	return 0;
}

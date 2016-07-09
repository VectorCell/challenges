#include <iostream>
#include <string>
#include <vector>

#include <cstdint>


using namespace std;


uint64_t permutations = 0;


// row-major order
typedef uint32_t elem_type;
typedef vector<elem_type> row_type;
typedef vector<row_type> grid_type;


void print_grid (const grid_type& grid)
{
	for (unsigned int row = 0; row < grid.size(); ++row) {
		for (unsigned int col = 0; col < grid[row].size(); ++col) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}

bool has_up (elem_type n) { return n & 1; }
bool has_right (elem_type n) { return (n >> 1) & 1; }
bool has_down (elem_type n) { return (n >> 2) & 1; }
bool has_left (elem_type n) { return (n >> 3) & 1; }

bool is_closed (const grid_type& g)
{
	for (unsigned int r = 0; r < g.size(); ++r) {
		for (unsigned int c = 0; c < g[r].size(); ++c) {
			if (has_up(g[r][c]) && (r == 0 || !has_down(g[r-1][c]))) {
				return false;
			}
			if (has_right(g[r][c]) && (c == g[r].size()-1 || !has_left(g[r][c+1]))) {
				return false;
			}
			if (has_down(g[r][c]) && (r == g.size()-1 || !has_up(g[r+1][c]))) {
				return false;
			}
			if (has_left(g[r][c]) && (c == 0 || !has_right(g[r][c-1]))) {
				return false;
			}
		}
	}
	return true;
}

void rotate (elem_type& n)
{
	n = ((n << 1) | (n >> 3)) & 0xf;
}

bool permute (grid_type& grid, unsigned int row, unsigned int col)
{
	if (row == grid.size()) {

		++permutations;

		if (is_closed(grid)) {
			return true;
		} else {
			//printf("not closed:\n");
			//print_grid(grid);
		}

	} else {

		unsigned int next_col = col + 1;
		unsigned int next_row = row;
		if (next_col == grid[row].size()) {
			next_col = 0;
			++next_row;
		}

		// no rotations
		if (permute(grid, next_row, next_col))
			return true;

		if (grid[row][col] == 0 || grid[row][col] == 0xf)
			return false;

		// one rotation
		rotate(grid[row][col]);
		if (permute(grid, next_row, next_col))
			return true;

		// two rotations
		rotate(grid[row][col]);
		if (permute(grid, next_row, next_col))
			return true;

		// three rotations
		rotate(grid[row][col]);
		if (permute(grid, next_row, next_col))
			return true;
	}

	return false;
}

bool solve_parallel (grid_type& grid)
{
	grid_type copies[4];
	bool ans[4];
	for (int k = 0; k < 4; ++k) {
		copies[k] = grid;
		ans[k] = false;
	}

	#pragma omp parallel for
	for (int k = 0; k < 4; ++k) {
		ans[k] = permute(copies[k], 0, 1);
	}

	for (int k = 0; k < 4; ++k) {
		if (ans[k])
			return true;
	}
	return false;
}

bool solve (grid_type& grid)
{
	//return solve_parallel(grid);
	return permute(grid, 0, 0);
}

int main (int argc, char *argv[])
{
	int n_rows, n_cols;
	cin >> n_rows >> n_cols;
	grid_type grid(n_rows, row_type(n_cols));
	for (int row = 0; row < n_rows; ++row) {
		for (int col = 0; col < n_cols; ++col) {
			int n;
			cin >> n;
			grid[row][col] = (elem_type)n;
		}
	}
	if (solve(grid)) {
		print_grid(grid);
	}
	cout << "This took " << permutations << " permutations." << endl;
	return 0;
}

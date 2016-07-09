/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 6 - Codeforces 166E
 * 
 * compile for C++11
 */

#include <iostream>
#include <cstdint>

using namespace std;

const int PRIME = 1000000007;
const int N_VERTICES = 4;

typedef struct {
    int64_t m[N_VERTICES][N_VERTICES];
} matrix_type;

void print_matrix (const matrix_type& m)
{
	for (int x = 0; x < N_VERTICES; ++x) {
		for (int y = 0; y < N_VERTICES; ++y) {
			printf("%ld ", m.m[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

matrix_type mmul (matrix_type a, matrix_type b)
{
    matrix_type res;
    for (int x = 0; x < N_VERTICES; ++x) {
        for (int y = 0; y < N_VERTICES; ++y) {
        	res.m[x][y] = 0;
            for (int k = 0; k < N_VERTICES; ++k) {
                res.m[x][y] += (a.m[x][k] * b.m[k][y]) % PRIME;
                res.m[x][y] %= PRIME;
            }
        }
    }
    return res;
}

void make_identity (matrix_type& m)
{
	for (int x = 0; x < N_VERTICES; ++x) {
		for (int y = 0; y < N_VERTICES; ++y) {
			m.m[x][y] = (x == y ? 1 : 0);
		}
	}
}

void make_inverse_identity (matrix_type& m)
{
	for (int x = 0; x < N_VERTICES; ++x) {
		for (int y = 0; y < N_VERTICES; ++y) {
			m.m[x][y] = (x == y ? 0 : 1);
		}
	}
}

int solve (matrix_type a, int n)
{
	matrix_type ans;
	make_identity(ans);
	while (n > 0) {
		if (n % 2 != 0) {
			ans = mmul(a, ans);
		}
		a = mmul(a, a);
		n /= 2;
	}
	return ans.m[3][3];
}

int main()
{
	int n;
	cin >> n;

    matrix_type m;
    make_inverse_identity(m);
    cout << solve(m, n) << endl;
    return 0;
}

/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 5 - Codeforces 448D
 * 
 * compile for C++11
 */

#include <iostream>
#include <cstdint>

using namespace std;

int64_t check (int64_t n, int64_t m, int64_t test)
{
	int64_t sum = 0;
	--test;
	for (int64_t k = 1; k <= n; ++k) {
		sum += min(m, test / k);
	}
	return sum;
}

int64_t solve (int64_t n, int64_t m, int64_t k)
{
	int64_t lower = 1;
	int64_t upper = n * m + 1;
	while (lower < upper) {
		int64_t test = (lower + upper) / 2;
		if (check(n, m, test) < k) {
			lower = test + 1;
		} else {
			upper = test;
		}
	}
	return --lower;
}

int main (int argc, char *argv[])
{
	int64_t n, m, k;
	cin >> n >> m >> k;
	cout << solve(n, m, k) << endl;
	return 0;
}

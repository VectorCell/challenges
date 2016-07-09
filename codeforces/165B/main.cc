/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 5 - Codeforces 165B
 * 
 * compile for C++11
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdio>
#include <cstdint>

using namespace std;

int term (int v, int k, int p)
{
	int denom = 1;
	for (int power = 0; power < p; ++power) {
		denom *= k;
	}
	return v / denom;
}

int check (int n, int k, int test)
{
	int sum = 0;
	int p = 0;
	int t;
	while ((t = term(test, k, p++)) > 0) {
		sum += t;
	}
	return sum;
}

int solve (int n, int k)
{
	int lower = 1;
	int upper = n;
	while (lower <= upper) {
		int test = (lower + upper) / 2;
		int result = check(n, k, test);
		if (result < n) {
			lower = test + 1;
		} else if (result > n) {
			upper = test - 1;
		} else {
			return test;
		}
	}
	int check_lower = check(n, k, lower);
	int check_upper = check(n, k, upper);
	if (check_lower >= n && check_upper >= n) {
		return min(lower, upper);
	} else if (check_lower >= n) {
		return lower;
	} else {
		return upper;
	}
}

int main (int argc, char *argv[])
{
	int n, k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
	return 0;
}

/*
**  Brandon Smith
**  CS 109 - Competitive Programming - Spring 2016
**  
**  Problem Set 8 - Codeforces 267A
**  
**  compile for C++11
*/

#include <iostream>
#include <algorithm>

using namespace std;

int solve (int a, int b)
{
	int min = (a < b) ? a : b;
	int max = (a < b) ? b : a;
	int count = 0;
	while (min > 0) {
		count += max / min;
		max = max % min;
		swap(min, max);
	}
	return count;
}

int main (int argc, char *argv[])
{
	int n_tests;
	cin >> n_tests;
	for (int test = 0; test < n_tests; ++test) {
		int a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}

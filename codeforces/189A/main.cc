/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 6 - Codeforces 189A
 * 
 * compile for C++11
 */

#include <iostream>

using namespace std;

int solve (const int n, const int a, const int b, const int c)
{
	// maximize x+y+z when ax+by+cz=n
	int max_ribbons = -1;
	for (int x = 0; x <= n / a; ++x) {
		for (int y = 0; y <= (n - a * x) / b; ++y) {
			int z = (n - a * x - b * y) / c;
			int len = a * x + b * y + c * z;
			int n_ribbons = x + y + z;
			if (len == n && n_ribbons > max_ribbons) {
				max_ribbons = n_ribbons;
			}
		}
	}
	return max_ribbons;
}

int main (int argc, char *argv[])
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << solve(n, a, b, c) << endl;
	return 0;
}
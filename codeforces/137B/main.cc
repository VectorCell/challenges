/*
**  Brandon Smith
**  CS 109 - Competitive Programming - Spring 2016
**  
**  Problem Set 13 - Codeforces 137B
**  
**  compile for C++11
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve (vector<int>& v)
{
	sort(v.begin(), v.end());
	const int n = static_cast<int>(v.size());
	int i = 1;
	int c = 0;
	for (const int& x : v) {
		if (i > n) {
			break;
		} else if (i == x) {
			++i;
			++c;
		} else if (i < x) {
			if (x > n) {
				break;
			} else {
				i = x + 1;
				++c;
			}
		}
	}
	return n - c;
}

int main (int argc, char *argv[])
{
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int& i : v)
			cin >> i;
		cout << solve(v) << endl;
	}
	return 0;
}

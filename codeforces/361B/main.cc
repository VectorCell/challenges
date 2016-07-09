/*
**  Brandon Smith
**  CS 109 - Competitive Programming - Spring 2016
**  
**  Problem Set 8 - Codeforces 361B
**  
**  compile for C++11
*/

#include <iostream>
#include <vector>

using namespace std;

bool solve (int n, int k, vector<int>& ans)
{
	if (n == k) {
		return false;
	} else {
		k = n - k;
		ans.push_back(k);
		for (int i = 1; i < k; ++i)
			ans.push_back(i);
		for (int i = k + 1; i <= n; ++i)
			ans.push_back(i);
		return true;
	}
}

int main (int argc, char *argv[])
{
	int n, k;
	cin >> n >> k;
	vector<int> ans;
	if (solve(n, k, ans)) {
		for (const int& n : ans)
			cout << n << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}

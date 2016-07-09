/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 7 - Codeforces 407B
 * 
 * compile for C++11
 */

#include <iostream>
#include <vector>

using namespace std;

const int PRIME = 1000000007;

int64_t solve_dp (const vector<int> p, vector<int64_t> dp)
{
	int64_t ans = -1;
	for (int i = 0; i < (int)p.size(); ++i) {
		dp[i + 1] = ++ans;
		ans = (ans + 1 + dp[i + 1] - dp[p[i]]) % PRIME;
	}
	++ans;
	ans %= PRIME;
	if (ans < 0)
		ans += PRIME;
	return ans;
}

int64_t solve (const vector<int> p)
{
	vector<int64_t> dp(p.size() + 1);
	return solve_dp(p, dp);
}

int main (int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> p(n);
	for (int& i : p) {
		cin >> i;
	}
	cout << solve(p) << endl;
}

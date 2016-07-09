/*
**  Brandon Smith
**  CS 109 - Competitive Programming - Spring 2016
**  
**  Problem Set 13 - Codeforces 26A
**  
**  compile for C++11
*/

#include <iostream>
#include <vector>

#include <cmath>

using namespace std;

vector<int> find_primes (int max_prime)
{
	vector<bool> sieve(max_prime + 1, true);
	sieve[0] = sieve[1] = false;
	size_t top = (size_t)sqrt(sieve.size()) + 1;
	for (size_t k = 4; k < sieve.size(); k += 2) {
		sieve[k] = false;
	}
	for (size_t i = 3; i <= top; i += 2) {
		if (sieve[i]) {
			for (size_t j = i * i; j < sieve.size(); j += i << 1) {
				sieve[j] = false;
			}
		}
	}

	vector<int> primes;
	for (size_t k = 2; k < sieve.size(); ++k) {
		if (sieve[k])
			primes.push_back(k);
	}
	return primes;
}

int solve (const int n)
{
	vector<int> primes = find_primes(n);
	int n_almost_primes = 0;
	for (int k = 6; k <= n; ++k) {
		int n_unique_factors = 0;
		for (const int& prime : primes) {
			if (k % prime == 0) {
				++n_unique_factors;
			}
		}
		if (n_unique_factors == 2) {
			++n_almost_primes;
		}
	}
	return n_almost_primes;
}

int main (int argc, char *argv[])
{
	int n;
	while (cin >> n)
		cout << solve(n) << endl;
	return 0;
}

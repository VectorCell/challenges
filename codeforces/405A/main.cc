/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 1 - Codeforces
 * 
 * compile for C++11
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> list(n);
	for (auto i = list.begin(); i != list.end(); ++i) {
		cin >> *i;
	}
	sort(list.begin(), list.end());
	for (auto i = list.begin(); i != list.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

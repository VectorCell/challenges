/*
**  Brandon Smith
**  CS 109 - Competitive Programming - Spring 2016
**  
**  Problem Set 12 - Codeforces 140A
**  
**  compile for C++11
*/

#include <iostream>
#include <sstream>
#include <string>

#include <cmath>

using namespace std;

bool solve (int n, int r_table, int r_plate)
{
	if (n == 1)
		return r_table >= r_plate;
	double pi_over_n = acos(-1) / n;
	double side_length = (r_table * sin(pi_over_n)) / (1 + sin(pi_over_n));
	return (side_length + 1e-8) >= (1.0 * r_plate);
}

int main (int argc, char *argv[])
{
	string line;
	while (getline(cin, line)) {
		istringstream iss(line);
		int n, r_table, r_plate;
		iss >> n >> r_table >> r_plate;
		cout << (solve(n, r_table, r_plate) ? "YES" : "NO") << endl;
	}
	return 0;
}

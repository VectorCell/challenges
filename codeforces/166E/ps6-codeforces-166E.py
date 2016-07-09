#!/usr/bin/env python3

# Brandon Smith
# CS 109 - Competitive Programming - Spring 2016
# 
# Problem Set 6 - Codeforces 166E

n = int(input())
array = [0] * (n + 1)

choose = 3
for i in range(3, n + 1):
	array[i] = (choose - array[i - 1]);
	choose *= 3
if n <= 1:
	print(0);
else:
 	print((choose - array[n]) % 1000000007)

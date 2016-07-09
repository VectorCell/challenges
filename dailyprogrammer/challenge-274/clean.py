#!/usr/bin/env python3

pipes = " ╹╺┗╻┃┏┣╸┛━┻┓┫┳╋"

while True:
	try:
		line = input()
		nums = list(int(n) for n in line.split())
		clean = ''.join(pipes[n] for n in nums if 0 <= n < len(pipes))
		print(clean)
	except Exception as ex:
		break

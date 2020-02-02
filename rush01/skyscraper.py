import itertools
from operator import mul
from functools import reduce
import sys
from time import time
from math import floor

def satisfies_r(s, row, r):
	return satisfies_l(s, list(reversed(row)), r)

def satisfies_l(s, row, l):
	if len(set(row)) < s:
		return False
	if l == 0:
		return True
	seen = 0
	curr_max = 0
	for entry in row:
		if entry > curr_max:
			curr_max = entry
			seen += 1
			if entry == s or seen > l:
                                print("row : ", row, " - entry :" ,entry, s, l)
				break
	return l == seen

def possible_rows(s, l, r):
	p = []
	for row in itertools.permutations(range(1, s + 1)):
                print("add - ", row)
		if satisfies_l(s, row, l) and satisfies_r(s, row, r):
                        print("satisfied - " , row)
			p.append(list(row))
        print("-----")
	return p

def is_valid_solution(s, solution, t, b):
	count = 0
	for i in range(s):
		c = [row[i] for row in solution]
		if not (satisfies_l(s, c, t[i]) and satisfies_r(s, c, b[i])):
			break
		count += 1
	return count == s

def solve(s, l, r, t, b, verbose):
	rows = [possible_rows(s, l[i], r[i]) for i in range(s)]
        print(rows)
        print("")
	for solution in itertools.product(*rows):
		if is_valid_solution(s, solution, t, b):
        #                print("valid solution : ", solution)
			return solution
        """
                else:
                        print("invalid solution : ", solution)
	"""
        return ["no solution found"]

def main(argv):
	s = 0
	l = r = t = b = []
	verbose = 0
	for arg in argv[1:]:
		if arg[0:2] == '-s':
			s = int(arg[2:])
			if s > 9:
				print('size should be 9 or smaller')
				exit()
		if arg[0:2] == '-c':
			temp = [int(i) for i in arg[2:]]
			t = temp[0:s]
			r = temp[s:2*s]
			b = list(reversed(temp[2*s:3*s]))
			l = list(reversed(temp[3*s:]))
		if arg[0:2] == '-l':
			l = [int(i) for i in arg[2:]]
		if arg[0:2] == '-r':
			r = [int(i) for i in arg[2:]]
		if arg[0:2] == '-t':
			t = [int(i) for i in arg[2:]]
		if arg[0:2] == '-b':
			b = [int(i) for i in arg[2:]]
		if arg[0:2] == '-v':
			verbose = 1
			if len(arg) > 2:
				verbose = float(arg[2:])
	for row in solve(s, l, r, t, b, verbose):
		print(row)


if __name__ == '__main__':
	main(sys.argv)

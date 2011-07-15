#!/usr/bin/python
import sys
import pprint

def line():
    return sys.stdin.readline().strip()

def find(grid, part, m, n, mm, nn):
    for i in range(m-mm+1):
        for j in range(n-nn+1):
            if all(grid[i+ii][j+jj] == part[ii][jj] for ii in range(mm)
                                                    for jj in range(nn)):
                return i+1, j+1
    return None

def main():
    num = int(line())
    for _ in range(num):
        m, n = map(int, line().split())
        grid = [list(line()) for _ in range(m)]
        num_grids = int(line())
        for _ in range(num_grids):
            mm, nn = map(int, line().split())
            part = [list(line()) for _ in range(mm)]
            for i in range(4):
                mm, nn = len(part), len(part[0])
                res = find(grid, part, m, n, mm, nn)
                part = zip(*part[::-1]) # rotate 90 degrees
                if res:
                    print '%d %d' % res,
                    print i*90
                    break

if __name__ == '__main__':
    main()

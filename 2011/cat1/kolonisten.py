#!/usr/bin/python
import sys
import collections as co

def line():
    return sys.stdin.readline().strip()

def main():
    chance = co.defaultdict(int)
    for i in range(1, 6+1):
        for j in range(1, 6+1):
            chance[i+j]+=1
    num = int(line())
    for _ in range(num):
        line() # niet nodig
        res = line().split() 
        val = map(int, line().split())
        produce = co.defaultdict(int)
        for r, v in zip(res, val):
            produce[r] += chance[v]
        res = sorted(produce.items(), key=lambda x: (x[1], res.count(x[0])))
        print res[0][0]

if __name__ == '__main__':
    main()

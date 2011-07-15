#!/usr/bin/python
import sys

def line():
    return sys.stdin.readline().strip()

def digits_sq(n):
    while n:
        n, dig = divmod(n, 10)
        yield dig**2

def solve(n):
    seen = set([n])
    while 1:
        n = sum(digits_sq(n))
        if n == 1:
            return 'JA'
        elif n in seen:
            return 'NEE'
        seen.add(n)

def main():
    num = int(line())
    for _ in range(num):
        print solve(int(line()))

if __name__ == '__main__':
    main()

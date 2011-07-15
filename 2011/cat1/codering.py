#!/usr/bin/python
import sys
import string
import itertools as it
import operator as op

conv = {0:' ', ' ':0}
conv.update(zip(range(1, 26+1), string.uppercase))
conv.update(zip(string.uppercase, range(1, 26+1)))
    
def line():
    return sys.stdin.readline().strip()

def parse():
    inp = line().split(' ', 1)
    return it.cycle(inp[0]), inp[1]
    
def cipher(oper):
    key, msg = parse()
    sol = []
    for k, c in zip(key, msg):
        num = (oper(conv[c], conv[k])+27) % 27
        sol.append(conv[num])
    return ''.join(sol)

def main():
    for i in range(2): 
        n = int(line())
        for _ in range(n):
            # 1st time encode, 2nd time decode
            print cipher(op.sub if i else op.add)

if __name__ == '__main__':
    main()

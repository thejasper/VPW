#!/usr/bin/python
import sys
import string
import itertools as it
import operator as op

# mapping cijfers <-> letters
conv.update(zip(range(27), ' ' + string.uppercase))
conv.update([v, k for k, v in conv.items()])

def line():
    return sys.stdin.readline().strip()

def parse():
    inp = line().split(' ', 1)
    return it.cycle(inp[0]), inp[1]
    
def cipher(oper):
    key, msg = parse()
    sol = []
    for k, c in zip(key, msg):
        num = oper(conv[c], conv[k]) % 27
        sol.append(conv[num])
    return ''.join(sol)

def main():
    for i in range(2): # 1x encoden, 1x decoden
        n = int(line())
        for _ in range(n):
            print cipher(op.sub if i else op.add)

if __name__ == '__main__':
    main()

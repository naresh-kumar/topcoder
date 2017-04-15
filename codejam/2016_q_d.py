#! /usr/bin/env python
#https://code.google.com/codejam/contest/6254486/dashboard#s=p3

import os

def gen(orig, c):
    k = len(orig)
    s = orig
    out = s
    for i in range(c-1):
        s = ''.join([orig if c == 'L' else k*'G' for c in s])
        out = ' ' + s
    print out

def mutate(s, i):
    return s[:i] + 'G' + s[i+1:]

def test():
    l = 5
    s = 'L'*l

    for i in range(l):
        gen(mutate(s, i), l-1)

def getInts(f):
    return f.readline()

def main():
    input = open('fractile.in')
    output = open('out.txt', 'w')
    tests = int(input.readline())
    for test in range(1,tests+1):
        k, c, s = [int(i) for i in input.readline().split()]
        if s >= k:
            positions = ' '.join([str(i) for i in range(1,s+1)])
            output.write("Case #%s: %s\n" % (test, positions))
        else:
            output.write("Case #%s: %s\n" % (test, 'IMPOSSIBLE'))
    input.close()
    output.close()

if __name__ == "__main__":
    main()


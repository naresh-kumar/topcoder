#! /usr/bin/env python
#https://code.google.com/codejam/contest/6254486/dashboard#s=p1

import os

def main():
    input = open('pancakes.in')
    output = open('out.txt', 'w')
    tests = int(input.readline())
    for test in range(1,tests+1):
        stack = input.readline().strip()
        count = 0
        last = ''
        for c in stack:
            count += 1 if last != c else 0
            last = c
        count -= 1 if last == '+' else 0
        output.write("Case #%s: %s\n" % (test, count))
    input.close()
    output.close()

if __name__ == "__main__":
    main()


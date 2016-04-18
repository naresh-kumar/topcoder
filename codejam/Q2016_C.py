#! /usr/bin/env python
#https://code.google.com/codejam/contest/6254486/dashboard#s=p2

import os
import math

def is_prime(n):
  if n == 2 or n == 3: return True, n
  if n < 2 or n%2 == 0: return False, 2
  if n < 9: return True, n
  if n%3 == 0: return False, 3
  r = min(int(n**0.5), 10000000)
  f = 5
  while f <= r:
    if n%f == 0: return False, f
    if n%(f+2) == 0: return False, f+2
    f += 6
  return True, n

def wline(f, s):
    f.write(str(s) + "\n")

def main():
    output = open('out.txt', 'w')
    n  = 32
    j = 500
    jamcoin = '1' + '0'*(n-2) + '1'
    next = lambda s : '{0:032b}'.format(int(s, 2) + 2)
    count = 0
    wline(output, "Case #1:")
    while count < j:
        divs = []
        b_max = 9
        for base in range(2, 2+b_max):
            prime, div = is_prime(int(jamcoin, base))
            if prime:
                break
            divs.append(div)
        if len(divs) == b_max:
            wline(output, jamcoin + ' ' + ' '.join([str(i) for i in divs]))
            count += 1
            print count, jamcoin
        jamcoin = next(jamcoin)

    output.close()

if __name__ == "__main__":
    main()


// https://www.codechef.com/status/COINS,nemausus
// https://www.codechef.com/viewplaintext/425578
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <cstdlib>

using namespace std;

int* solution = new int[524288];

long long int solve(long long int n) {
  if(n < 524288) return solution[n];
  return max(n, solve(n/2) + solve(n/3) + solve(n/4));
}

int main() {
  solution[0] = 0;
  solution[1] = 1;
  solution[2] = 2;
  for(int i = 3; i < 524288; ++i) {
    solution[i] = max(i, solution[i/2] + solution[i/3] + solution[i/4]);
  }
  int c = getchar();
  while(c != EOF) {
    int n = c - '0';
    c = getchar();
    while(isdigit(c)) {
      n = n*10 + c - '0';
      c = getchar();
    }
    printf("%lld\n", solve(n));
    while(c == ' ' || c == '\n') {
      c = getchar();
    }
  }
  return 0;
}

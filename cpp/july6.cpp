//author Naresh
#include <algorithm>
#include <bitset>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define si(x) ((int)x.size())
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a, b)
#define all(a) a.begin(),a.end()
#define ss ({int x;scanf("%d", &x);x;})
#define ssl ({long long int x;scanf("%lld", &x);x;})
#define sd ({double x;scanf("%lf", &x);x;})
#define rep(i, a, b) for(int i=(a); i<(b); ++i)
#define irep(i, a, b) for(int i=(a); i>=(b); --i)
#define iter(i,v) for(auto i : (v))

typedef long long ll;

typedef vector<vector<double> > matrix;
void mul(matrix& A, matrix& B, matrix& C) {
  rep(i, 0, 3) rep(j, 0, 3) C[i][j] = 0.0;
  rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3)
    C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
  rep(i, 0, 3) rep(j, 0, 3) A[i][j] = C[i][j];
}

// computes A ^ p
matrix pow(matrix A, int p) {
  matrix X = A;--p;
  matrix C(3, vector<double>(3));
  while (p) {
    if (p & 1) {
      mul(X, A, C);
    }
    p >>= 1;
    mul(A, A, C);
  }
  return X;
}

typedef long double  long_double_t;
int main() {
  //freopen("/Users/knaresh/codejam/codejam/in.txt", "r", stdin);
  //freopen("/Users/knaresh/codejam/codejam/out.txt", "w", stdout);
  //buffer_size = fread(buffer, 1, SIZE, stdin);
  int t = ss;
  ll n = ss, p = ss, m = ss, b = ss;
  long_double_t r1 = sd, r2 = sd, r3 = sd, r4 = sd;
  long_double_t k1 = 1.0/r1;
  long_double_t k2 = 1.0/r2;
  long_double_t k3 = 1.0/r3;
  long_double_t k4 = 1.0/r4;

  long_double_t sum = 0.0;
  long_double_t k = 0.0;
  rep(i, 0, t) {
    n = (p * n) % m + b;
    k = (n-3LL) * k4 - (n-4LL) * k3 + (n*n -7LL*n +12LL) * (k2-k1);
    sum += 1.0/k;
  }
  printf("%.6Lf\n", sum);
  return 0;
}

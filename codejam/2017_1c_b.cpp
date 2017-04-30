// Author: Naresh
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define irep(i, a, b) for (int i = (a); i >= (b); --i)
#define iter(i, v) for (auto &i : (v))
#define sint(x) int x; cin >> x
#define sdouble(x) double x; cin >> x
#define slong(x) long long x; cin >> x
#define sstring(x) string x; cin >> x

// Debug write
template <class T> void print(T t, string s = "\n") { cerr << t << s; }
template <class T> void printpair(T p) { print(p.first, "->"); print(p.second); }
template <class T> void printlist(T l) { iter(i, l) print(i, " "); cerr << endl; }
template <class T> void printlist(T *l, int n) { rep(i, 0, n) print(*(l + i), " "); cerr << endl; }
template <class T> void printmap(T m) { iter(i, m) { printpair(i); } cerr << endl; }

// Input and Output
template <class T> void sarray(T& v, int n) {
  rep(i, 0, n) { cin >> v[i]; }
}
template <class T> void sgrid(T& v, int r, int c) {
  rep(i, 0, r) rep(j, 0, c) { cin >> v[i][j]; }
}
template <class T> void out(T x) { cout << x; }
template <class T> void outs(T x) { cout << x << " "; }
template <class T> void outln(T x) { cout << x << "\n"; }

template <class T> void chmin(T &a, T b) { if (b < a) a = b; }
template <class T> void chmax(T &a, T b) { if (b > a) a = b; }

const int n = 12 * 60;

ll dp[n + 1][n + 1][2];
int timeline[2*n+1];

ll f(ll i, ll j, int last, int guess) {
  if (i == n && j == n && guess == last) return 0;
  if (i == n && j == n) return INT_MAX;
  if (i > n || j > n) return INT_MAX;

  ll& ans = dp[i][j][last];
  if (ans != -1) return ans;

  int id = timeline[i + j];
  if (id == -1) {
    ans = min(abs(last - 0) + f(i + 1, j, 0, guess),
              abs(last - 1) + f(i, j + 1, 1, guess));
  } else if (id == 0) {
    ans = abs(last - 0) + f(i + 1, j, 0, guess);
  } else {
    ans = abs(last - 1) + f(i, j + 1, 1, guess);
  }
  return ans;
}

void solve() {
  sint(C);
  sint(J);
  rep(i, 0, 2*n+1) timeline[i] = -1;
  rep(i, 0, C) {
    sint(start); sint(end);
    rep(j, start, end) timeline[j] = 0;
  }
  rep(i, 0, J) {
    sint(start); sint(end);
    rep(j, start, end) timeline[j] = 1;
  }

  ll ans = INT_MAX;
  rep(i, 0, n+1) rep(j, 0, n+1) rep(k, 0, 2) dp[i][j][k] = -1;
  chmin(ans, f(0, 0, 0, 0));

  rep(i, 0, n+1) rep(j, 0, n+1) rep(k, 0, 2) dp[i][j][k] = -1;
  chmin(ans, f(0, 0, 1, 1));

  out(ans);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sint(tests);
  rep(t, 0, tests) {
    cout << "Case #" << t + 1 << ": ";
    solve();
    cout << endl;
  }
  return 0;
}


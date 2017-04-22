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

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define irep(i, a, b) for (int i = (a); i >= (b); --i)
#define iter(i, v) for (auto &i : (v))

typedef long long ll;

template <class T> void print(T t, string s = "\n") { cerr << t << s; }
template <class T> void printpair(T p) { print(p.first, "->"); print(p.second); }
template <class T> void printlist(T l) { iter(i, l) print(i, " "); cerr << endl; }
template <class T> void printlist(T *l, int n) { rep(i, 0, n) print(*(l + i), " "); cerr << endl; }
template <class T> void printmap(T m) { iter(i, m) { printpair(i); } cerr << endl; }

int si() { int x; scanf("%d", &x); return x; }
int sll() { ll x; scanf("%lld", &x); return x; }
double sf() { double x; scanf("%lf", &x); return x; }
string ss(int n = 1000) { char buf[n+1]; scanf("%s", buf); return buf; }
void svector(vector<int> &v, int n) { rep(i, 0, n) v.push_back(si()); }
void sarray(int *v, int n) { rep(i, 0, n) v[i] = si(); }
template <class T> void chmin(T &a, T b) { if (b < a) a = b; }
template <class T> void chmax(T &a, T b) { if (b > a) a = b; }

void solve() {
}

int main() {
  int tests = si();
  rep(t, 0, tests) {
    printf("Case #%d: ", t + 1);
    solve();
    printf("\n");
  }
  return 0;
}

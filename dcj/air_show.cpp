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
#include "message.h"
#include "air_show.h"

using namespace std;
typedef long long ll;
typedef __int128 bigint;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define irep(i, a, b) for (int i = (a); i >= (b); --i)

// Stream operators for std::pair
template<class F, class S> ostream& operator<<(ostream& os, const pair<F,S>& p) { return os << p.first << ":" << p.second; }
template<class F, class S> istream& operator>>(istream& is, pair<F,S>& p) { return is >> p.first >> p.second; }

// Debug write to stderr
template <class T> void print(T& t, string s = "") { cerr << "    " << t << s; }
template <class T> void printlist(T& l, int n, string s = "") { rep(i,0,n) print(l[i], s); print("\n"); }
template <class T> void printmap(T& m, string s = "") { for(auto& i : m) { print(i, s); } print("\n"); }

// Input from stdin
#define sint(x) int x; cin >> x
#define sdouble(x) double x; cin >> x
#define slong(x) ll x; cin >> x
#define sstring(x) string x; cin >> x
template <class T> void sarray(T& v, int n) { rep(i, 0, n) { cin >> v[i]; } }
template <class T> void sgrid(T& v, int r, int c) { rep(i, 0, r) rep(j, 0, c) { cin >> v[i][j]; } }

template <class T> void chmin(T &a, T b) { if (b < a) a = b; }
template <class T> void chmax(T &a, T b) { if (b > a) a = b; }

bool IsFirst() { return MyNodeId() == 0; }
bool IsLast() { return MyNodeId() == NumberOfNodes() - 1; }
int Next() { return MyNodeId() + 1; }
int Previous() { return MyNodeId() - 1; }
pair<int, int> MyRange(ll n) {
  int start = n * MyNodeId() / NumberOfNodes();
  int end = n * (MyNodeId() + 1) / NumberOfNodes();
  return {start, end};
}

void Small() {
  auto range = MyRange(GetNumSegments() - 1); // 0 ot n-2
  ll safe_dist = GetSafeDistance() * GetSafeDistance();
  ll ans = 0;
  rep(i, range.first + 1, range.second + 1) {
    ll p1 = GetPosition(0, i);
    ll y1 = p1 >> 20;
    ll z1 = p1 - (y1 << 20);

    ll p2 = GetPosition(1, i);
    ll y2 = p2 >> 20;
    ll z2 = p2 - (y2 << 20);
    ll dist = (z2 - z1) * (z2 - z1) + (y1 - y2) * (y1 - y2);
    if (dist < safe_dist) {
      ++ans;
    }
  }
  PutLL(0, ans);
  Send(0);
  if (IsFirst()) {
    ans = 0;
    rep (i, 0, NumberOfNodes()) {
      Receive(i);
      ans += GetLL(i);
    }
    cout << ans <<  " " << ans << endl;
  }
}

void Large() {
  // TODO
}

int main() {
  Small();
}

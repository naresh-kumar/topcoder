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

using namespace std;
typedef int64_t ll;
typedef __int128 bigint;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define irep(i, a, b) for (ll i = (a); i >= (b); --i)

// Stream operators for std::pair
template<class F, class S> ostream& operator<<(ostream& os, const pair<F,S>& p) { return os << p.first << ":" << p.second; }

// Debug write to stderr
template <class T> void print(T& v, string s = "\n") { cerr << v << s; }
template <class T> void printlist(T& l, int n) { rep(i,0,n) print(l[i], " "); print(""); }
template <class T> void printgrid(T& g, int n, int m) { rep(i,0,n) { printlist(g[i], m); } }
template <class T> void printmap(T& m) { for(auto& i : m) { print(i, " "); } print(""); }

template <class T> void chmin(T &a, T b) { if (b < a) a = b; }
template <class T> void chmax(T &a, T b) { if (b > a) a = b; }

class Writer {
 public:
  Writer(int to) : to(to) {}
  Writer& Char(char v) { PutChar(to, v); return *this; }
  Writer& Int(int v) { PutInt(to, v); return *this; }
  Writer& LL(ll v) { PutLL(to, v); return *this; }
  Writer& String(string& s) { PutInt(to, s.size()); for (auto c : s) PutChar(to, c); return *this; }
  Writer& IntVector(vector<int>& l) { PutInt(to, l.size()); for (auto v : l) PutInt(to, v); return *this; }
  Writer& LLVector(vector<ll>& l) { PutInt(to, l.size()); for (auto v : l) PutLL(to, v); return *this; }
  void Done() { Send(to); }
  int to;
};

class Reader {
 public:
  Reader(int from) : from(from) { Receive(from);}
  char Char() { return GetChar(from); }
  int Int() { return GetInt(from); }
  ll LL() { return GetLL(from); }
  void String(string& s) { int n = GetInt(from); s.resize(n); rep(i, 0, n) s[i] = GetChar(from); }
  void IntVector(vector<int>& v) { int n = GetInt(from); v.resize(n); rep(i, 0, n) v[i] = GetInt(from); }
  void LLVector(vector<ll>& v) { int n = GetInt(from); rep(i, 0, n) v[i] = GetLL(from); }
  int from;
};

class Node {
 public:
  Node(ll range, int currid, int nnodes) {
    id = currid;
    start = range * id / nnodes;
    end = range * (id + 1) / nnodes;
    size = end - start;
    is_first = id == 0;
    is_last = id == nnodes - 1;
    next = (id + 1) % nnodes;
    previous = (id + nnodes - 1) % nnodes;
  }
  int id, start, end, size, previous, next, is_first, is_last;
};

// default limits
// Each node can send at most 1000 messages and total size of all messages
// can not exceed 8MB.

/*************************** Code starts here *********************************/

#include "asteroids.h"

ll width = GetWidth();
ll height = GetHeight();

inline ll score(ll i, ll j) {
  if (j >= width) return INT_MIN;
  char c = GetPosition(i, j);
  return c == '#' ? INT_MIN : c - '0';
}

ll k = 300;
int main() {
  ll nnodes = NumberOfNodes();
  ll n = width;
  while(n % k != 0) ++n;
  nnodes = n / k;
  Node node(n, MyNodeId(), nnodes);
  if (node.id >= nnodes) return 0;
  assert(node.size == k);
  ll l = max(node.start - k, (ll)0);
  ll r = min(node.end + k, n);
  ll segment = r - l;
  vector<vector<ll>> dp(2, vector<ll>(segment, 0));
  int from = 0;
  int to = 1;
  vector<ll> val(segment, 0);
  for (ll row = 0; row < height; ++row) {
    if (row % k == 0 && row > 0) {
      if (not node.is_first) {
        Reader reader(node.previous);
        rep(i, 0, k) dp[from][i] = reader.LL();
      }
      if (not node.is_last) {
        Reader reader(node.next);
        rep(i, 0, k) dp[from][k + i + node.start - l] = reader.LL();
      }
    }
    rep (i, 0, segment) {
      val[i] = score(row, i + l);
    }
    for (ll j = 0; j < segment; ++j) {
      ll ans = dp[from][j] + val[j];
      if (j > 0) {
        chmax(ans, dp[from][j - 1] + val[j] + val[j-1]);
      }
      if (j + 1 < segment) {
        chmax(ans, dp[from][j + 1] + val[j] + val[j+1]);
      }
      dp[to][j] = ans;
    }
    if (row % k == k - 1 && row != height - 1) {
      if (not node.is_first) {
        Writer writer(node.previous);
        rep(i, 0, k) writer.LL(dp[to][i + node.start - l]);
        writer.Done();
      }
      if (not node.is_last) {
        Writer writer(node.next);
        rep(i, 0, k) writer.LL(dp[to][i + node.start - l]);
        writer.Done();
      }
    }
    from = not from;
    to = not to;
  }
  ll ans = INT_MIN;
  rep(i, 0, k) chmax(ans, dp[from][i + node.start - l]);
  Writer(0).LL(ans).Done();
  if (node.is_first) {
    ll ans = INT_MIN;
    rep(i, 0, nnodes) {
      Reader reader(i);
      chmax(ans, reader.LL());
    }
    if (ans < 0) ans = -1;
    cout << ans << endl;
  }
  return 0;
}

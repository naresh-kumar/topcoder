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
  Reader& Char(char& v) { v = GetChar(from); return *this; }
  Reader& Int(int& v) { v = GetInt(from); return *this; }
  Reader& LL(ll& v) { v = GetLL(from); return *this; }
  Reader& String(string& s) { int n = GetInt(from); s.resize(n); rep(i, 0, n) s[i] = GetChar(from); return *this; }
  Reader& IntVector(vector<int>& v) { int n = GetInt(from); v.resize(n); rep(i, 0, n) v[i] = GetInt(from); return *this; }
  Reader& LLVector(vector<ll>& v) { int n = GetInt(from); rep(i, 0, n) v[i] = GetLL(from); return *this; }
  int from;
};

class Node {
 public:
  Node(ll range) : Node(range, MyNodeId(), NumberOfNodes()) {}
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

/*************************** Code starts here *********************************/

#include "again.h"
#define MOD 1000000007
ll amm(ll a, ll b, ll c = 1) { return ((c * b) % MOD + a) % MOD; }
int main() {
  int nnodes = NumberOfNodes();
  ll n = GetN();
  Node node(n, MyNodeId(), nnodes);
  ll asum = 0, bsum = 0;
  rep(i, node.start, node.end) {
    asum = (asum + GetA(i)) % MOD;
    bsum = (bsum + GetB(i)) % MOD;
  }
  ll extra_a = 0;
  for (int i = node.id; i < n; i += nnodes) {
    extra_a = (extra_a + GetA(i)) % MOD;
  }
  ll extra_b = 0;
  for (int j = (nnodes - node.id) % nnodes; j < n; j += nnodes) {
    extra_b = (extra_b + GetB(j)) % MOD;
  }
  ll extra = (extra_a * extra_b) % MOD;
  Writer w(0);
  w.LL(asum).LL(bsum).LL(extra).Done();

  if (node.id == 0) {
    ll asum = 0, bsum = 0;
    ll extra = 0;
    rep(i, 0, nnodes) {
      Reader reader(i);
      ll a,b,ex;
      reader.LL(a).LL(b).LL(ex);
      asum = (asum + a) % MOD;
      bsum = (bsum + b) % MOD;
      extra = amm(extra, ex);
    }
    ll ans = (asum * bsum) % MOD;
    ans = ans - extra;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
  }
  return 0;
}

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
  Node(ll range, ll currid, ll nnodes) {
    id = currid;
    begin = range * id / nnodes;
    end = range * (id + 1) / nnodes;
    size = end - begin;
    is_first = id == 0;
    is_last = id == nnodes - 1;
    next = (id + 1) % nnodes;
    previous = (id + nnodes - 1) % nnodes;
  }
  ll id, begin, end, size, previous, next, is_first, is_last;
};

// default limits
// Each node can send at most 1000 messages and total size of all messages
// can not exceed 8MB.

/*************************** Code starts here *********************************/

#include "todd_and_steven.h"
ll MOD =  1000000007;
ll tlength = GetToddLength();
ll slength = GetStevenLength();

ll bsearchtodd(ll v) {
  ll s = 0;
  ll e = tlength;
  ll m = (s + e) / 2;
  while (s < e) {
    ll curr = GetToddValue(m);
    if (curr < v) {
      s = m+1;
    } else {
      e = m;
    }
    m = (s + e) / 2;
  }
  return m;
}

ll bsearchsteven(ll v) {
  ll s = 0;
  ll e = slength;
  ll m = (s + e) / 2;
  while (s < e) {
    ll curr = GetStevenValue(m);
    if (curr < v) {
      s = m+1;
    } else {
      e = m;
    }
    m = (s + e) / 2;
  }
  return m;
}

int main() {
  int nnodes = NumberOfNodes();
  Node nodet(tlength, MyNodeId(), nnodes);
  Node nodes(slength, MyNodeId(), nnodes);
  ll ans = 0;
  ll j = -1;
  rep(i, nodet.begin, nodet.end) {
    ll curr = GetToddValue(i);
    if (j == -1) {
      j = bsearchsteven(curr);
    } else {
      int limit = 10;
      while (j < slength && GetStevenValue(j) < curr && limit) {
        ++j;
        --limit;
      }
      if (not limit) {
        j = bsearchsteven(curr);
      }
    }
    ans += (i + j) ^ curr;
    ans = ans % MOD;
  }

  j = -1;
  rep(i, nodes.begin, nodes.end) {
    ll curr = GetStevenValue(i);
    if (j == -1) {
      j = bsearchtodd(curr);
    } else {
      int limit = 10;
      while (j < tlength && GetToddValue(j) < curr && limit) {
        ++j;
        --limit;
      }
      if (not limit) {
        j = bsearchtodd(curr);
      }
    }
    ans += (i + j) ^ curr;
    ans = ans % MOD;
  }

  Writer(0).LL(ans).Done();
  if (nodet.is_first) {
    ll ans = 0;
    rep(i, 0, nnodes) {
      Reader reader(i);
      ans += reader.LL();
      ans = ans % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}

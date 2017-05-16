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
template <class T> void print(T& t, string s = "") { cerr << "    " << t << s; }
template <class T> void printlist(T& l, int n, string s = "") { rep(i,0,n) print(l[i], s); print("\n"); }
template <class T> void printmap(T& m, string s = "") { for(auto& i : m) { print(i, s); } print("\n"); }

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

int main() {
  int nnodes = NumberOfNodes();
  Node node(0, MyNodeId(), nnodes);
  return 0;
}

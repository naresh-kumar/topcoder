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

#include "query_of_death.h"

int main() {
  int nnodes = NumberOfNodes();
  if (MyNodeId() == 0) {
    ll n = GetLength();
    set<int> nodes;
    rep(i, 1, nnodes) nodes.insert(i);
    ll offset = 0;
    ll sum = 0;
    while (n > 1) {
      int i = 0;
      for (auto node_id : nodes) {
        Node node(n, i, nodes.size());
        Writer(node_id).LL(offset + node.begin).LL(offset + node.end).Done();
        ++i;
      }
      ll broken = -1;
      for (auto node_id : nodes) {
        Reader reader(node_id);
        ll v = reader.LL();
        ll from = reader.LL();
        ll to = reader.LL();
        if (v == -1) {
          broken = node_id;
          offset = from;
          n = to - from;
        }
        else sum += v;
      }
      nodes.erase(broken);
    }
    rep (i, 1, nnodes) {
      Writer(i).LL(-1).LL(-1).Done();
    }
    cout << sum + GetValue(offset) << endl;
    return 0;
  }
  while (true) {
    Reader reader(0);
    ll from = reader.LL();
    ll to = reader.LL();
    if (from == -1) break;
    ll sum = 0;
    rep(i, from, to) { sum += GetValue(i); }
    bool isbroken = false;
    if (from != to) {
      ll v = GetValue(from);
      rep(i, 0, 100) {
        if (GetValue(from) != v) {
          isbroken = true;
          break;
        }
      }
    }
    Writer(0).LL(isbroken ? -1 : sum).LL(from).LL(to).Done();
  }
  return 0;
}

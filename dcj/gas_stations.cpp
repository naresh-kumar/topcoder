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
    begin = range * id / nnodes;
    end = range * (id + 1) / nnodes;
    size = end - begin;
    is_first = id == 0;
    is_last = id == nnodes - 1;
    next = (id + 1) % nnodes;
    previous = (id + nnodes - 1) % nnodes;
  }
  int id, begin, end, size, previous, next, is_first, is_last;
};

// default limits
// Each node can send at most 1000 messages and total size of all messages
// can not exceed 8MB.

/*************************** Code starts here *********************************/
#include "gas_stations.h"

int small() {
  int nnodes = NumberOfNodes();
  Node node(0, MyNodeId(), nnodes);
  if (node.id > 0) return 0;
  ll tank_size = GetTankSize();
  ll dist = GetNumKms();
  deque<pair<ll, ll>> prices;
  ll cost = 0;
  rep(i, 0, dist) {
    ll p = GetGasPrice(i);
    while (not prices.empty() && prices.back().second > p) {
      prices.pop_back();
    }
    prices.push_back({i, p});
    if (prices.front().first <= i - tank_size) {
      prices.pop_front();
    }
    cost += prices.front().second;
  }
  cout << cost << endl;
  return 0;
}

ll k = 5 * 1000000;
ll dist = GetNumKms();
ll P(ll i) {
  return i < dist ? GetGasPrice(i) : 0;
}

int main() {
  int nnodes = NumberOfNodes();
  ll n = dist;
  while (n % k != 0) ++n;
  nnodes = n/k;
  Node node(n, MyNodeId(), nnodes);
  if (node.id >= nnodes) return 0;

  ll min_index = -1;
  ll min_value = INT_MAX;
  ll r = min((ll)node.end, dist);
  rep(i, node.begin, r) {
    ll price = P(i);
    if (price <= min_value) {
      min_value = price;
      min_index = i;
    }
  }
  rep(i, 0, nnodes) {
    Writer(i).LL(min_index).LL(min_value).Done();
  }
  vector<pair<ll, ll>> min_prices(nnodes);
  rep(i, 0, nnodes) {
    Reader reader(i);
    min_prices[i].first = reader.LL();
    min_prices[i].second = reader.LL();
  }
  ll tank_size = GetTankSize();
  deque<pair<ll, ll>> prices;
  ll s_index = max((ll)0, node.begin - tank_size + 1);
  ll e_index = min((ll)node.begin, s_index + k);
  rep (i, s_index, e_index) {
    ll p = P(i);
    while (not prices.empty() && prices.back().second >= p) {
      prices.pop_back();
    }
    prices.push_back({i, p});
  }
  rep(i, 0, nnodes) {
    ll index = min_prices[i].first;
    ll p = min_prices[i].second;
    if (i < node.id && index > prices.back().first) {
      while (not prices.empty() && prices.back().second >= p) {
        prices.pop_back();
      }
      prices.push_back({index, p});
    }
  }
  ll cost = 0;
  rep(i, node.begin, r) {
    ll p = P(i);
    while (not prices.empty() && prices.back().second >= p) {
      prices.pop_back();
    }
    prices.push_back({i, p});
    if (prices.front().first <= i - tank_size) {
      prices.pop_front();
    }
    cost += prices.front().second;
  }
  Writer(0).LL(cost).Done();
  if (node.is_first) {
    ll cost = 0;
    rep(i, 0, nnodes) {
      Reader reader(i);
      cost += reader.LL();
    }
    cout << cost << endl;
  }
  return 0;
}

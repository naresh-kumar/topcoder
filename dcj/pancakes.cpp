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
typedef long long ll;
typedef __int128 bigint;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define irep(i, a, b) for (int i = (a); i >= (b); --i)

// Stream operators for std::pair
template<class F, class S> ostream& operator<<(ostream& os, const pair<F,S>& p) { return os << p.first << ":" << p.second; }

// Debug write to stderr
template <class T> void print(T& t, string s = "") { cerr << "    " << t << s; }
template <class T> void printlist(T& l, int n, string s = "") { rep(i,0,n) print(l[i], s); print("\n"); }
template <class T> void printmap(T& m, string s = "") { for(auto& i : m) { print(i, s); } print("\n"); }

template <class T> void chmin(T &a, T b) { if (b < a) a = b; }
template <class T> void chmax(T &a, T b) { if (b > a) a = b; }

template <class T> void Put(int to, T value);
template <class T> void Put(int to, vector<T>& list);
template<> void Put<ll>(int to, ll value) { PutLL(to, value); Send(to); }
template<> void Put<int>(int to, int value) { PutInt(to, value); Send(to); }
template<> void Put<char>(int to, char value) { PutChar(to, value); Send(to); }
template<> void Put<ll>(int to, vector<ll>& list) { for(auto value : list) PutLL(to, value); Send(to); }
template<> void Put<int>(int to, vector<int>& list) { for(auto value : list) PutInt(to, value); Send(to); }
template<> void Put<char>(int to, vector<char>& list) { for(auto value : list) PutChar(to, value); Send(to); }

template <class T> T Get(int from);
template<> ll Get<ll>(int from) { Receive(from); return GetLL(from); }
template<> int Get<int>(int from) { Receive(from); return GetInt(from); }
template<> char Get<char>(int from) { Receive(from); return GetChar(from); }

class Node {
 public:
  Node(ll range) {
    id = MyNodeId();
    start = range * MyNodeId() / NumberOfNodes();
    end = range * (MyNodeId() + 1) / NumberOfNodes();
    size = end - start;
    is_first = id == 0;
    is_last = id == NumberOfNodes() - 1;
    next = id + 1;
    previous = id - 1;
  }
  int id, start, end, size, previous, next, is_first, is_last;
};
#include "pancakes.h"

int main() {
  ll N = GetStackSize();
  Node node(N);
  ll rounds = 0;
  ll last = INT_MAX;
  rep(i, node.start, node.end) {
    ll curr = GetStackItem(i);
    if (curr < last) ++rounds;
    last = curr;
  }
  ll s = -1;
  ll e = -1;
  if (node.start < node.end) {
    s = GetStackItem(node.start);
    e = GetStackItem(node.end - 1);
  }
  PutLL(0, rounds);
  PutLL(0, s);
  PutLL(0, e);
  Send(0);
  if (node.is_first) {
    ll rounds = 0;
    ll e = INT_MAX;
    rep(i, 0, NumberOfNodes()) {
      rounds += Get<ll>(i);
      ll currs = GetLL(i);
      ll curre = GetLL(i);
      if (currs > -1) {
        if (currs >= e) --rounds;
        e = curre;
      }
    }
    cout << rounds << endl;
  }
  return 0;
}

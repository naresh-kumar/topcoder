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


#include "weird_editor.h"

ll MOD = 1000000007;
ll pow(ll exp) {
  ll base = 10;
  ll result = 1;
  while (exp) {
    if (exp & 1) result = (result * base) % MOD;
    exp >>= 1;
    base = (base * base) % MOD;
  }
  return result;
}

int main() {
  ll N = GetNumberLength();
  Node node(N);
  vector<ll> count(10, 0);
  vector<ll> mm(10, 0);
  rep(i, node.start, node.end) {
    ll d = GetDigit(i);
    for (int j = 0; j < d; ++j) {
      count[j] = 0;
      mm[j] = 0;
    }
    ++count[d];
    mm[d] = ((mm[d] * 10) % MOD + d) % MOD;
  }

  rep(i, 1, 10) {
    PutLL(0, count[i]);
    PutLL(0, mm[i]);
  }
  Send(0);
  if (not node.is_first) return 0;

  {
    vector<ll> count(10, 0);
    vector<ll> mm(10, 0);
    vector<ll> wcount(10, 0);
    vector<ll> wmm(10, 0);
    rep(i, 0, NumberOfNodes()) {
      Receive(i);
      rep(digit, 1, 10) {
        wcount[digit] = GetLL(i);
        wmm[digit] = GetLL(i);
      }
      irep (d, 9, 0) {
        if (wcount[d] <= 0) continue;
        for (int j = 0; j < d; ++j) {
          count[j] = 0;
          mm[j] = 0;
        }
        count[d] += wcount[d];
        ll exp = pow(wcount[d]);
        mm[d] = ((mm[d] * exp) % MOD) + wmm[d];
      }
    }
    ll ans = 0;
    ll offset = 0;
    for (ll d = 9; d > 0; --d) {
      ll power = N - offset - count[d];
      offset += count[d];
      ans += (mm[d] * pow(power)) % MOD;
      ans %= MOD;
    }
      cout << ans << endl;
    }
  return 0;
}

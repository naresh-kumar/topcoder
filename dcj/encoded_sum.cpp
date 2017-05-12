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

bool IsFirst() { return MyNodeId() == 0; }
bool IsLast() { return MyNodeId() == NumberOfNodes() - 1; }
int Next() { return MyNodeId() + 1; }
int Previous() { return MyNodeId() - 1; }
pair<int, int> MyRange(ll n) {
  int start = n * MyNodeId() / NumberOfNodes();
  int end = n * (MyNodeId() + 1) / NumberOfNodes();
  return {start, end};
}

#include "encoded_sum.h"

int UNSEEN = 0;
int RESOLVED = 1;
int TIED = 2;

int Resolve(char ch, vector<int>& tied, vector<int>& state) {
  int with = tied[ch];
  if (with != -1) {
    tied[with] = -1;
    state[with] = RESOLVED;
  }
  tied[ch] = -1;
  state[ch] = RESOLVED;
  return with;
}

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
  vector<int> state(10, UNSEEN);
  string a = "";
  string b = "";
  vector<int> tied(10, -1);
  auto range = MyRange(GetLength());
  rep(i, range.first, range.second) {
    char one = GetScrollOne(i) - 'A';
    char two = GetScrollTwo(i) - 'A';
    if (one == two) {
      if (state[one] != RESOLVED) {
        a += one;
        b += one;
        Resolve(one, tied, state);
      }
    } else {
      if (tied[one] == two) {
        continue;
      }
      if (state[one] == UNSEEN && state[two] == UNSEEN) {
        a += one;
        b += two;
        state[one] = state[two] = TIED;
        tied[one] = two;
        tied[two] = one;
      } else if (state[one] != RESOLVED || state[two] != RESOLVED) {
        a += one;
        b += two;
        Resolve(one, tied, state);
        Resolve(two, tied, state);
      }
    }
  }
  PutInt(0, a.length());
  for(auto& ch: a) PutChar(0, ch);
  for(auto& ch: b) PutChar(0, ch);
  Send(0);
  if (IsFirst()) {
    string a = "";
    string b = "";
    rep(i, 0, NumberOfNodes()) {
      Receive(i);
      int len = GetInt(i);
      rep(j, 0, len) {
        a += GetChar(i);
      }
      rep(j, 0, len) {
        b += GetChar(i);
      }
    }
    vector<int> state(10, UNSEEN);
    vector<int> tied(10, -1);
    vector<int> rank(10, 0);
    int index = 9;
    rep(i, 0, a.length()) {
      char one = a[i];
      char two = b[i];
      if (one == two) {
        if (state[one] == UNSEEN) {
          rank[one] = index--;
          Resolve(one, tied, state);
        } else if (state[one] == TIED) {
          int with = Resolve(one, tied, state);
          if (with != -1) {
            rank[with]--;
          }
        }
      } else {
        if (tied[one] == two) {
          continue;
        }
        if (state[one] == UNSEEN && state[two] == UNSEEN) {
          state[one] = state[two] = TIED;
          rank[one] = rank[two] = index;
          tied[one] = two;
          tied[two] = one;
          index -= 2;
          continue;
        }
        if (state[one] == UNSEEN) {
          rank[one] = index--;
          Resolve(one, tied, state);
        } else if (state[one] == TIED) {
          int with = Resolve(one, tied, state);
          if (with != -1) {
            rank[with]--;
          }
        }
        if (state[two] == UNSEEN) {
          rank[two] = index--;
          Resolve(two, tied, state);
        } else if (state[two] == TIED) {
          int with = Resolve(two, tied, state);
          if (with != -1) {
            rank[with]--;
          }
        }
      }
    }
    set<int> dedup;
    for(auto& r : rank) {
      if (dedup.find(r) != dedup.end() && r != 0) {
        --r;
      }
      dedup.insert(r);
    }
    rep(i, 0, NumberOfNodes()) {
      for(auto r: rank) {
        PutInt(i, r);
      }
      Send(i);
    }
  }
  vector<int> rank(10, 0);
  Receive(0);
  rep(i, 0, 10) rank[i] = GetInt(0);
  ll result = 0;
  ll mult = pow(GetLength() - range.second);
  irep(i, range.second - 1, range.first) {
    ll one = rank[GetScrollOne(i) - 'A'];
    ll two = rank[GetScrollTwo(i) - 'A'];
    result = (result + (mult * one) % MOD) % MOD;
    result = (result + (mult * two) % MOD) % MOD;
    mult = (mult * 10) % MOD;
  }
  PutLL(0, result);
  Send(0);
  if (IsFirst()) {
    ll result = 0;
    rep(i, 0, NumberOfNodes()) {
      Receive(i);
      result = (result + GetLL(i)) % MOD;
    }
    cout << result << endl;
  }
  return 0;
}

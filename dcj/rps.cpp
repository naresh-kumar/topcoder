// Author: Naresh
#include <algorithm>
#include <bitset>
#include <cassert>
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
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <limits.h>
#include <vector>
#include "message.h"
#include "rps.h"

using namespace std;

#define all(a) a.begin(),a.end()
#define rep(i, a, b) for(int i=(a); i<(b); ++i)
#define irep(i, a, b) for(int i=(a); i>=(b); --i)
#define iter(i,v) for(auto &i : (v))

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<string, string> pss;

typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;

// read
#define gc getchar_unlocked
template<class T> inline T readnum() { int i=gc(),f=1; for(;i<'0'||i>'9';i=gc()) if(i=='-') { f=-1;i=gc();break; } T ret = 0; for(;i>='0'&&i<='9';i=gc()) { ret = ret*10 + (i-'0'); } return f*ret; }
inline int si() { return readnum<int>(); }
inline ll sll() { return readnum<ll>(); }
inline string ss() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }
inline void svector(vector<int>& v, int n) { v.reserve(n); rep(i,0,n) v.push_back(si()); }
inline void sarray(int* v, int n) { rep(i,0,n) v[i] = si(); }

// debug write
template<class T> inline void println(T t, string msg = "") { cerr <<  msg << " " << t << endl; }
template<class T> inline void prints(T t, string s = " ") { cerr << t << s; }
template<class T> inline void printlist(T l) { iter(i,l) prints(i); cerr << endl; }
template<class T> inline void printlist(T *l, int n) { rep(i,0,n) prints(*(l+i)); cerr << endl; }
template<class T> inline void printmap(T m) { iter(i,m) { prints(i.first); prints(i.second); } cerr << endl; }

// general utils
template<class T> inline void setmax(T &a, T b) { if(b > a) a = b; }
template<class T> inline void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> inline bool isInGrid(T i, T j, T n) { return i>=0 && i<n && j>=0 && j<n; }
template<class T> inline bool isInside(T a, T b, T c) { return a > b && a < c; }
template<class T> inline T reverse(T n) { T r = 0; while (n != 0) { r = r*10; r = r+n%10; n = n/10; } return r; }
template<class T> inline int firstdigit(T n) { int r = 0; while (n != 0) { r = n%10; n = n/10; } return r; }
template<class T> inline int digits(T n) { int r = 0; while (n != 0) { ++r; n /= 10; } return r; }
inline int frequency(string& s, char c) { int r = 0; rep(i,0,s.length()) if (s[i] == c) ++r; return r; }

// math utils
extern int MOD;
// multiply add mod
template<class T> inline T mam(T a, T b, T c) { return ((a*b) % MOD + c) % MOD; }
ll factorial(int x) { return (x < 2) ? 1 : x*factorial(x-1); }
ll ncr(int n, int r) { return factorial(n)/(factorial(r) * factorial(n-r)); }
inline ll ipow(ll a, ll b, ll c = MOD) { ll r = 1; while(b) { if(b & 1) r = r*a % MOD; a = a*a % MOD; b >>= 1; } return r; }
inline ll inver(ll a,ll c = MOD) { ll ans = ipow(a,MOD-2); return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
inline bool almost_equal(double x, double y, int ulp) { return std::abs(x-y) < std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp || std::abs(x-y) < std::numeric_limits<double>::min(); }

// constants
const double PI = 3.14159265358979323846;
const int MAX_INT = (1LL << 31) - 1;
const int MIN_INT = (1LL << 31);
int MOD = 1E+7 + 7;

bool IsFirst() { return MyNodeId() == 0; }
bool IsLast() { return MyNodeId() == NumberOfNodes() - 1; }
pii NodeRange(ll p) {
  if (NumberOfNodes() <= 10 || p <= 10) {
    if (IsFirst()) return {0, 1 << p};
    return {0,0};
  }
  if (MyNodeId() < 64) {
    ll n = 1LL << p;
    int start = n * MyNodeId() / 64;
    int end = n * (MyNodeId() + 1) / 64;
    return {start, end};
  } else {
    return {0,0};
  }
}

int winner(int id1, int id2) {
  char l = GetFavoriteMove(id1);
  char r = GetFavoriteMove(id2);
  if (l == r) return id1;
  if (l == 'R' && r == 'S') return id1;
  if (l == 'S' && r == 'R') return id2;
  if (l == 'S' && r == 'P') return id1;
  if (l == 'P' && r == 'S') return id2;
  if (l == 'P' && r == 'R') return id1;
  if (l == 'R' && r == 'P') return id2;
  return id1;
}

int main() {
  ll p = GetN();
  pii range = NodeRange(p);
  if (range.first == range.second) {
    PutInt(0, -1);
    Send(0);
  } else {
    vi ans;
    ans.reserve((range.second - range.first) / 2);
    for (int i = range.first; i < range.second; i += 2)
      ans.push_back(winner(i, i + 1));
    ll n = ans.size();
    while (n > 1) {
      for (int i = 0; i < n; i += 2) {
        ans[i / 2] = winner(ans[i], ans[i + 1]);
      }
      n = n / 2;
    }
    PutInt(0, ans[0]);
    Send(0);
  }
  if (IsFirst()) {
    vi ans;
    rep(i, 0, NumberOfNodes()) {
      Receive(i);
      int id = GetInt(i);
      if (id > -1) {
        ans.push_back(id);
      }
    }
    ll n = ans.size();
    while (n > 1) {
      for (int i = 0; i < n; i += 2) {
        ans[i / 2] = winner(ans[i], ans[i + 1]);
      }
      n = n / 2;
    }
    cout << ans[0] << endl;
  }
  return 0;
}

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
#include <limits.h>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

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
template<class T> inline void printpair(T m, T n) { cerr << m << " " << n << endl; }

// general utils
template<class T> inline void setmax(T &a, T b) { if(b > a) a = b; }
template<class T> inline void setmin(T &a, T b) { if(b < a) a = b; }
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
#define counti __builtin_popcount
#define countll __builtin_popcountll

// constants
const double PI = 3.14159265358979323846;
const int MAX_INT = (1LL << 31) - 1;
const int MIN_INT = (1LL << 31);
int MOD = 1E+7 + 7;

const int N = 1000;
ll sum[N][N];
int matrix[N][N];
int sw[N][N];
int larr[N];
int lw[N];

void maxSlidingWindow(int* A, int n, int w, int* B) {
  deque<int> Q;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] >= A[Q.back()]) Q.pop_back();
    Q.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i - w] = A[Q.front()];
    while (!Q.empty() && A[i] >= A[Q.back()]) Q.pop_back();
    while (!Q.empty() && Q.front() <= i - w) Q.pop_front();
    Q.push_back(i);
  }
  B[n - w] = A[Q.front()];
}

int main() {
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);
  int n = si();
  int m = si();
  rep (i, 0, n) rep (j, 0, m) matrix[i][j] = si();
  sum[0][0] = matrix[0][0];
  rep (i, 1, n) sum[i][0] = sum[i-1][0] + matrix[i][0];
  rep (j, 1, m) sum[0][j] = sum[0][j-1] + matrix[0][j];
  rep (i, 1, n) rep (j, 1, m) {
    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
  }
  int q = si();
  rep (i, 0, q) {
    int a = si();
    int b = si();
    ll ans = MAX_INT;
    rep (i, 0, n) {
      maxSlidingWindow(matrix[i], m, b, sw[i]);
    }
    rep(j, 0, m - b + 1) {
      rep(i, 0, n) {
        larr[i] = sw[i][j];
      }
      maxSlidingWindow(larr, n, a, lw);
      rep(i, 0, n - a + 1) {
        int lmax = lw[i];
        // cout << "i:" << i << " j:" << j << " m:" << lmax << endl;
        ll csum = sum[i + a - 1][j + b - 1];
        if (i - 1 >= 0) csum -= sum[i - 1][j + b - 1];
        if (j - 1 >= 0) csum -= sum[i + a - 1][j - 1];
        if (i - 1 >= 0 && j - 1 >= 0) csum += sum[i - 1][j - 1];
        ans = min(ans, a * b * lmax - csum);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

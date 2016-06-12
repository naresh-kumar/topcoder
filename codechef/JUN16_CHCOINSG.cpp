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

class SieveOfEratosthenes {
  public:
    SieveOfEratosthenes(int N) {
      v = new bool[N];
      memset(v, 0, N);
      sp = new int[N];
      // Pierre Dusart showed that if x > 598 then
      int maxPrimes = N/log(N)*(1 + 1.2762/log(N));
      primes = new int[maxPrimes];
      count = 0;
      primes[count++] = 2;
      sp[1] = 1;
      sp[2] = 2;
      for (int i = 4; i < N; i += 2) {
        v[i] = true;
        sp[i] = 2;
      }
      for (int i = 3; i < N; i += 2) {
        if (v[i] == false) { // found new prime
          primes[count++] = i;
          sp[i] = i;
          for (ll j = i; (j*i) < N; j += 2) {
            if (v[j*i] == false) {
              v[j*i] = true;
              sp[j*i] = i;
            }
          }
        }
      }
    }

    vector<pii> factors(int n) {
      vector<pii> v;
      int x = sp[n];
      int count = 1;
      n = n/x;
      while (x > 1) {
        int y = sp[n];
        if (y != x) {
          v.push_back(make_pair(x, count));
          count = 0;
        }
        ++count;
        x = y;
        n = n/x;
      }
      return v;
    }

  public:
    bool* v; // is composite
    int* sp; // smallest prime
    int* primes;
    int count; // number of primes
};

int main() {
  //ios::sync_with_stdio(false);
  //cin.tie(NULL);
  int n = 10000;
  SieveOfEratosthenes soe(n+1);
  vi moves;
  moves.push_back(1);
  rep (i, 0, soe.count) {
    int prime = soe.primes[i];
    int move = prime;
    while (move < n+1) {
      moves.push_back(move);
      move = move * prime;
    }
  }
  sort(all(moves));
  bool dp[n+1];
  dp[0] = false;
  rep (i, 1, n+1) {
    dp[i] = false;
    rep(j, 0, moves.size()) {
      if (i - moves[j] < 0) {
        break;
      }
      if (dp[i - moves[j]] == false) {
        dp[i] = true;
        break;
      }
    }
  }
  int tests = si();
  rep (t, 0, tests) {
    int n = si();
    if (n%6==0) {
      cout << "Misha" << endl;
    } else {
      cout << "Chef" << endl;
    }
  }
  return 0;
}

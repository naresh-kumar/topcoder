//author Naresh
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

// fast input
#define gc getchar_unlocked
template<class T> inline int readnum() { int i=gc(),f=1; for(;i<'0'||i>'9';i=gc()) if(i=='-') { f=-1;i=gc();break; } T ret = 0; for(;i>='0'&&i<='9';i=gc()) { ret = ret*10 + (i-'0'); } return f*ret; }
inline int si() { return readnum<int>(); }
inline ll sll() { return readnum<ll>(); }
inline string ss() { string i=""; int c=gc(); while(c<'a'||c>'z') c=gc(); while(c>='a'&&c<='z') { i+=(char)c; c=gc(); } return i; }

// read and write
inline void svector(vector<int>& v, int n) { v.reserve(n); rep(i,0,n) v.push_back(si()); }
inline void sarray(int* v, int n) { rep(i,0,n) v[i] = si(); }
template<class T> inline void println(T t) { cout << t << endl; }
template<class T> inline void prints(T t) { cout << t << " "; }
template<class T> inline void print(T t) { cout << t; }
template<class T> inline void printlist(T l) { iter(i,l) prints(i); cout << endl; }
template<class T> inline void printlist(T *l, int n) { rep(i,0,n) prints(*(l+i)); cout << endl; }
template<class T> inline void printmap(T m) { iter(i,m) { prints(i.first); prints(i.second); } cout << endl; }

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
ll factorial(int x) { return (x < 2) ? 1 : x*factorial(x-1); }
ll getNcr(int n, int r) { return factorial(n)/(factorial(r) * factorial(n-r)); }
inline ll ipow(ll a, ll b, ll c = MOD) { ll r = 1; while(b) { if(b & 1) r = r*a % MOD; a = a*a % MOD; b >>= 1; } return r; }
inline ll inver(ll a,ll c = MOD) { ll ans = ipow(a,MOD-2); return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
int ncr[1][1];
void pascalTriangle() { rep(i, 0, 100) rep(j, 0, i+1) { if (j==0 || j==i) ncr[i][j] = 1; else ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % MOD; } }
inline bool almost_equal(double x, double y, int ulp) { return std::abs(x-y) < std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp || std::abs(x-y) < std::numeric_limits<double>::min(); }

// constants
const double PI = 3.14159265358979323846;
const int MAX_INF = (1LL << 31) - 1;
const int MIN_INF = (1LL << 31);
int MOD = 1E+9 + 7;

const int N = 100000;
bool arr[N+1];
int sp[N+1];
int pcount;
int primes[9600];
int pindex[N+1];
void SieveOfEratosthenes(int N) {
  pcount = 0;
  primes[pcount++] = 2;
  pindex[2] = pcount-1;
  sp[1] = 1;
  sp[2] = 2;
  for (int i = 4; i < N; i += 2) {
    arr[i] = false;
    sp[i] = 2;
  }
  for (int i = 3; i < N; i += 2) {
    if (arr[i] == 0) {
      primes[pcount++] = i;
      pindex[i] = pcount-1;
      sp[i] = i;
      for (ll j = i; (j*i) < N; j += 2){
        if (arr[j*i] == false) {
          arr[j*i] = true;
          sp[j*i] = i;
        }
      }
    }
  }
//  printf("%d\n", pcount);
//  printlist(primes, 20);
//  printlist(arr, 20);
//  printlist(sp, 20);
//  printlist(pindex, 20);
}

// 0th => 2,
// 13th prime => 43   43^3 < 100000
// 14th prime => 47   47^3 > 100000
// 64th prime => 313  313^2 < 100000
// 65th prime => 317  317^2 > 100000
const int f2 = 14;
const int f1 = 65;
char carray[f2][N+1];
int rmq[f2][N+1][17];

int mult[N+1];
int extra[N+1];
ll power[9600][18];

void pre() {
  rep(i, 0, 9600) rep(j, 0, 18) power[i][j] = 1;
  rep(p, 0, pcount) {
    ll ans = 1;
    ll max = N+1;
    for(int j = 1; j < 18 && ans < N+1; ++j) {
      ans *= primes[p];
      power[p][j] = ans;
    }
  }
  rep(i, 0, N+1) {
    mult[i] = 1;
    extra[i] = 1;
  }
  rep(i, 0, 1) {
    rep(k, 1, 18) {
      ll p = power[i][k];
      if (p > N) break;
      for (int j = p; j < N+1; j += p) {
        mult[j] = (mult[j] * (ll)p) % MOD;
      }
    }
  }
  rep(i, 0, 15) prints(i);
  cout << endl;
  printlist(mult, 15);
  rep(j, 1, N+1) {
    mult[j] = (mult[j] * (ll) mult[j-1]) % MOD;
  }
  printlist(mult, 15);
  rep(k, 2, N+1) {
    extra[k] = inver(mult[k]);
  }
}

ll solve(int n, int k) {
  if (k == 1) return n;
  //printf("%d %d %d %d %d\n", n, k, mult[n], mult[n-k], extra[k]);
  ll ans = (mult[n] * inver(mult[n-k])) % MOD;
  //ans = (ans * (ll) extra[k]) % MOD;
  return ans;
}

unordered_map<ll, int> cache;
int main() {
  int tests = si();
  int n = si();
  int k = si();
  int a = si();
  int b = si();
  int m = si();
  SieveOfEratosthenes(100000+1);
  pre();
  vi c, d;
  c.reserve(tests-1);
  d.reserve(tests-1);
  rep(i, 0, tests-1) c.push_back(si());
  rep(i, 0, tests-1) d.push_back(si());
  rep(test, 0, tests) {
    ll ans;
    ll ind = n*(ll)(N+1) + k;
    if (cache.find(ind) != cache.end()) ans = cache[ind];
    else ans = solve(n, k);
    cache[ind] = ans;
    printf("%d\n", ans);
    if (test != tests-1) {
      n = 1 + (a*ans + c[test]) % m;
      k = 1 + (b*ans + d[test]) % n;
    }
  }
  return 0;
}


// https://www.codechef.com/status/INTEST,nemausus
// https://www.codechef.com/viewplaintext/7391669
//author Naresh
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define all(a) a.begin(),a.end()
#define rep(i, a, b) for(int i=(a); i<(b); ++i)
#define irep(i, a, b) for(int i=(a); i>=(b); --i)
#define iter(i,v) for(auto i : (v))

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

template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template<class T> T factorial(T x) { return (x < 2) ? 1 : x*factorial(x-1); }
template<class T> inline T getNcr(T n, T r) { return factorial(n)/(factorial(r) * factorial(n-r)); }
template<class T> inline void setmax(T &a, T b) { if(b > a) a = b; }
template<class T> inline void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> inline bool isInGrid(T i, T j, T n) { return i>=0 && i<n && j>=0 && j<n; }
template<class T> inline bool isInside(T a, T b, T c) { return a > b && a < c; }

inline int si();
inline ll sll();
inline string ss();
inline void svector(vector<int>& v, int n) { v.reserve(n); rep(i,0,n) v.push_back(si()); }
inline void sarray(int* v, int n) { rep(i,0,n) v[i] = si(); }
template<class T> inline void println(T t) { cout << t << endl; }
template<class T> inline void prints(T t) { cout << t << " "; }
template<class T> inline void print(T t) { cout << t; }
template<typename T> void printlist(T l) {
  for (const auto& i : l) cout << i << " "; cout << endl;
}
template<typename T> void printlist(T* l, int size) {
  for (int i = 0; i < size; ++i) cout << *(l+i) << " "; cout << endl;
}
template<class T> void printmap(T m) {
  for (const auto& i : m) cout << i.first << " " << i.second << " ";
  cout << endl;
}

template<typename T> inline T reverse(T n) {
  T r = 0; while (n != 0) { r = r*10; r = r+n%10; n = n/10; } return r;
}
template<typename T> inline int firstdigit(T n) {
  int ans = 0; while (n != 0) { ans = n%10; n = n/10; } return ans;
}
template<typename T> inline int digits(T n) {
  int ans = 0; while (n != 0) { ans++; n = n/10; } return ans;
}
int frequency(string& str, char ch) {
  int ans = 0; rep(i,0,str.length()) if (str[i] == ch) ans++; return ans;
}

bool almost_equal(double x, double y, int ulp) {
  return std::abs(x-y) < std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp
    || std::abs(x-y) < std::numeric_limits<double>::min();
}
double randreal(double l, double u) {
  std::uniform_real_distribution<double> unif(l,u);
  static std::default_random_engine re(time(0));
  return unif(re);
}
inline int randint(int max) { return rand()%max; }
inline int randint(int min, int max) { return randint(max-min+1)+min; }

void computePascalTriangle();
int overlap(string& s1, string& s2);
ll ipow(ll a, ll b, ll c);
ll inver(ll a, ll c);

const double PI = 3.14159265358979323846;
const int MAX_INF = (1LL << 31) - 1;
const int MIN_INF = (1LL << 31);
const int MOD = 1E+7 + 9;

int main() {
  //srand(time(nullptr));
  //freopen("/Users/knaresh/codejam/codejam/in.txt", "r", stdin);
  //freopen("/Users/knaresh/codejam/codejam/out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
#endif
  int n = si();
  int k = si();
  int count = 0;
  int a;
  rep(i,0,n) {
    a = si();
    if(a%k == 0) ++count;
  }
  printf("%d\n", count);
  return 0;
}

void computePascalTriangle() {
  // move outside before use
  int ncr[4000][2000];
  for (int i = 0; i < 4000; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        ncr[i][j] = 1;
      else
        ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % MOD;
    }
  }
}

int overlap(string& s1, string& s2) {
  // 1 in case of single string
  int start = 0;
  int x = max(start, (int)(s1.length() - s2.length()));
  for(;x<s1.length(); ++x) {
    bool match = true;
    for(int i = x, j = 0; i<s1.length() && j<s2.length(); ++i,++j) {
      if(s1[i] != s2[j]) {
        match = false;
        break;
      }
    }
    if (match)
      return (int)s1.length() - x;
  }
  return 0;
}

ll ipow(ll a, ll b, ll c = MOD) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}

ll inver(ll a,ll c = MOD) {
  ll ans = ipow(a,MOD-2);
  return ans;
}

// start of fast input
#define gc getchar_unlocked
template<class T>
inline int readnum() {
  int i=gc(),f=1;
  for(;i<'0'||i>'9';i=gc())
    if(i=='-') {
      f=-1;i=gc();break;
    }
  T ret = 0;
  for(;i>='0'&&i<='9';i=gc()) {
    ret = ret*10 + (i-'0');
  }
  return f*ret;
}
inline int si() { return readnum<int>(); }
inline ll sll() { return readnum<ll>(); }
inline string ss() {
  string i="";
  int c=gc();
  while(c<'a'||c>'z')
    c=gc();
  while(c>='a'&&c<='z') {
    i+=(char)c;
    c=gc();
  }
  return i;
}
//end of fast input

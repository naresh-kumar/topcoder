// https://www.codechef.com/AUG15/status/DISTNUM,nemausus
// https://www.codechef.com/viewplaintext/7841382
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

// read and write
inline int si();
inline ll sll();
inline string ss();
inline void svector(vector<int>& v, int n) { v.reserve(n); rep(i,0,n) v.push_back(si()); }
inline void sarray(int* v, int n) { rep(i,0,n) v[i] = si(); }
template<class T> inline void println(T t) { cout << t << endl; }
template<class T> inline void prints(T t) { cout << t << " "; }
template<class T> inline void print(T t) { cout << t; }
template<class T> inline void printlist(T l) { iter(i,l) prints(i); cout << endl; }
template<class T> inline void printlist(T *l, int n) { rep(i,0,n) prints(*(l+i)); cout << endl; }
template<class T> inline void printmap(T m) { iter(i,m) { prints(i.first); prints(i.second); } cout << endl; }

template<class T> inline void setmax(T &a, T b) { if(b > a) a = b; }
template<class T> inline void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> inline bool isInGrid(T i, T j, T n) { return i>=0 && i<n && j>=0 && j<n; }
template<class T> inline bool isInside(T a, T b, T c) { return a > b && a < c; }
template<class T> inline T reverse(T n) { T r = 0; while (n != 0) { r = r*10; r = r+n%10; n = n/10; } return r; }
template<class T> inline int firstdigit(T n) { int r = 0; while (n != 0) { r = n%10; n = n/10; } return r; }
template<class T> inline int digits(T n) { int r = 0; while (n != 0) { ++r; n /= 10; } return r; }
inline int frequency(string& s, char c) { int r = 0; rep(i,0,s.length()) if (s[i] == c) ++r; return r; }

const int MOD = 1E+9 + 7;
ll factorial(int x) { return (x < 2) ? 1 : x*factorial(x-1); }
ll getNcr(int n, int r) { return factorial(n)/(factorial(r) * factorial(n-r)); }
ll ipow(ll a, ll b, ll c = MOD) { ll r = 1; while(b) { if(b & 1) r = r*a % MOD; a = a*a % MOD; b >>= 1; } return r; }
ll inver(ll a,ll c = MOD) { ll ans = ipow(a,MOD-2); return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

int ncr[4][4];
void pascalTriangle() {
  rep(i, 0, 4) rep(j, 0, i+1) { if (j==0 || j==i) ncr[i][j] = 1; else ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % MOD; }
}
bool almost_equal(double x, double y, int ulp) {
  return std::abs(x-y) < std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp
    || std::abs(x-y) < std::numeric_limits<double>::min();
}

const double PI = 3.14159265358979323846;
const int MAX_INF = (1LL << 31) - 1;
const int MIN_INF = (1LL << 31);

const int MAXN = 100005, MAXLGN = 20;

int tree[MAXN];
struct node {
  int val, L, R, size;
} buff[2 * MAXN * MAXLGN];

map< int, int > pos;
int cant;

int build( int lo, int hi ) {
  if ( lo > hi ) return 0;

  int idx = ++cant;

  int mid = ( lo + hi ) / 2;
  buff[idx] = (node){ mid, build( lo, mid - 1 ), build( mid + 1, hi ), 0 };
  return idx;
}

int update( int x, int val, int amount ) {

  if ( x == 0 ) return 0;

  int idx = ++cant;

  int L = buff[x].L;
  int R = buff[x].R;
  if ( val < buff[x].val ) L = update( L, val, amount );
  if ( val > buff[x].val ) R = update( R, val, amount );

  buff[idx] = (node){ buff[x].val, L, R, buff[x].size + amount };

  return idx;
}

int query( int x, int val ) {
  if ( val < buff[x].val )
    return query( buff[x].L, val ) + buff[x].size - buff[ buff[x].L ].size;

  if ( val > buff[x].val )
    return query( buff[x].R, val );

  return buff[x].size - buff[ buff[x].L ].size;
}

int main() {
  int n = si();
  int q = si();
  vi v;
  v.reserve(n+1);
  v.push_back(-1);
  rep(i, 0, n) v.push_back(si());
  tree[0] = build( 1, n );
  for (int i = 1; i <= n; i++) {
    int x=v[i], posx;
    posx = pos[x];
    if ( posx != 0 )
      tree[i] = update( update( tree[i - 1], posx, -1 ), i, +1 );
    else
      tree[i] = update( tree[i - 1], i, +1 );
    pos[x] = i;
  }
  int types[6] = {0,0,0,0,0,0};
  rep(i, 0, q) {
    int type = si();
    types[type]++;
    if (type == 1) {
      int l = si();
      int r = si();
      vi range(v.begin()+l, v.begin()+r+1);
      sort(all(range));
      auto it = unique(all(range));
      ll ans = 0;
      if (it - range.begin() > 2) {
        ll mul = (range[0] * (ll)range[1]) % MOD;
        ll sum = (range[0] + (ll)range[1]) % MOD;
        ans = (mul * range[2]) % MOD;
        for (auto i = range.begin() + 3; i < it; ++i) {
          ll curr = *i;
          ll prev = *(i-1);
          mul = (mul + (prev * sum)%MOD)%MOD;
          sum = (sum + prev)%MOD;
          ans = (ans + (curr * mul)%MOD)%MOD;
        }
      }
      printf("%lld\n", ans);
    } else if (type == 2) {
      int x = si();
      int y = si();
      v[x] = y;
    } else if (type == 3) {
      int x = si();
      v.erase(v.begin() + x);
    } else if (type == 4) {
      int z = si();
      int y = si();
      v.insert(v.begin() + z + 1, y);
    } else if (type == 5) {
      int l = si();
      int r = si();
      printf("%d\n", query(tree[r], l));
    }
  }
  return 0;
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

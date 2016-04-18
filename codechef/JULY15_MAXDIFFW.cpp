// https://www.codechef.com/JULY15/status/MAXDIFFW,nemausus
// https://www.codechef.com/viewplaintext/7472232
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

const int MOD = 1E+7 + 7;
ll factorial(int x) { return (x < 2) ? 1 : x*factorial(x-1); }
ll getNcr(int n, int r) { return factorial(n)/(factorial(r) * factorial(n-r)); }
ll ipow(ll a, ll b, ll c = MOD) { ll r = 1; while(b) { if(b & 1) r = r*a % MOD; a = a*a % MOD; b >>= 1; } return r; }
ll inver(ll a,ll c = MOD) { ll ans = ipow(a,MOD-2); return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

int ncr[4][4];
void pascalTriangle() {
  rep(i, 0, 4) rep(j, 0, i+1) { if (j==0 || j==i) ncr[i][j] = 1; else ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % MOD; }
}

const double PI = 3.14159265358979323846;
const int MAX_INF = (1LL << 31) - 1;
const int MIN_INF = (1LL << 31);

int graph[51][51];
int seen[51][51];
int getNext(int i, int n) {
  int cost = MIN_INF;
  int v = 0;
  rep(j, 1, n+1) {
    if(!seen[i][j] && i != j) {
      if (graph[i][j] > cost) {
        v = j;
        cost = graph[i][j];
      }
    }
  }
  return v;
}
int last;
pii getBest(int i, int n) {
  last = 0;
  int diff = MIN_INF;
  int v = 0;
  rep(j, 1, n+1) {
    if(!seen[i][j] && i != j) {
      int next = getNext(j, n);
      if ((graph[i][j] - graph[j][next]) > diff) {
        v = j;
        diff = graph[i][j] - graph[j][next];
        last = next;
      }
    }
  }
  return make_pair(v, diff);
}

pii getBest2(int i, int n) {
  int diff = MIN_INF;
  int v = 0;
  rep(j, 1, n+1) {
    if(!seen[i][j] && i != j) {
      int next = getNext(j, n);
      pii next2 = getBest(next, n);
      if ((i == next && j == next2.first) || (i == next2.first && j == last) || (next2.first == j && next == last)) next2.second = 0;
      if ((graph[i][j] - graph[j][next] + next2.second) > diff) {
        v = j;
        diff = graph[i][j] - graph[j][next] + next2.second;
      }
    }
  }
  return make_pair(v, diff);
}

int main() {
  int n;
  scanf("%d",&n);
  int from = 0;
  int mcost = (n * (n+1))/2;
  rep(i, 1, n+1) rep(j, 1, n+1) {
    int temp;
    scanf("%d",&temp);
    graph[i][j] = temp;
    if (temp == mcost)
      from = i;
  }
  int to = 0;
  int ms = 0;
  int js = 0;
  int cost = MIN_INF;
  rep (i, 1, n+1) {
    int next = getBest(i, n).first;
    if (cost < graph[i][next]) {
      from = i;
      cost = graph[i][next];
    }
  }
  int count = 1;
  int random = false;
  while(true) {
    if (count > 10 && count%2 == 0 && count < 500 && random == false) to = getBest2(from, n).first;
    else to = getBest(from, n).first;
    if (to == 0) break;
    seen[from][to] = 1;
    ms += graph[from][to];
    printf("%d %d\n",from, to);
    fflush(stdout);
    int predict = getNext(to,n);
    if (predict == 0) break;
    scanf("%d %d",&from, &to);
    if (predict != to) random = true;
    seen[from][to] = 1;
    js += graph[from][to];
    from = to;
    ++count;
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

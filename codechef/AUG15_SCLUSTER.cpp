// https://www.codechef.com/AUG15/status/SCLUSTER,nemausus
// https://www.codechef.com/viewplaintext/7838712
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
template<class T> inline void printlist(T *l, int n) { rep(i,0,n) {if (i!=n-1) prints(*(l+i)); else print(*(l+i));} cout << endl; }
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
inline bool isPrime(int number) {
  if (((!(number & 1)) && number != 2) || (number < 2) || (number % 3 == 0 && number != 3)) {
    return false;
  }

  for (int k = 1; 36*k*k-12*k < number; ++k) {
    if ((number % (6*k+1) == 0) || (number % (6*k-1) == 0)) {
      return false;
    }
  }
  return true;
}

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

int grid[60][60];
int inter[2001];
double cost[2001];
int row[61];
int col[61];
double rowcost[61];
int main() {
  int tests = si();
  while(tests--) {
    memset(grid, 0, sizeof(grid));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    rep(i, 0, 61) rowcost[i] = 0.0;
    int n = si();
    int k = si();
    rep(i, 0, n) {
      rep(j, 0, n) {
        grid[i][j] = si();
        row[i] += (grid[i][j] ? 1 : 0);
        col[j] += (grid[i][j] ? 1 : 0);
      }
    }
    double totalm = 0.0;
    rep(i, 0, k) {
      inter[i] = si();
      cost[i] = 25.0/inter[i];
      totalm += cost[i];
    }
    double sumx = 0.0;
    double sumy = 0.0;
    rep(i, 0, n) {
      rep(j, 0, n) {
        if (grid[i][j]) {
          sumx += i*cost[grid[i][j]-1];
          sumy += j*cost[grid[i][j]-1];
          rowcost[i] += cost[grid[i][j]-1];
        }
      }
    }
    int centerx = round(sumx/totalm);
    int centery = round(sumy/totalm);

    rep(i, centerx, n) {
      if (row[i] > 0) continue;
      double min = 10000000.0;
      int index = -1;
      rep(j, i+1, n) {
        if (row[j] && rowcost[j]*(j-i) < min) {
          index = j;
          min = rowcost[j]*(j-i);
        }
      }
      if (index != -1) {
        memcpy(grid[i], grid[index], 4 * n);
        memset(grid[index], 0, 4 * n);
        row[i] = row[index];
        row[index] = 0;
      }
    }

    irep(i, centerx, 0) {
      if(row[i] > 0) continue;
      double min = 10000000.0;
      int index = -1;
      irep(j, i-1, 0) {
        if (row[j] && rowcost[j]*(i-j) < min) {
          index = j;
          min = rowcost[j]*(i-j);
        }
      }
      if (index != -1) {
        memcpy(grid[i], grid[index], 4 * n);
        memset(grid[index], 0, 4 * n);
        row[i] = row[index];
        row[index] = 0;
      }
    }

    rep(i, 0, n) {
      rep(j, centery, n) {
        if (grid[i][j] > 0) continue;
        double min = 20000.0;
        int index = -1;
        rep(k, j+1, n) {
          if (grid[i][k] && cost[grid[i][k]-1]*(k-j) < min) {
            index = k;
            min = cost[grid[i][k]-1]*(k-j);
          }
        }
        if (index != -1) {
          grid[i][j] = grid[i][index];
          grid[i][index] = 0;
        }
      }

      irep(j, centery, 0) {
        if (grid[i][j] > 0) continue;
        double min = 20000.0;
        int index = -1;
        irep(k, j-1, 0) {
          if (grid[i][k] && cost[grid[i][k]-1]*(j-k) < min) {
            index = k;
            min = cost[grid[i][k]-1]*(j-k);
          }
        }
        if (index != -1) {
          grid[i][j] = grid[i][index];
          grid[i][index] = 0;
        }
      }
    }

    rep(i, 0, n) {
      printlist(grid[i], n);
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

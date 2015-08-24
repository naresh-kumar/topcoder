//author Naresh
#include <algorithm>
#include <bitset>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
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
#include <cassert>

using namespace std;

#define si(x) ((int)x.size())
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a, b)
#define all(a) a.begin(),a.end()
#define ss ({int x;scanf("%d", &x);x;})
#define ssl ({long long int x;scanf("%lld", &x);x;})
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

template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> bool isInGrid(T i, T j, T n) { return i>=0 && i<n && j>=0 && j<n; }
template<class T> bool isInside(T a, T b, T c) { return a > b && a < c; }
struct Point { int x; int y; };
template<class T> void printmap(T m) {
  for (const auto& i : m) cout << i.first << " " << i.second << " ";
  cout << endl;
}
template<typename T> void printlist(T l) {
  for (const auto& i : l) cout << i << " "; cout << endl;
}
template<typename T> void printlist(T* l, int size) {
  for (int i = 0; i < size; ++i) cout << *(l+i) << " "; cout << endl;
}
template<typename T> T reverse(T n) {
  T r = 0; while (n != 0) { r = r*10; r = r+n%10; n = n/10; } return r;
}
template<typename T> int firstdigit(T n) {
  int ans = 0; while (n != 0) { ans = n%10; n = n/10; } return ans;
}
template<typename T> int digits(T n) {
  int ans = 0; while (n != 0) { ans++; n = n/10; } return ans;
}
int frequency(string& str, char ch) {
  int ans = 0; rep(i,0,str.length()) if (str[i] == ch) ans++; return ans;
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

bool almost_equal(double x, double y, int ulp) {
  return std::abs(x-y) < std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp
    || std::abs(x-y) < std::numeric_limits<double>::min();
}

double drand(double l, double u) {
  std::uniform_real_distribution<double> unif(l,u);
  static std::default_random_engine re;
  return unif(re);
}

ll factorial(ll x) { return (x < 2) ? 1 : x*factorial(x-1); }

ll getNcr(ll n, ll r) {
  return factorial(n)/(factorial(r) * factorial(n-r));
}

int mod = 1000007;
void pascalTriangle() {
  int ncr[4000][2000];
  for (int i = 0; i < 4000; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        ncr[i][j] = 1;
      else
        ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % mod;
    }
  }
}

#define SIZE 1024*128
#define INF  (1LL << 31) - 1;
#define PI  3.14159265358979323846  /* pi */

char buffer[SIZE];
int buffer_size;
int pointer = 0;
int max_digits = 12;
int nextInt() {
  int num = 0;
  char c;
  int r = buffer_size - pointer;
  if (r < max_digits) {
    memcpy(buffer, buffer + pointer, r);
    buffer_size = r + fread(buffer + r, 1, SIZE-r, stdin);
    pointer = 0;
  }
  while(true) {
    c = buffer[pointer];
    if (c == '\n' || c == ' ') {
      ++pointer;
      return num;
    } else {
      num = num*10 + c - '0';
    }
    ++pointer;
  }
}
int arr[100000];
int main() {
  //freopen("/Users/knaresh/codejam/codejam/in.txt", "r", stdin);
  //freopen("/Users/knaresh/codejam/codejam/out.txt", "w", stdout);
  //buffer_size = fread(buffer, 1, SIZE, stdin);
  int n = ss;
  int q = ss;
  int sum = 0;
  rep(i, 0, n) {
    sum += ss;
    arr[i] = sum;
  }
  int l,r;
  rep(i, 0, q) {
    l = ss;
    r = ss;
    abs(arr[r-1] - (l == 1 ? 0 : arr[l-2])) % 2 == 0 ? cout << "Even" : cout << "Odd";
    cout << endl;
  }
  return 0;
}

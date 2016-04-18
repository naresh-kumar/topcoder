// https://www.codechef.com/JULY15/status/ADDMUL,nemausus
// https://www.codechef.com/viewplaintext/7391757
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
const int mod = 1E+9 + 7;
const int MOD = 1E+9 + 7;

ll arr[100000];
ll tree[262150];
ll add[262150];
ll mul[262150];
ll val[262150];

void build_tree(int node, int a, int b) {
  if(a > b) return; // Out of range

  if(a == b) { // Leaf node
    tree[node] = arr[a]; // Init value
    return;
  }

  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

  tree[node] = (tree[node*2] + tree[node*2+1])%mod; // Init root value
}

void propagate(int node, int a, int b, int i, int j) {
  ll count = b-a+1;
  if (val[node] != 0) {
    tree[node] = (val[node] * count)%mod;
    if(a != b) {
      mul[node*2] = 1;
      mul[node*2+1] = 1;
      add[node*2] = 0;
      add[node*2+1] = 0;
      val[node*2] = val[node];
      val[node*2+1] = val[node];
    }
    val[node] = 0;
  }
  if(mul[node] > 1) { // This node needs to be updated
    tree[node] = (tree[node] * mul[node])%mod;

    if (a != b) {
      mul[node*2] = (mul[node*2] * mul[node])%mod; // Mark child as lazy
      mul[node*2+1] = (mul[node*2+1] * mul[node])%mod; // Mark child as lazy
      add[node*2] = (add[node*2] * mul[node])%mod; // Mark child as lazy
      add[node*2+1] = (add[node*2+1] * mul[node])%mod; // Mark child as lazy
    }

    mul[node] = 1; // Reset it
  }
  if(add[node] != 0) { // This node needs to be updated
    tree[node] = (tree[node] + (add[node] * count)%mod)%mod; // Update it

    if(a != b) {
      add[node*2] = (add[node*2] + add[node])%mod; // Mark child as lazy
      add[node*2+1] = (add[node*2+1] + add[node])%mod; // Mark child as lazy
    }

    add[node] = 0; // Reset it
  }
}

void update_tree(int node, int a, int b, int i, int j, ll value, int type) {
  propagate(node, a, b, i, j);
  if(a > b || a > j || b < i) // Current segment is not within range [i, j]
    return;

  ll count = b-a+1;
  if(a >= i && b <= j) { // Segment is fully within range
    if (type == 1) {
      tree[node] = (tree[node] + (value * count)%mod)%mod;
      if(a != b) { // Not leaf node
        add[node*2] = (add[node*2] + value)%mod;
        add[node*2+1] = (add[node*2+1] + value)%mod;
      }
    }
    if (type == 2) {
      tree[node] = (tree[node] * value)%mod;
      if(a != b) { // Not leaf node
        mul[node*2] = (mul[node*2] * value)%mod;
        mul[node*2+1] = (mul[node*2+1] * value)%mod;
        add[node*2] = (add[node*2] * value)%mod;
        add[node*2+1] = (add[node*2+1] * value)%mod;
      }
    }
    if (type == 3) {
      tree[node] = (value * count)%mod;
      if(a != b) { // Not leaf node
        mul[node*2] = 1;
        mul[node*2+1] = 1;
        add[node*2] = 0;
        add[node*2+1] = 0;
        val[node*2] = value;
        val[node*2+1] = value;
      }
    }

    return;
  }

  update_tree(node*2, a, (a+b)/2, i, j, value, type); // Updating left child
  update_tree(1+node*2, 1+(a+b)/2, b, i, j, value, type); // Updating right child

  tree[node] = (tree[node*2] + tree[node*2+1])%mod; // Updating root with max value
}

ll query_tree(int node, int a, int b, int i, int j) {

  if(a > b || a > j || b < i) return 0; // Out of range
  propagate(node, a, b, i, j);

  if(a >= i && b <= j) // Current segment is totally within range [i, j]
    return tree[node];

  ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
  ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

  return (q1 + q2)%mod;
}

int main() {
  //freopen("/Users/knaresh/codejam/codejam/in.txt", "r", stdin);
  //freopen("/Users/knaresh/codejam/codejam/out.txt", "w", stdout);
  //buffer_size = fread(buffer, 1, SIZE, stdin);
  int n = si();
  int q = si();
  int type, x, y, v;
  rep(i, 0, n) arr[i] = si();
  rep(i, 0, 262150) mul[i] = 1;
  build_tree(1, 0, n-1);
  rep(i, 0, q) {
    type = si();
    x = si()-1;
    y = si()-1;
    if (type == 4) {
//      ll sum = 0;
//      rep(j,x,y+1) {
//        sum += arr[j];
//        sum %= mod;
//      }
//      ll expected = sum%mod;
      ll actual = query_tree(1, 0, n-1, x, y);
      cout << actual << endl;
//      cout << expected << endl;
//      if (expected != actual)
//        printf("expected %d, actual %d\n", expected, actual);
    }
    else {
      v = si();
      update_tree(1, 0, n-1, x, y, v, type);
//      rep(j,x,y+1) {
//        if (type == 1) arr[j] += v;
//        if (type == 2) arr[j] *= v;
//        if (type == 3) arr[j] = v;
//        arr[j] %= mod;
//      }
    }
  }
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

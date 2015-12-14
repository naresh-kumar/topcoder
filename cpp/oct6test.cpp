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
int ncr[4][4];
void pascalTriangle() { rep(i, 0, 4) rep(j, 0, i+1) { if (j==0 || j==i) ncr[i][j] = 1; else ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % MOD; } }
inline bool almost_equal(double x, double y, int ulp) { return std::abs(x-y) < std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp || std::abs(x-y) < std::numeric_limits<double>::min(); }

// constants
const double PI = 3.14159265358979323846;
const int MAX_INF = (1LL << 31) - 1;
const int MIN_INF = (1LL << 31);
int MOD = 1E+7 + 7;

set<string> perms;
void revert(string& s, int start, int k) {
  auto curr = s[start];
  rep(i, start+1, start+k) {
    s[i-1] = s[i];
  }
  s[start+k-1] = curr;
}
void rotate(string& s, int start, int k) {
  auto curr = s[start];
  s[start] = s[start+k-1];
  rep(i, start+1, start+k) {
    swap(curr, s[i]);
  }
}
void findall(string& s, int k) {
  perms.insert(s);
  queue<string> qu;
  qu.push(s);
  while(qu.size()) {
    string s = qu.front();
    qu.pop();
    rep(i, 0, s.length()-k+1) {
      rotate(s, i, k);
      if (perms.find(s) == perms.end()) {
        perms.insert(s);
        qu.push(s);
      }
      revert(s, i, k);
    }
  }
}

typedef struct node_t node_t;

/* Binary tree node */
struct node_t {
    int data;
    int lCount;

    node_t* left;
    node_t* right;
};

/* Iterative insertion
   Recursion is least preferred unless we gain something
*/
node_t *insert_node(node_t *root, node_t* node) {
    /* A crawling pointer */
    node_t *pTraverse = root;
    node_t *currentParent = root;

    // Traverse till appropriate node
    while(pTraverse) {
        currentParent = pTraverse;
        if( node->data < pTraverse->data ) {
            /* We are branching to left subtree
               increment node count */
            pTraverse->lCount++;
            /* left subtree */
            pTraverse = pTraverse->left;
        } else {
            /* right subtree */
            pTraverse = pTraverse->right;
        }
    }

    /* If the tree is empty, make it as root node */
    if( !root ) {
        root = node;
    }
    else if( node->data < currentParent->data ) {
        /* Insert on left side */
        currentParent->left = node;
    } else {
        /* Insert on right side */
        currentParent->right = node;
    }

    return root;
}

int getLCount(node_t* root, int n) {
  node_t* curr = root;
  int ans = 0;
  while(curr) {
    if (curr->data == n) return ans + curr->lCount;
    else if (n < curr->data) {
      curr = curr->left;
    } else {
      ans += 1 + curr->lCount;
      curr = curr->right;
    }
  }
  return 0;
}

int FACT[100001];
pair<int, bool> getRank(string s) {
  int n = s.length();
  node_t* root = nullptr;
  ll rank = 1;
  bool odd = true;
  int next = n;
  int small = 0;
  int size = 0;
  rep(i, 0, n-1) {
    int curr = s[i] - '0';
    ll count = curr - 1;
    if (next == curr) {
      --next;
      count -= size + small;
    } else if (small + 1 == curr) {
      ++small;
      count = 0;
    } else {
      node_t* new_node = (node_t *)malloc( sizeof(node_t) );

      /* initialize */
      new_node->data   = curr;
      new_node->lCount = 0;
      new_node->left   = nullptr;
      new_node->right  = nullptr;

      /* insert into BST */
      root = insert_node(root, new_node);
      count -= getLCount(root, curr) + small;
      ++size;
    }
    //printf("%d %d\n", curr, count);
    if (count%2 == 1 && n-i-1 == 1) {
      odd = !odd;
    }
    rank = (rank + (count * FACT[n-i-1])%MOD)%MOD;
  }
  return make_pair(rank, odd);
}
int main() {
  FACT[0] = 1;
  rep(i, 1, 100002) {
    FACT[i] = (FACT[i-1]*(ll)i)%MOD;
  }
  string s = "123456";
  findall(s, 2);
  vs fullset(all(perms));
  sort(all(fullset));
  perms.clear();

  findall(s, 3);
//  s = "1234576";
//  findall(s, 3);
  vs sorted(all(perms));
  sort(all(sorted));
  int lindex = 0;
  rep(i, 0, sorted.size()) {
    int index = find(all(fullset), sorted[i]) - fullset.begin()+1;
    int missed = index-lindex-1;
    rep(i, 0, missed) {
      string blank(s.size(), missed == 1 ? '#' : '-');
      printf("%s %d %d\n", blank.c_str(), lindex + i + 1, lindex + i + 1 - getRank(fullset[lindex+i]).first);
    }
    int myindex = (index-2+(index&1))/2;
    if (missed > 2 || myindex != i) {
      throw std::runtime_error("WTF");
    }

    printf("%s %d %d\n", sorted[i].c_str(), index, index - getRank(fullset[index-1]).first);
    lindex = index;
  }
}


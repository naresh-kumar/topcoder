// Author: Naresh
#include <algorithm>
#include <bitset>
#include <climits>
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
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define irep(i, a, b) for (int i = (a); i >= (b); --i)
#define iter(i, v) for (auto& i : (v))

typedef long long ll;

///////////////////////////////////////////////////////////////////////////////

// constants
const double PI = 3.141592653589793238463;
ll MOD = 1E+9 + 7;

template <class T> T reverse(T n) { T r = 0; while (n != 0) { r = r * 10; r = r + n % 10; n = n / 10; } return r; }
template <class T> int firstdigit(T n) { int r = 0; while (n != 0) { r = n % 10; n = n / 10; } return r; }
int digits(ll n) { if (n) return log10(abs(n)) + 1; return 0; }
int frequency(string& s, char c) { int r = 0; rep(i, 0, s.length()) if (s[i] == c)++ r; return r; }
// multiply add mod
template <class T> T mam(T a, T b, T c) { return ((a * b) % MOD + c) % MOD; }
ll factorial(int x) { return (x < 2) ? 1 : x * factorial(x - 1); }
ll ncr(int n, int r) { return factorial(n) / (factorial(r) * factorial(n - r)); }
ll ipow(ll a, ll b, ll c = MOD) { ll r = 1; while (b) { if (b & 1) r = r * a % MOD; a = a * a % MOD; b >>= 1; } return r; }
ll inver(ll a, ll c = MOD) { ll ans = ipow(a, MOD - 2); return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

bool almost_equal(double x, double y, int ulp = 4) {
  return abs(x - y) < numeric_limits<double>::epsilon() * abs(x + y) * ulp ||
         abs(x - y) < numeric_limits<double>::min();
}

// To get ncr % MOD using PascalTriagle
class PascalTriagle {
 public:
  int** ncr;
  PascalTriagle(int N) {
    ncr = new int*[N];
    for (int i = 0; i < N; ++i) {
      ncr[i] = new int[N];
    }
    // maybe need init
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < i + 1; ++j)
        if (j == 0 || j == i)
          ncr[i][j] = 1;
        else
          ncr[i][j] = (ncr[i - 1][j - 1] + (ll)ncr[i - 1][j]) % MOD;
  }
};

class SieveOfEratosthenes {
 public:
  bool* v;  // is composite
  int* sp;  // smallest prime
  int* primes;
  int count;  // number of primes
  SieveOfEratosthenes(int N) {
    v = new bool[N];
    memset(v, 0, N);
    sp = new int[N];
    // Pierre Dusart showed that if x > 598 then
    int maxPrimes = N / log(N) * (1 + 1.2762 / log(N));
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
      if (v[i] == false) {  // found new prime
        primes[count++] = i;
        sp[i] = i;
        for (ll j = i; (j * i) < N; j += 2) {
          if (v[j * i] == false) {
            v[j * i] = true;
            sp[j * i] = i;
          }
        }
      }
    }
  }

  vector<pair<int, int>> factors(int n) {
    vector<pair<int, int>> v;
    int x = sp[n];
    int count = 1;
    n = n / x;
    while (x > 1) {
      int y = sp[n];
      if (y != x) {
        v.push_back(make_pair(x, count));
        count = 0;
      }
      ++count;
      x = y;
      n = n / x;
    }
    return v;
  }
};

template <class T>
class SegmentTree {
 public:
  SegmentTree(int n) : n(n) {
    height = (int)(ceil(log2(n)));           // Height of segment tree
    max_size = 2 * (int)pow(2, height) - 1;  // Maximum size of segment tree
    tree = new int[max_size];
    mul = new int[max_size];
    add = new int[max_size];
    val = new int[max_size];
    memset(tree, 0, max_size * sizeof(T));
    memset(add, 0, max_size * sizeof(T));
    memset(mul, 0, max_size * sizeof(T));
    memset(val, 0, max_size * sizeof(T));
  }

  // initialize tree with array.
  void initialize(T* arr) { build_tree(1, 0, n - 1, arr); }

  void build_tree(int node, int a, int b, T* arr) {
    if (a > b) return;  // Out of range

    if (a == b) {           // Leaf node
      tree[node] = arr[a];  // Init value
      return;
    }

    build_tree(node * 2, a, (a + b) / 2, arr);          // Init left child
    build_tree(node * 2 + 1, 1 + (a + b) / 2, b, arr);  // Init right child

    // Init root value with sum of its children
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
  }

  // query range [i,j]
  T query_tree(int node, int a, int b, int i, int j) {
    if (a > b || a > j || b < i) return 0;  // Out of range
    propagate(node, a, b, i, j);

    if (a >= i && b <= j)  // Current segment is totally within range [i, j]
      return tree[node];

    T q1 = query_tree(node * 2, a, (a + b) / 2, i, j);  // Query left child
    T q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i,
                      j);  // Query right child

    return (q1 + q2) % MOD;
  }

  void update_tree(int node, int a, int b, int i, int j, T value, int type) {
    propagate(node, a, b, i, j);
    if (a > b || a > j || b < i)  // Current segment is not within range [i, j]
      return;

    T count = b - a + 1;
    if (a >= i && b <= j) {  // Segment is fully within range
      if (type == 1) {       // add
        tree[node] = (tree[node] + (value * count) % MOD) % MOD;
        if (a != b) {  // Not leaf node
          add[node * 2] = (add[node * 2] + value) % MOD;
          add[node * 2 + 1] = (add[node * 2 + 1] + value) % MOD;
        }
      }
      if (type == 2) {  // multiply
        tree[node] = (tree[node] * value) % MOD;
        if (a != b) {  // Not leaf node
          mul[node * 2] = (mul[node * 2] * value) % MOD;
          mul[node * 2 + 1] = (mul[node * 2 + 1] * value) % MOD;
          add[node * 2] = (add[node * 2] * value) % MOD;
          add[node * 2 + 1] = (add[node * 2 + 1] * value) % MOD;
        }
      }
      if (type == 3) {  // set
        tree[node] = (value * count) % MOD;
        if (a != b) {  // Not leaf node
          mul[node * 2] = 1;
          mul[node * 2 + 1] = 1;
          add[node * 2] = 0;
          add[node * 2 + 1] = 0;
          val[node * 2] = value;
          val[node * 2 + 1] = value;
        }
      }
      return;
    }

    // Updating left child
    update_tree(node * 2, a, (a + b) / 2, i, j, value, type);
    // Updating right child
    update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value, type);
    // Updating root with sum
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
  }

  void propagate(int node, int a, int b, int i, int j) {
    T count = b - a + 1;
    if (val[node] != 0) {
      tree[node] = (val[node] * count) % MOD;
      if (a != b) {
        mul[node * 2] = 1;
        mul[node * 2 + 1] = 1;
        add[node * 2] = 0;
        add[node * 2 + 1] = 0;
        val[node * 2] = val[node];
        val[node * 2 + 1] = val[node];
      }
      val[node] = 0;
    }
    if (mul[node] > 1) {  // This node needs to be updated
      tree[node] = (tree[node] * mul[node]) % MOD;

      if (a != b) {
        mul[node * 2] =
            (mul[node * 2] * mul[node]) % MOD;  // Mark child as lazy
        mul[node * 2 + 1] =
            (mul[node * 2 + 1] * mul[node]) % MOD;  // Mark child as lazy
        add[node * 2] =
            (add[node * 2] * mul[node]) % MOD;  // Mark child as lazy
        add[node * 2 + 1] =
            (add[node * 2 + 1] * mul[node]) % MOD;  // Mark child as lazy
      }

      mul[node] = 1;  // Reset it
    }
    if (add[node] != 0) {  // This node needs to be updated
      tree[node] = (tree[node] + (add[node] * count) % MOD) % MOD;  // Update it

      if (a != b) {
        add[node * 2] =
            (add[node * 2] + add[node]) % MOD;  // Mark child as lazy
        add[node * 2 + 1] =
            (add[node * 2 + 1] + add[node]) % MOD;  // Mark child as lazy
      }

      add[node] = 0;  // Reset it
    }
  }

  int n;
  int height;
  int max_size;
  T* tree;
  T* add;
  T* mul;
  T* val;
};

// https://www.codechef.com/OCT15/status/PERSHFTS,nemausus
// https://www.codechef.com/viewplaintext/8475337
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
int MOD = 1E+9 + 7;

int FACT[100005];
int P[100000];
int Q[100000];

ll  _mergeSort(int arr[], int temp[], int left, int right);
ll merge(int arr[], int temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
 *    number of inversions in the array */
ll mergeSort(int arr[], int array_size) {
  int *temp = (int *)malloc(sizeof(int)*array_size);
  return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
 *   returns the number of inversions in the array. */
ll _mergeSort(int arr[], int temp[], int left, int right) {
  int mid;
  ll inv_count = 0;
  if (right > left) {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
     *        for each of the parts */
    mid = (right + left)/2;

    /* Inversion count will be sum of inversions in left-part, right-part
     *       and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

/* This funt merges two sorted arrays and returns inversion count in
 *    the arrays.*/
ll merge(int arr[], int temp[], int left, int mid, int right) {
  int i, j, k;
  ll inv_count = 0;

  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    }
    else {
      temp[k++] = arr[j++];

      /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }

  /* Copy the remaining elements of left subarray
   *    (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  /* Copy the remaining elements of right subarray
   *    (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];

  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

bool check(int n) {
  ll inv1 = 0;
  ll inv2 = 0;
  int *temp = (int *)malloc(sizeof(int)*n);
  memcpy(temp, P, n*sizeof(int));
  inv1 = mergeSort(temp, n);
  memcpy(temp, Q, n*sizeof(int));
  inv2 = mergeSort(temp, n);
  return inv1%2 == inv2%2;
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

pair<ll, bool> getRank(int n) {
  node_t* root = nullptr;
  ll rank = 1;
  bool odd = true;
  int next = n;
  int small = 0;
  int size = 0;
  rep(i, 0, n-1) {
    int curr = Q[i];
    ll count = curr - 1;
    if (next ==curr) {
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
    if (count == 0) continue;
    //printf("%d %d\n", curr, count);
    if (count%2 == 1 && n-i-1 < 2) {
      odd = !odd;
    }
    rank = (rank + (count * (ll)FACT[n-i-1])%MOD)%MOD;
  }
  return make_pair(rank, odd);
}

int main() {
  FACT[0] = 1;
  rep(i, 1, 100002) {
    FACT[i] = (FACT[i-1]*(ll)i)%MOD;
  }
  ll inver2 = inver(2);
  int tests = si();
  while(tests--) {
    int n = si();
    int k = si();
    assert(n<100001);
    rep(i, 0, n) P[i] = si();
    rep(i, 0, n) Q[i] = si();
    ll ans = -1;
    if (k == n) {
      int start = 0;
      while(P[start] != Q[0]) ++start;
      bool canPermutate = true;
      rep(i, start, n) {
        if (P[i] != Q[i-start]) {
          canPermutate = false;
          break;
        }
      }
      if (canPermutate) {
        rep(i, 0, start) {
          if (P[i] != Q[i+n-start]) {
            canPermutate = false;
            break;
          }
        }
      }
      if (canPermutate) {
        ans = Q[0];
      }
    } else {
      bool canPermutate = k%2 == 0 ? true : check(n);
      if (canPermutate) {
        auto rank = getRank(n);
        ans = rank.first;
        if (k%2 == 1) {
          ans = (ans + (int)rank.second) % MOD;
          ans = (ans * inver2) % MOD;
        }
      }
    }
    cout << ans << endl;
  }
}


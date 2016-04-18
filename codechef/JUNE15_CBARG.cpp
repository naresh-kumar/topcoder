// https://www.codechef.com/JUNE15/status/CBARG,nemausus
// https://www.codechef.com/viewplaintext/7112371
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
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef map<string, int> msi;
typedef map<string, string> mss;
typedef map<int, int> mii;
typedef map<int, string> mis;

#define INF 1000000000
#define PI  3.14159265358979323846  /* pi */

template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

struct Point { int x; int y; };

template<class T>
void printmap(T m) {
  for(const auto& i : m) cout << i.first << " " << i.second << " ";
  cout << endl;
}

template<typename T>
void printlist(T l) {
  for(const auto& i : l) cout << i << " ";
  cout << endl;
}

bool valid(int i, int j, int n) {
  return i>=0 && i<n && j>=0 && j<n;
}

template<typename T>
T reverse(T n) {
  T reverse = 0;
  while (n != 0) {
    reverse = reverse * 10;
    reverse = reverse + n%10;
    n = n/10;
  }
  return reverse;
}

template<typename T>
int firstdigit(T n) {
  int ans = 0;
  while (n != 0) {
    ans = n%10;
    n = n/10;
  }
  return ans;
}

template<typename T>
int digits(T n) {
  int ans = 0;
  while (n != 0) {
    ans++;
    n = n/10;
  }
  return ans;
}

int frequency(string& str, char ch) {
  int count = 0;
  rep(i, 0, str.length())
    if (str[i] == ch) count++;
  return count;
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

ll solve () {
  int n = ss;
  ll sol = 0;
  int mem = 0;
  rep(i, 0, n) {
    int required = ss;
    sol += max(0, required - mem);
    mem = required;
  }
  return sol;
}

int main() {
  //freopen("/Users/knaresh/codejam/codejam/in.txt", "r", stdin);
  //freopen("/Users/knaresh/codejam/codejam/out.txt", "w", stdout);
  int tests = ss;
  while (tests--) {
    printf("%lld\n", solve());
  }
  return 0;
}

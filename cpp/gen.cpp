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

double randreal(double l, double u) {
  std::uniform_real_distribution<double> unif(l,u);
  static std::default_random_engine re(time(0));
  return unif(re);
}

inline int randint(int max) { return rand()%max; }

inline int randint(int min, int max) { return randint(max-min)+min; }

int main() {
  srand (time(NULL));
  int n = ss;
  cout << n << endl;
  rep(i, 0, n) {
    cout << randint(-1000000, 1000000) << " ";
  }
  cout << endl;
  return 0;
}

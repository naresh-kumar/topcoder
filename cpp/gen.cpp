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

#define all(a) a.begin(),a.end()
#define rep(i, a, b) for(int i=(a); i<(b); ++i)
#define irep(i, a, b) for(int i=(a); i>=(b); --i)
#define iter(i,v) for(auto &i : (v))

typedef long long ll;

// random generator
template<class T> inline void println(T t) { cout << t << endl; }
inline int randint(int max) { return rand()%max; }
inline int randint(int min, int max) { return randint(max-min+1)+min; }
double randreal(double l, double u) {
  std::uniform_real_distribution<double> unif(l,u);
  static std::default_random_engine re(time(0));
  return unif(re);
}

int main() {
  srand(time(0));
  int n = 1000000;
  println(1);
  println(n);
  rep(i, 0, n) {
    int x = randint(1000000-3);
    int y = randint(1000000-3);
    printf("%d %d\n", min(x,y), max(x,y));
  }
  return 0;
}

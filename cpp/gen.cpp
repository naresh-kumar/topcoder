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
template<class T> inline void prints(T t) { cout << t << " "; }
inline int randint(int max) { return rand()%max; }
inline int randint(int min, int max) { return randint(max-min+1)+min; }
double randreal(double l, double u) {
  std::uniform_real_distribution<double> unif(l,u);
  static std::default_random_engine re(time(0));
  return unif(re);
}

int main() {
  srand(time(0));
  int t = 10;
  println(t);
  rep(i, 0, t) {
    prints(200000);
    println(50000);
    rep(i, 0, 200000) {
      prints(randint(50000)+1);
    }
    cout << endl;
    rep(i, 0, 50000) {
      printf("%d %d %d\n", i+1, randint(50000)+1, randint(50000)+1);
    }
  }
  return 0;
}

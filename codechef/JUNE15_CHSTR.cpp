// https://www.codechef.com/JUNE15/status/CHSTR,nemausus
// https://www.codechef.com/viewplaintext/7214784
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
#include <unordered_map>
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

#define INF 2147483647
#define PI  3.14159265358979323846  /* pi */

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

template<class T>
T getRand(T l, T u) {
  std::uniform_real_distribution<T> unif(l,u);
  static std::default_random_engine re;
  return unif(re);
}

#define SIZE 1024*128
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

ll factorial(ll x) { return (x < 2) ? 1 : x*factorial(x-1); }

ll getNcr(ll n, ll r) {
  return factorial(n)/(factorial(r) * factorial(n-r));
}

clock_t lastMark = 0;
void markTime(string tag) {
  clock_t mark = clock();
  printf("time %s %lf\n", tag.c_str(), double(mark - lastMark) / CLOCKS_PER_SEC);
  lastMark = mark;
}
class HashEntry {
private:
      int key;
      int value;
public:
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }

      int getKey() {
            return key;
      }

      int getValue() {
            return value;
      }
};

int mod = 1000000007;
int ncr[5005][5005];
int main() {
  //freopen("/Users/knaresh/codejam/codejam/in.txt", "r", stdin);
  //freopen("/Users/knaresh/codejam/codejam/out.txt", "w", stdout);
  //buffer_size = fread(buffer, 1, SIZE, stdin);
  //markTime("start");
  int tests = ss;
  while(tests--) {
    int n = ss;
    for (int i = 0; i < n+3; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i)
          ncr[i][j] = 1;
        else
          ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % mod;
      }
    }
    //markTime("pascal");
    int q = ss;
    char str[n];
    scanf("%s", str);
    int ch = str[0];
    int isSame = 1;
    rep(i, 0, n) { if (str[i] != ch) {isSame = 0;break;}}
    if (isSame) {
      rep(i, 0, q) {
        int k = ss;
        if (k <= n)
          printf("%d\n", ncr[n+1][min(k+1,n-k)]);
        else
          printf("%d\n", 0);
      }
      continue;
    }
    int tableSize = 10007;
    int value[tableSize];
    ll key[tableSize];
    int frequency[n+1];

    memset(frequency, 0, sizeof(frequency));
    memset(key, 0, sizeof(key));
    memset(value, 0, sizeof(value));

    ll hash_arr[n];
    ll hash = 13;
    rep(i, 0, n) {
      hash = 13 * 31 + str[i];
      hash_arr[i] = hash;
      int index = hash % tableSize;
      if (index < 0) index += tableSize;
      while (key[index] != 0 && key[index] != hash) index = (index + 1) % tableSize;
      value[index]++;
      key[index] = hash;
    }
    rep (i, 0, tableSize) {
      frequency[value[i]]++;
    }
    //markTime("count init");
    rep(l, 2, n+1) {
      memset(key, 0, sizeof(key));
      memset(value, 0, sizeof(value));
      rep(j, 0, n-l+1) {
        hash = hash_arr[j] * 31 + str[j+l-1];
        hash_arr[j] = hash;
        int index = hash % tableSize;
        if (index < 0) index += tableSize;
        while (key[index] != 0 && key[index] != hash) index = (index + 1) % tableSize;
        value[index]++;
        key[index] = hash;
      }
      int allUnique = 1;
      rep (i, 0, tableSize) {
        frequency[value[i]]++;
        allUnique = allUnique && value[i] < 2;
      }
      if (allUnique) {
        int sum = 0;
        rep(i, l+1, n+1) sum += n - i + 1;
        frequency[1] += sum;
        break;
      }
    }
    //markTime("count");
    //rep(i, 0, 10) printlist(&frequency[i], 20);
    int answer[n+1];
    memset(answer, -1, sizeof(answer));
    int max = n+1;
    for(int i=n; i>=0; --i) {if (frequency[i] != 0) break; else max = i;}
    max = min(n+1, max+1);
    rep(i, 0, q) {
      int k = ss;
      int ans = 0;
      if (k <= n) {
        if (answer[k] == -1) {
            rep(i, k, max) {
              ans = (ans + (frequency[i]*(ll)ncr[i][min(k,i-k)])%mod)%mod;
            }
          answer[k] = ans;
        } else
          ans = answer[k];
      }
      printf("%d\n",ans);
    }
    //markTime("ans");
  }
  return 0;
}

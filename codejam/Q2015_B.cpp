//author Naresh
// https://code.google.com/codejam/contest/6224486/dashboard#s=p1
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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define IFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define FORD(i, a, b, c) for(int i=(a); i<(b); i+=(c))

#define SI(x) ((int)x.size())
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a, b)
#define SORT(a) sort(a.begin(),a.end())
#define ITER(it,a) for(typeof(a.begin()) it=a.begin();it!=a.end();it++)
#define ALL(a) a.begin(),a.end()
#define INF 1000000000
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({long long x;scanf("%lld", &x);x;})

#define V vector
#define S string
#define FST first
#define SEC second
typedef V<int> VI;
typedef V<S> VS;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<S, int> PSI;
typedef pair<S, S> PSS;
typedef map<S, int> MSI;
typedef map<S, S> MSS;

template<typename T>
void printMap(T c) {
    ITER(it, c)
    {
        cout << it->first << " " << it->second << ", ";
    }
    cout << endl;
}

template<typename T>
void printList(T c) {
    ITER(it, c)
    {
        cout << *it << ", ";
    }
    cout << endl;
}

LL a, b, c, a1, b1, c1;
int MOD = 1000000007;

LL mul(LL x, LL y) {
    if(x > 0 && y > 0)
    {
        x = x % MOD;
        y = y % MOD;
        return (LL)(x * y) % MOD;
    }
    return 0;
}

VI getFactors(int n) {
    VI v;
    while (n % 2 == 0) {
        v.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i+=2) {
        while (n % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }
    if (n>2) v.push_back(n);
    return v;
}

int f(VI vecOrig, int last) {
    int numPeople = vecOrig[last];
    if (last <= numPeople || last < 4) return last;

    int ans = last;
    int i = last;
        for ( int j = 1; j <= i/2; ++j) {
            VI vec = vecOrig;
            numPeople = vec[i];
            if(numPeople == 0) continue;
            vec[j] += numPeople;
            vec[i-j] += numPeople;
            vec[i] = 0;
            int l = last;
            while(l > 0 && vec[l] == 0) {
                l--;
            }
            ans = min(ans, numPeople + f(vec, l));
        }

    REP(k, last) {
        vecOrig[k] = vecOrig[k+1];
    }
    vecOrig[0] = 0;
    vecOrig[last] = 0;
    int ans2 = 1+ f(vecOrig, last-1);
    if (ans2 < ans) {
        return ans2;
    }
    return ans;
}

int main() {
    freopen("/Users/knaresh/codechef/codechef/codechef/in.txt", "r", stdin);
    freopen("/Users/knaresh/codechef/codechef/codechef/out.txt", "w", stdout);
    int c = 1;
    int t = SS;
    while(t--) {
        int n = SS;
        VI vec;
        vec.resize(1005);
        int last = 0;
        REP(i,n) {
            int p = SS;
            vec[p]++;
            if (p > last) last = p;
        }
        int ans = f(vec, last);
        printf("Case #%d: %d\n", c++, ans);
    }
    return 0;
}

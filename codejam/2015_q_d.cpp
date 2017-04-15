//author Naresh
// https://code.google.com/codejam/contest/6224486/dashboard#s=p3
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

int arr[5][5][5];

int main() {
    freopen("/Users/knaresh/codechef/codechef/codechef/in.txt", "r", stdin);
    freopen("/Users/knaresh/codechef/codechef/codechef/out.txt", "w", stdout);
    FOR(i, 1, 5) FOR(j, 1, 5) FOR(k, j, 5) {
        int ans = 0;
        switch (i) {
            case 1:
                ans = 1;
                break;
            case 2:
                ans = (j*k)%i == 0;
            default:
                break;
        }
        if ((j*k) % i != 0 || j*k < i) ans = 0;
        //printf("%d %d %d : %d\n", i, j, k, ans);
        arr[i][j][k] = ans;
    }
    arr[3][2][3] = 1;
    arr[3][3][3] = 1;
    arr[3][3][4] = 1;
    arr[4][3][4] = 1;
    arr[4][4][4] = 1;
    int t = SS;
    int n = 1;
    while(t--) {
        int x = SS;
        int r = SS;
        int c = SS;
        int ans = r < c ? arr[x][r][c] : arr[x][c][r];
        printf("Case #%d: %s\n", n++, ans == 1 ? "GABRIEL" : "RICHARD");
    }
    return 0;
}

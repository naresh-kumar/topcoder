#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(auto i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")
typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 100000;
int near[MAX+1] = {};
vi d[MAX+1];
int a[MAX];
int ans[MAX];

int main() {
    fori(i, 1, MAX+1) {
        ford(j, i, MAX+1, i) d[j].pb(i);
    }
    int n = SS, k = SS;
    rep(i, n) a[i] = SS;
    int nearK = -1;
    rep(i, MAX) near[i+1] = -1;
    rep(i, n) {
        if (i==0) {
            ans[0] = 0;
        } else {
            if (a[i] <= k) {
                ans[i] = ans[i-1];
            } else {
                ans[i] = max(ans[i-1], 1 + max(nearK, near[a[i]]));
            }
        }
        if (a[i] > k) {
            int num = a[i]-k;
            vector<int>::iterator it = upper_bound(d[num].begin(), d[num].end(), k);
            for(vector<int>::iterator iter = it; iter != d[num].end(); iter++) {
                near[*iter] = i;
            }
        } else if (a[i] == k) {
            nearK = i;
        }
    }
    ll res = 0;
//    rep(i, n) cout<<ans[i]<<" ";
   // puts("");
    rep(i, n) {
        res += i-ans[i] + 1;
    }
    printf("%lld\n", res);
}

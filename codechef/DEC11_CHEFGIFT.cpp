// https://www.codechef.com/DEC11/status/CHEFGIFT,nemausus
// https://www.codechef.com/viewplaintext/753661
//author Naresh
#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <bitset>

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
#define V vector
#define S string
#define FST first
#define SEC second
#define SS ({int x;scanf("%d", &x);x;})
typedef V<int> VI;
typedef V<S> VS;
typedef long long LL;
typedef pair<int, int> PII;

int dp[102][102];
int cost [102][102];
int shift [102][102];
int main()
{
	//freopen("in", "r", stdin);
	int t=SS;
	while(t--)
	{
		int d = SS;
		int n = SS;
		int m = SS;

		FOR(i,0,m)
		FOR(j,0,n)
		cost[j][i]=SS;
		
		FOR(i,0,m)
		FOR(j,0,m)
		shift[i][j]=SS;
		
		FOR(k, 0, m)
		FOR(i, 0, m)
		FOR(j, 0, m)
        shift[i][j] = min(shift[i][j], shift[i][k]+shift[k][j]);
		
		FOR(i, 0, m)
		dp[0][i] = 0;
		
		int l = n+1;
		
		FOR(i, 1, l)
		FOR(j, 0, m)
		{
			int sol = INF;
			FOR(k, 0, m){
				int temp = dp[i-1][k] + shift[k][j] + cost[i-1][j];
				if(sol > temp) sol = temp;
			}
			dp[i][j] = sol;
		}
		
		int ans = dp[n][0];
		FOR(i, 0, m){
			if(ans > dp[n][i])
			ans = dp[n][i];
		}
		ans = d - ans;
		if(ans < 0) ans = -1;
		printf("%d\n", ans);
	}
}

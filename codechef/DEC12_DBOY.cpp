// https://www.codechef.com/DEC12/status/DBOY,nemausus
// https://www.codechef.com/viewplaintext/1617928
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
int dp[1001];
int dis[500];
int fuel[500];
int n;

int solve(int x)
{
	if(dp[x] != -1) return dp[x];
	
	int ans = 10000000;
	for(int i = 0; i < n; ++i)
	{
		if(fuel[i] == x) {
			ans = 1;
			break;
		}
		else if(fuel[i] < x)
		{
			int a = 1 + solve(x-fuel[i]);
			if(a < ans) ans = a;
		}
	}
	dp[x] = ans;
	return ans;
}

int main()
{
	int t = SS;
	while(t--)
	{
		n = SS;
		for(int i = 0; i < 1001; ++i)
		{
			dp[i] = -1;
		}
		for(int i = 0; i < n ; ++i)
		{
			dis[i] = SS * 2;
		}
		for(int i = 0; i < n ; ++i)
		{
			fuel[i] = SS;
		}
		
		int total = 0;
		for(int i = 0; i < n; ++i)
		{
			total += solve(dis[i]);
		}
		cout << total << endl;
	}
	return 0;
}
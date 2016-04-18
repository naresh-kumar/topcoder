// https://www.codechef.com/DEC12/status/MGCRNK,nemausus
// https://www.codechef.com/viewplaintext/1617539
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
int arr[100][100];
int sol[100][100];
int INT_MIN = -1000000000;

int main()
{
	int t = SS;
	while(t--)
	{
		int n = SS;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				arr[i][j] = SS;
		
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				int up = INT_MIN;
				int left = INT_MIN;
				if(i > 0) up = sol[i-1][j];
				if(j > 0) left = sol[i][j-1];
				int m = max(up, left);
				if(m == INT_MIN) m = 0;
				sol[i][j] = m + arr[i][j];
			}
		
		int ans = sol[n-1][n-1];
		if(ans < 0)
		{
			printf("Bad Judges\n");
		}
		else
		{
			printf("%0.6f\n", (double)ans/(2*n-3));
		}
	}
	return 0;
}

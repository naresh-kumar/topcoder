// https://www.codechef.com/FEB12/status/MAXCOUNT,nemausus
// https://www.codechef.com/viewplaintext/821898
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
int sol[10001];
using namespace std;

int main()
{
	//freopen("in", "r", stdin);
	int t=SS;
	while(t--)
	{
		int n=SS;
		memset(sol, 0, 4*10001);
		FOR(i, 0, n)
		{
			sol[SS]++;
		}
		int max_count = 0;
		int min_value = 10001;
		FOR(i, 1, 10001)
		{
			if(sol[i] > max_count)
			{
				max_count = sol[i];
				min_value = i;
			}
		}
		printf("%d %d\n", min_value, max_count);
	}
	return 0;
}

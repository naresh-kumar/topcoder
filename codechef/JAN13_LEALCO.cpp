// https://www.codechef.com/JAN13/status/LEALCO,nemausus
// https://www.codechef.com/viewplaintext/1683027
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
void printMap(T c)
{
	ITER(it, c)
	{
		cout << it->first << " " << it->second << " ";
	}
	cout << endl;
}

template<typename T>
void printList(T c)
{
	ITER(it, c)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int n, k, m;
VI inc;
int solve(VI v, int start)
{
	if(m == 1) return -1;
	start = 0;
	FOR(i,start, n-k+1)
	{
		int max = -1;
		int max_count = 0;
		FOR(j, i, i+k)
		{
			if(max < v[j]) {max = v[j]; max_count = 1;}
			else if(max == v[j]) ++max_count;
		}
		if(max_count >= m)
		{
			int min = INF;
			IFOR(j, i+k-1, i)
			{
				if(v[j] == max && inc[j] == 0)
				{
					v[j] = v[j] + 1;
					inc[j] = 1;
					int ans = solve(v, i);
//					string s = "\t";
//					REP(l, i) s += " ";
//					cout << "ans " << ans << s << i + 1 << " : ";
//					printList(v);
//					cout << "ans " << ans << s << i + 1 << " : ";
//					printList(inc);
					v[j] = v[j] - 1;
					inc[j] = 0;
					if(ans != -1 && ans < min) min = ans;
					if(min == 0) return 1;
				}
			}
			if(min == INF) return -1;
			return min+1;
		}
	}
	return 0;
}

int main()
{
	int t = SS;
	while(t--)
	{
		inc.clear();
		VI v;
		n = SS;
		k = SS;
		m = SS;
		REP(i, n)
		{
			v.PB(SS);
			inc.PB(0);
		}
		cout << solve(v, 0) << endl;
	}
	return 0;
}



// https://www.codechef.com/JAN13/status/CHEFHACK,nemausus
// https://www.codechef.com/viewplaintext/1681511
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
		cout << it->first << " " << it->second << ", ";
	}
	cout << endl;
}

template<typename T>
void printList(T c)
{
	ITER(it, c)
	{
		cout << *it << ", ";
	}
	cout << endl;
}
const int max_val = 10000000;
int pass_type[512][512];
int pass[512][512];
int prime_count[max_val];
int n;

int getType(int pass)
{
	// 1 2 3 - odd even prime
	if(prime_count[pass] != -1) return 3;
	if(pass % 2 == 0) return 2;
	return 1;
}

void mark(int i, int j, int type)
{
	if(pass[i][j] != -1 && pass_type[i][j] == type)
	{
		pass[i][j] = -1;
		if(i>0)
		mark(i-1, j, type);
		if(i<n-1)
		mark(i+1, j, type);
		if(j>0)
		mark(i, j-1, type);
		if(j<n-1)
		mark(i, j+1, type);
	}
}

int main()
{
	for(int i = 0; i < max_val; i+=2)
	{
		prime_count[i] = -1;
		prime_count[i+1] = i;
	}
	
	prime_count[1] = -1;
	prime_count[2] = 0;
	int total_count = 1;
	
	for(int i = 3; i < max_val; i+=2)
	{
		if(prime_count[i] != -1)
		{
			prime_count[i] = total_count;
			++total_count;
			
			for(int j = i*2; j < max_val; j += i)
			{
				prime_count[j] = -1;
			}
		}
	}
	
	int t = SS;
	while(t--)
	{
		n = SS;
		int type;
		LL ans = 0;
		REP(i, n)
		{
			REP(j, n)
			{
				pass[i][j] = SS;
				pass_type[i][j] = getType(pass[i][j]);
			}
		}
		
		REP(i, n)
		{
			REP(j, n)
			{
				if(pass[i][j] != -1)
				{
					type = pass_type[i][j];
					
					if(type == 1)
					{
						ans += (pass[i][j]+3)/2; 
					}
					else if(type == 2)
					{
						ans += pass[i][j]/2;
					}
					else
					{
						ans += prime_count[pass[i][j]];
					}
					if(type != 3)
					mark(i, j, type);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
// https://www.codechef.com/JAN13/status/SALARY,nemausus
// https://www.codechef.com/viewplaintext/1679785
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

int main(int argc, char **argv)
{
	int t = SS;
	
	while(t--)
	{
		int min = INF;
		int total = 0;
		int n = SS;
		int salary;
		REP(i, n)
		{
			salary = SS;
			if(min > salary) min = salary;
			total += salary;
		}
		
		cout << total - (min*n) << endl;
	}
	return 0;
}

// https://www.codechef.com/DEC12/status/CNTWAYS,nemausus
// https://www.codechef.com/viewplaintext/1622777
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
#include <cassert>

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

int MOD = 1000000007;
LL arr[800005];
const int ie = 10000000;
LL IE[ie];


LL pow(int a, int b)
{
	LL x=1,y=a; 
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD; 
		b /= 2;
	}
	return x;
}

LL InverseEuler(int n)
{
	if(n < ie)
	{
		if(IE[n] == -1)
			IE[n] = pow(n, MOD-2);
		return IE[n];
	}
		
	return pow(n,MOD-2);
}

LL C(int n, int r)
{	
	r = min(r, n-r);
	return (arr[n] * ((InverseEuler(arr[r]) * InverseEuler(arr[n-r])) % MOD)) % MOD;
}

int main()
{
	//freopen("/home/naresh/codechef/count/Debug/in", "r+", stdin);
	arr[0] = 1;
	arr[1] = 1;
	for (int i=2; i<=800001;i++)
		arr[i]= (arr[i-1]*i) % MOD;
		
	for(int i = 0; i < ie; ++i) IE[i] = -1;
	int t = SS;
	while(t--)
	{
		LL n = SS;
		LL m = SS;
		LL a = SS;
		LL b = SS;
		
		LL ans = C(m+n-a,m);
		LL prev = ans;
		for(int i = 1; i < m -b +1; ++i)
		{
			LL down = (InverseEuler(i) * InverseEuler(m+n-a-i+1)) % MOD ;
			LL up = ((m-i+1) * (a+i-1)) %MOD;
			LL prod = down*up;
			if(prod > MOD) prod %= MOD;
			prod *= prev;
			if(prod > MOD) prod %= MOD;
			prev = prod;
			ans += prod;
			if(ans > MOD) ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
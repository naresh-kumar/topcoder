// https://www.codechef.com/JAN13/status/CVOTE,nemausus
// https://www.codechef.com/viewplaintext/1679655
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
void print(T c)
{
	ITER(it, c)
	{
		cout << it->first << " " << it->second << ", ";
	}
	cout << endl;
}

int main()
{
	int chefCount = SS;
	int emailCount = SS;
	MSS chef_country;
	MSI chef_votes;
	MSI country_votes;
	
	char chef[16];
	char country[16];
	REP(i, chefCount)
	{
		scanf("%s", chef);
		scanf("%s", country);
		chef_country.insert(PSS(chef, country));
		chef_votes.insert(PSI(chef, 0));
		country_votes.insert(PSI(country, 0));
	}
//	print(chef_country);
//	print(chef_votes);
//	print(country_votes);
	REP(i, emailCount)
	{
		scanf("%s", chef);
		MSI::iterator pos = chef_votes.find(chef);
		pos->second = pos->second + 1;
		
		MSS::iterator country_pos = chef_country.find(chef);
		pos = country_votes.find(country_pos->second);
		pos->second = pos->second + 1;
	}
//	print(chef_votes);
//	print(country_votes);
	
	int votes = 0;
	string name;
	ITER(it, country_votes)
	{
		if(it->second > votes)
		{
			votes = it->second;
			name = it->first;
		}
	}
	
	cout << name << endl;
	
	votes = 0;
	ITER(it, chef_votes)
	{
		if(it->second > votes)
		{
			votes = it->second;
			name = it->first;
		}
	}
	
	cout << name << endl;
	return 0;
}

//author Naresh
#include <algorithm>
#include <bitset>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

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
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({long long int x;scanf("%lld", &x);x;})

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

#define INF 1000000000

template<class T>
T gcd(T a, T b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

struct Point {
  int x;
  int y;
};

template<class T>
void printMap(T m) {
    for(const auto& i : m) {
      cout << i.first << " " << i.second << " ";
    }
    cout << endl;
}

template<typename T>
void printList(T l) {
    for(const auto& i : l) {
      cout << i << " ";
    }
    cout << endl;
}

bool valid(int i, int j, int n) {
    return i>=0 && i<n && j>=0 && j<n;
}

int main() {
    freopen("/Users/knaresh/codejam/codejam/in.txt", "r", stdin);
    freopen("/Users/knaresh/codejam/codejam/out.txt", "w", stdout);
    int testCase = SS;
    int testNo = 1;
    while(testCase--) {
        int n = SS;
        int maze[n][n];
        REP(i,n) REP(j,n) maze[i][j] = SS;
        int ans_moves = -1;
        int ans_num = 0;
        FOR(a,0,n)
        FOR(b,0,n) {
            if (maze[a][b] == -2) continue;
            int moves = 0;
            int i = a;
            int j = b;
            while (true) {
                int next = maze[i][j] - 1;
                if (valid(i-1,j,n) && maze[i-1][j] == next) {
                    i = i-1;
                } else if (valid(i,j-1,n) && maze[i][j-1] == next) {
                    j = j-1;
                } else if (valid(i+1,j,n) && maze[i+1][j] == next) {
                    i = i+1;
                } else if (valid(i,j+1,n) && maze[i][j+1] == next) {
                    j = j+1;
                }
                else {
                    break;
                }
            }
            int num = maze[i][j];
            while (true) {
                int next = maze[i][j] + 1;
                int ii = i;
                int jj = j;
                if (valid(i-1,j,n) && maze[i-1][j] == next) {
                    ++moves;
                    i = i-1;
                } else if (valid(i,j-1,n) && maze[i][j-1] == next) {
                    ++moves;
                    j = j-1;
                } else if (valid(i+1,j,n) && maze[i+1][j] == next) {
                    ++moves;
                    i = i+1;
                } else if (valid(i,j+1,n) && maze[i][j+1] == next) {
                    ++moves;
                    j = j+1;
                }
                maze[ii][jj] = -2;
                if( i == ii && j == jj) break;
            }
            if (ans_moves < moves) { ans_moves = moves; ans_num = num;}
            else if (ans_moves == moves) ans_num = min(ans_num, num);
        }
        printf("Case #%d: %d %d\n", testNo++, ans_num, ans_moves+1);
    }
    return 0;
}
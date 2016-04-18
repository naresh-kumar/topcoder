// https://www.codechef.com/DEC11/status/MOVES,nemausus
// https://www.codechef.com/viewplaintext/753526
#include<iostream>
#include<cstdio>
int sol[5000][5000];
using namespace std;
    int mod = 1000000007;
    int combination(int n, int k)
    {
        if(k == 0 ) return 1;
        if(n <= k) return 1;
        if(k > n/2) k = n-k;
        return sol[n][k];
    }

    void compute()
    {

        for(int i = 1; i < 5000; ++i) {
            sol[i][0] = 1;
            for(int j = 1; j < i && j < 2500; ++j){
                	sol[i][j] = (sol[i-1][j-1] + sol[i-1][j])%mod;    
            }
            sol[i][i]= 1;
		}
    }

int main()
{          
        compute();
        while (true)
        {
            int n;
            int k;
            scanf("%d%d", &n, &k);
            if(n == 0 && k == 0) break;

            --n;
            int totalSlots = k + 1;
            int downSlots = totalSlots / 2;
            int rightSlots = totalSlots - downSlots;
            int answer = combination(n - 1, rightSlots - 1);
            answer = answer*(long long)combination(n - 1, downSlots - 1) % mod;
            answer %= mod;
            answer *= 2;
            answer %= mod;
            printf("%d\n", answer);
        }
       
    }
  

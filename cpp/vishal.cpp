#include <iostream>

using namespace std;

int countTuples(int N, int S, int** dp) {
  if (N == 1 || S == 0) {
    return 1;
  }
  int count = dp[N][S];
  if (count != -1) return count;
  count = 0;
  for (int i = 0; i <= S; i++) {
    count = count + countTuples(N - 1, S - i, dp);
  }
  dp[N][S] = count;
  return count;
}

int main() {
  while(true) {
    int N, S;
    cin >> N >> S;
    int** dp;
    dp = new int *[N+1];
    for (int i = 0; i < N+1; ++i) {
      dp[i] = new int[S+1];
      for (int j = 0; j < S+1; ++j) {
        dp[i][j] = -1;
      }
    }
    cout << countTuples(N, S, dp) << endl;
  }
  return 0;
}


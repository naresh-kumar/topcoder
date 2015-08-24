package dp;

// Is it possible to create string S by interleaving strings A and B?

public class InterleavingStrings {
  public boolean[][] canBeCreated(String S, String A, String B) {
    boolean[][] dp = new boolean[A.length() + 1][B.length() + 1];

    dp[0][0] = true;

    for (int i = 1; i < B.length() + 1; ++i) {
      dp[0][i] = dp[0][i - 1] && B.charAt(i - 1) == S.charAt(i - 1);
    }

    for (int i = 1; i < A.length() + 1; ++i) {
      dp[i][0] = dp[i - 1][0] && A.charAt(i - 1) == S.charAt(i - 1);
    }


    for (int i = 1; i < A.length() + 1; ++i) {
      for (int j = 1; j < B.length() + 1; ++j) {
        char a = A.charAt(i - 1);
        char b = B.charAt(j - 1);
        char s = S.charAt(i + j - 1);
        dp[i][j] = (dp[i - 1][j] && a == s) ||
          (dp[i][j - 1] && b == s);
      }
    }

    return dp;
  }
}

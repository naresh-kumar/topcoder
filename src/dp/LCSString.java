package dp;

import java.util.Collections;
import java.util.List;

// longest common sub-sequence
public class LCSString {
  public static int getLCSLength(List<String> list1, List<String> list2) {
    int[][] dp = new int[list1.size() + 1][list2.size() + 1];

    for (int i = 0; i < list1.size(); ++i) {
      dp[i][0] = 0;
    }

    for (int i = 0; i < list2.size(); ++i) {
      dp[0][i] = 0;
    }

    for (int i = 1; i < list1.size() + 1; ++i) {
      for (int j = 1; j < list2.size() + 1; ++j) {
        if (list1.get(i - 1).equals(list2.get(j - 1))) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[list1.size()][list2.size()];
  }

  public static int getLCSLengthSorting(List<String> list1, List<String> list2) {
    Collections.sort(list1);
    Collections.sort(list2);
    int i = 0, j = 0, lcsLength = 0;

    while (i < list1.size() && j < list2.size()) {
      int comp = list1.get(i).compareTo(list2.get(j));
      if (comp < 0) {
        ++i;
      } else if (comp == 0) {
        ++i;
        ++j;
        lcsLength++;
      } else {
        ++j;
      }
    }
    return lcsLength;
  }
}


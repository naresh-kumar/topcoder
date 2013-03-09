package dp;

public class SubsetSum
{
    public static boolean isSumZero(int[] array)
    {
        int negSum = 0;
        int posSum = 0;

        for (int i : array)
        {
            if (i < 0) negSum += i;
            else posSum += i;
        }

        int rows = array.length + 1;
        int columns = posSum - negSum + 1;

        boolean[][] dp = new boolean[rows][columns];

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (i == 0)
                {
                    dp[i][j] = false;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] || array[i - 1] == (j + negSum);
                    int prevSum = j - array[i - 1];
                    if (prevSum >= 0 && prevSum < columns)
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][prevSum];
                    }
                }
            }

        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                System.out.print((dp[i][j] ? 1 : 0));
            }
            System.out.println();
        }

        int i = rows - 1;
        int j = -negSum;

        while (true)
        {
            if (dp[i][j] && !dp[i - 1][j])
            {
                System.out.println(array[i - 1]);
                j = j - array[i - 1];
            }
            i = i - 1;
            if (i == -1) break;
        }
        return dp[rows - 1][-negSum];
    }
}

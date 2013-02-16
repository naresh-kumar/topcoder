import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class BalanceInRoom
{
    public void solve() throws IOException
    {
        BufferedReader reader = new Solution.Reader("in.txt");
        Solution.Writer writer = new Solution.Writer(System.out);

        int n = Integer.parseInt(reader.readLine());
        boolean[] root = new boolean[n];
        Arrays.fill(root, true);
        List<Balance> balances = new ArrayList<Balance>(n);

        for (int i = 0; i < n; ++i)
        {
            Balance balance = new Balance();

            StringTokenizer stringTokenizer = new StringTokenizer(reader.readLine());
            balance.lw = Integer.parseInt(stringTokenizer.nextToken());
            while (stringTokenizer.hasMoreTokens())
            {
                String s = stringTokenizer.nextToken();
                int id = Integer.parseInt(s);
                balance.leftB.add(id);
                root[id] = false;
            }

            stringTokenizer = new StringTokenizer(reader.readLine());
            balance.rw = Integer.parseInt(stringTokenizer.nextToken());
            while (stringTokenizer.hasMoreTokens())
            {
                int id = Integer.parseInt(stringTokenizer.nextToken());
                balance.rightB.add(id);
                root[id] = false;
            }

            balances.add(balance);
        }

        int start = 0;


        for (int i = 0; i < n; ++i)
        {
            if (root[i])
            {
                dfs(balances.get(start), balances);
            }
        }

        for (Balance balance : balances)
        {
            writer.append(balance.l_added + " " + balance.r_added + "\n");
        }

        reader.close();
        writer.finish();

    }

    private static void dfs(Balance balance, List<Balance> balances)
    {
        int leftTotal = balance.lw;

        for (Integer i : balance.leftB)
        {
            Balance b = balances.get(i);
            dfs(b, balances);

            leftTotal += b.total;
        }

        int rightTotal = balance.rw;
        for (Integer i : balance.rightB)
        {
            Balance b = balances.get(i);
            dfs(b, balances);

            rightTotal += b.total;
        }

        if (leftTotal > rightTotal)
        {
            balance.r_added = leftTotal - rightTotal;
            rightTotal = leftTotal;
        }
        else
        {
            balance.l_added = rightTotal - leftTotal;
            leftTotal = rightTotal;
        }

        balance.total = leftTotal + rightTotal + 10;
    }

    private static class Balance
    {
        int lw;
        int rw;
        int total;
        List<Integer> leftB = new ArrayList<Integer>();
        List<Integer> rightB = new ArrayList<Integer>();
        int l_added;
        int r_added;
    }
}

import java.io.IOException;
import java.util.Arrays;

public class solutions
{
    static int MOD = 1000000007;
    static int ie = 1000000;
    static long[] IE = new long[ie];
    static long[] arr = new long[1001];

    private static void hackerCup3(Main.Reader reader, Main.Writer writer) throws IOException
    {
        int t = reader.nextInt();
        for (int testCase = 1; testCase <= t; ++testCase)
        {
            int n = reader.nextInt();
            int k = reader.nextInt();
            int a = reader.nextInt();
            int b = reader.nextInt();
            int c = reader.nextInt();
            int r = reader.nextInt();

            int index[] = new int[k];
            Arrays.fill(index, -1);


            long prev = a;

            if (prev < k) index[(int) prev] = 0;

            for (int i = 1; i < k; ++i)
            {
                prev = (b * prev) % r;
                if (prev < 0) prev += r;
                prev = (prev + c) % r;
                if (prev < 0) prev += r;
                if (prev < k) index[(int) prev] = i;
            }

            //            writer.print(index);

            int seq[] = new int[k + 1];
            Arrays.fill(seq, -1);

            int firstEmptyIndex = 0;

            int missing = -1;
            for (int i = 0; i < k; ++i)
            {
                if (index[i] == -1)
                {
                    seq[firstEmptyIndex] = i;
                    while (firstEmptyIndex < k && seq[firstEmptyIndex] != -1) ++firstEmptyIndex;
                }
                else
                {
                    int start = index[i] + 1;
                    while (start < k && seq[start] > 0) ++start;
                    if (start < k) seq[start] = i;
                    else missing = i;
                    while (firstEmptyIndex < k && seq[firstEmptyIndex] > 0) ++firstEmptyIndex;
                }
            }

            for (int i = 0; i < k; ++i)
            {
                if (seq[i] == -1)
                {
                    seq[i] = k;
                    break;
                }
            }

            if (missing == -1)
                seq[k] = k;
            else seq[k] = missing;

            //            writer.print(seq);

            int i = (n - k - 1) % (k + 1);
            if (i < 0) i += k + 1;
            writer.append("Case #" + testCase + ": " + seq[i] + "\n");

        }
    }

    private static void feb13buy1get1(Main.Reader reader, Main.Writer writer) throws IOException
    {
        int t = reader.nextInt();
        while (t-- > 0)
        {
            String s = reader.nextString();
            boolean[] isFree = new boolean[128];
            int cost = 0;
            for (int i = 0; i < s.length(); ++i)
            {
                char c = s.charAt(i);
                if (isFree[c])
                {
                    isFree[c] = false;
                }
                else
                {
                    isFree[c] = true;
                    ++cost;
                }
            }
            writer.append(cost + "\n");
        }
    }

    private static void feb13ClimbingStairs(Main.Reader reader, Main.Writer writer) throws IOException
    {
        int MOD = 1000000007;
        int t = reader.nextInt();
        int[] sol = new int[1000001];
        int max = 2;
        sol[1] = 1;
        sol[2] = 2;
        while (t-- > 0)
        {
            int n = reader.nextInt();
            int g = reader.nextInt();

            if (n > max)
            {
                for (int i = max + 1; i <= n; ++i)
                {
                    long temp = sol[i - 1] + sol[i - 2];
                    temp %= MOD;
                    sol[i] = (int) temp;
                }
                max = n;
            }
            int count = countOne(sol[n]);
            writer.append(count == g ? "CORRECT\n" : "INCORRECT\n");
        }
    }

    private static int countOne(int i)
    {
        int count = 0;
        while (i != 0)
        {
            if ((i & 1) == 1)
            {
                ++count;
            }
            i = i >> 1;
        }
        return count;
    }

    private static void feb13CardGame(Main.Reader reader, Main.Writer writer) throws IOException
    {
        arr[0] = 1;
        arr[1] = 1;
        for (int i = 2; i < 1001; i++)
            arr[i] = (arr[i - 1] * i) % MOD;

        Arrays.fill(IE, -1);

        int t = reader.nextInt();
        while (t-- > 0)
        {
            int n = reader.nextInt();
            for (int i = 0; i < n; ++i) reader.nextInt();

            long sol = 0;
            for (int i = n / 2 + 1; i <= n; ++i)
            {
                sol = (sol + nCr(n, i)) % MOD;
            }
            writer.append(sol + "\n");
        }
    }

    static long pow(int a, int b)
    {
        long x = 1, y = a;
        while (b > 0)
        {
            if (b % 2 == 1)
            {
                x = (x * y);
                if (x > MOD) x %= MOD;
            }
            y = (y * y);
            if (y > MOD) y %= MOD;
            b /= 2;
        }
        return x;
    }

    static long InverseEuler(int n)
    {
        if (n < ie)
        {
            if (IE[n] == -1)
                IE[n] = pow(n, MOD - 2);
            return IE[n];
        }

        return pow(n, MOD - 2);
    }

    static long nCr(int n, int r)
    {
        r = Math.min(r, n - r);
        return (arr[n] * ((InverseEuler((int) arr[r]) * InverseEuler((int) arr[n - r])) % MOD)) % MOD;
    }


}

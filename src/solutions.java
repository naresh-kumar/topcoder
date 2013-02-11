import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class solutions
{
    static int MOD = 1000000007;
    static int ie = 1000000;
    static long[] IE = new long[ie];
    static long[] arr = new long[1001];

    private static void hackerCup3(Solution.Reader reader, Solution.Writer writer) throws IOException
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

    private static void feb13buy1get1(Solution.Reader reader, Solution.Writer writer) throws IOException
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

    private static void feb13ClimbingStairs(Solution.Reader reader, Solution.Writer writer) throws IOException
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

    private static void feb13CardGame(Solution.Reader reader, Solution.Writer writer) throws IOException
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

    private static boolean comp(String a, String b, int aStart, int bStart, int len)
    {
        for (int i = 0; i < len; ++i)
        {
            char c1 = a.charAt(aStart + i);
            char c2 = b.charAt(bStart + i);
            if (!(c1 == '?' || c2 == '?' || c1 == c2))
            {
                return false;
            }
        }
        return true;
    }

    private static class Pixel implements Comparable<Pixel>
    {
        int x;
        int y;

        public Pixel(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pixel o)
        {
            return (x - o.x) != 0 ? (x - o.x) : y - o.y;
        }

        @Override
        public String toString()
        {
            return "[" + x + "," + y + "]";
        }

        @Override
        public boolean equals(Object o)
        {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pixel pixel = (Pixel) o;

            if (x != pixel.x) return false;
            if (y != pixel.y) return false;

            return true;
        }

        @Override
        public int hashCode()
        {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

    private static void hackerCupDeadPixels(Solution.Reader reader, Solution.Writer writer) throws IOException
    {
        int t = reader.nextInt();
        int testCases = t;
        while (t-- > 0)
        {
            final int w = reader.nextInt();
            final int h = reader.nextInt();
            final int p = reader.nextInt();
            final int q = reader.nextInt();
            final int n = reader.nextInt();
            final int x = reader.nextInt();
            final int y = reader.nextInt();
            final int a = reader.nextInt();
            final int b = reader.nextInt();
            final int c = reader.nextInt();
            final int d = reader.nextInt();

            List<Pixel> deadPixels = new ArrayList<Pixel>(n);

            int deadX = x;
            int deadY = y;
            //            writer.logTime();
            deadPixels.add(new Pixel(deadY, deadX));
            for (int i = 1; i < n; ++i)
            {
                int tempDeadX = deadX;
                deadX = (deadX * a + deadY * b + 1) % w;
                deadY = (tempDeadX * c + deadY * d + 1) % h;
                deadPixels.add(new Pixel(deadY, deadX));
            }
            //            writer.logTime();

            Collections.sort(deadPixels);

            int[][] dpUp = new int[2][w];
            int[][] dpLeft = new int[2][w];
            int[][] dpOrder = new int[2][w];

            int ans = 0;

            int min = Math.min(p, q);
            int upDiff = q - min;
            int leftDiff = p - min;

            int curr = 0;
            int prev = inverse(curr);
            int currDeadIndex = 0;
            Pixel currDeadPixel = deadPixels.get(0);

            for (int i = 0; i < h; ++i)
            {
                for (int j = 0; j < w; ++j)
                {
                    int up = 0;
                    int left = 0;
                    int order = 0;
                    if (currDeadPixel == null || !pixelEquals(currDeadPixel, i, j))
                    {
                        up = i > 0 ? dpUp[prev][j] + 1 : 1;
                        left = j > 0 ? dpLeft[curr][j - 1] + 1 : 1;
                        int max_order = 1;
                        if (i > 0 && j > 0)
                        {
                            max_order = Math.max(dpOrder[prev][j - 1] + 1, 1);
                        }
                        int potential_order = Math.min(up - upDiff, left - leftDiff);
                        order = Math.min(max_order, potential_order);
                    }
                    else if (currDeadPixel != null)
                    {
                        while (true)
                        {
                            ++currDeadIndex;
                            if (currDeadIndex < deadPixels.size())
                            {
                                currDeadPixel = deadPixels.get(currDeadIndex);
                                if (!pixelEquals(currDeadPixel, i, j))
                                {
                                    break;
                                }
                            }
                            else
                            {
                                currDeadPixel = null;
                                break;
                            }
                        }
                    }
                    if (order >= min) ++ans;
                    dpUp[curr][j] = up;
                    dpLeft[curr][j] = left;
                    dpOrder[curr][j] = order;
                }
                prev = curr;
                curr = inverse(curr);
            }

            writer.append("Case #" + (testCases - t) + ": " + ans + "\n");
        }

    }

    private static boolean pixelEquals(Pixel currDeadPixel, int i, int j)
    {
        return currDeadPixel.x == i && currDeadPixel.y == j;
    }

    private static int inverse(int a)
    {
        return a ^ 1;
    }

    private static int findMin(int[] array)
    {
        int low = 0;
        int high = array.length - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (mid > 0)
            {
                if (array[mid - 1] > array[mid])
                {
                    low = mid;
                    break;
                }
            }
            else
            {
                if (array[array.length - 1] > array[mid])
                {
                    low = mid;
                    break;
                }
            }
            if (array[mid] < array[high])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return array[low];
    }

    public static String getBitRepresentation(int x)
    {
        char[] str = new char[32];
        for (int i = 31; i >= 0; --i)
        {
            str[i] = (char) ((x & 1) + '0');
            x = x >> 1;
        }
        return new String(str);
    }

    private static void countWays(Solution.Reader reader, Solution.Writer writer)
    {
        int n = 135;
        System.out.println(solve(n, 25));
    }

    private static int solve(int change, int lastCoin)
    {
        if (change == 0) return 1;
        int ans = use(change, lastCoin, 25);
        ans += use(change, lastCoin, 10);
        ans += use(change, lastCoin, 5);
        ans += use(change, lastCoin, 1);
        return ans;
    }

    private static int use(int change, int lastCoin, int denom)
    {
        if (lastCoin >= denom && change >= denom)
        {
            return solve(change - denom, denom);
        }
        return 0;
    }
}

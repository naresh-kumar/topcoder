import java.util.List;
import java.util.Random;

public class Utils
{
    private static final String PP = "pp";
    private static final String TILDE_PP = "~pp";
    private static final String TILDE_MC = "~mc";
    private static final char TILDE = '~';
    private static final char SLASH = '/';
    private static final char AT = '@';
    private static final char HYPHEN = '-';
    public static final char SEMI_COLON = ';';
    private static final char COMMA = ',';

    private static Random random = new Random();

    private Utils()
    {
        // do nothing
    }

    public static double root(int n)
    {
        long x = (long) n * 10000;
        long low = 1;
        long high = x;
        while (low < high)
        {
            long mid = (low + high) / 2;

            long value = mid * mid;
            if (value == x)
            {
                low = mid;
                break;
            }
            else if (value < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return (double) low / 100;
    }

    public static int getRandomInt(int limit)
    {
        return random.nextInt(limit);
    }

    public static String getRandomString(int len)
    {
        String dict = "qwertyuiopasdfghjklzxcvbnm";

        char[] result = new char[len];

        for (int i = 0; i < len; ++i)
        {
            result[i] = dict.charAt(getRandomInt(26));
        }

        return new String(result);
    }

    public static long getMemory()
    {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        return runtime.totalMemory() - runtime.freeMemory();
    }

    public static long getTime()
    {
        return System.currentTimeMillis();
    }

    public static int gcd(int a, int b)
    {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0)
        {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public static long gcd(long a, long b)
    {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0)
        {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public static boolean match(String pattern, String filename)
    {
        int pLen = pattern.length();
        int fLen = filename.length();

        int i = 0;
        int j = 0;
        while (i < pLen)
        {
            char c = pattern.charAt(i);
            if (i + 1 < pLen && pattern.charAt(i + 1) == '*')
            {
                while (j < fLen && filename.charAt(j) == c) ++j;

                i += 2;
            }
            else if (j < fLen && c == '?')
            {
                ++i;
                ++j;
            }
            else if (j < fLen && c == filename.charAt(j))
            {
                ++i;
                ++j;
            }
            else
            {
                break;
            }
        }

        return i == pLen && j == fLen;
    }

    public static String mult(String a, String b)
    {
        int a_len = a.length();
        int b_len = b.length();
        int res_len = a_len + b_len;

        char[] res = new char[res_len];

        for (int i = 0; i < a_len; ++i)
        {
            for (int j = 0; j < res_len; ++j)
            {
                res[j] += '0';
            }
            System.out.println(res);
            for (int j = 0; j < res_len; ++j)
            {
                res[j] -= '0';
            }
            char[] temp = new char[res_len];
            int multiplier = a.charAt(a_len - i - 1) - '0';

            int carry = 0;
            for (int j = 0; j < b.length(); ++j)
            {
                int m = (b.charAt(b_len - j - 1) - '0') * multiplier + carry;
                if (m > 9)
                {
                    carry = m / 10;
                    m %= 10;
                }
                else
                {
                    carry = 0;
                }

                temp[res_len - j - 1 - i] = (char) m;
            }
            temp[a_len - 1 - i] = (char) carry;

            carry = 0;
            for (int j = i; j < res_len; ++j)
            {
                int m = res[res_len - j - 1] + temp[res_len - j - 1] + carry;
                if (m > 9)
                {
                    carry = m / 10;
                    m %= 10;
                }
                else
                {
                    carry = 0;
                }
                res[res_len - j - 1] = (char) (m);
            }

        }
        for (int j = 0; j < res_len; ++j)
        {
            res[j] += '0';
        }

        return new String(res);
    }

    static int binarySearchOnRotatedList(List<Integer> list, int key)
    {
        int low = 0;
        int high = list.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int midValue = list.get(mid);
            int lowValue = list.get(low);
            int highValue = list.get(high);

            if (midValue == key)
            {
                return mid;
            }
            else
            {
                if (lowValue < midValue)
                {
                    if (key < midValue && key >= lowValue)
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (key > midValue && key <= highValue)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

            }
        }
        return -1;
    }
}


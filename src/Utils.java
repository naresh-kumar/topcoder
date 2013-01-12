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
}


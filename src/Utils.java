import java.util.Collection;
import java.util.Random;

public class Utils
{
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
}

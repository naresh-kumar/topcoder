package utils;

import java.util.Arrays;

public class MathUtils
{

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

    public static char[] multiply(char[] a, char[] b)
    {

        int len = a.length + b.length;
        char[] res = new char[len];
        char[] temp = new char[len];
        Arrays.fill(res, '0');

        for (int i = 0; i < a.length; ++i)
        {
            int multiplier = a[a.length - i - 1] - '0';
            Arrays.fill(temp, '0');

            System.arraycopy(b, 0, temp, a.length - i, b.length);

            int carry = 0;
            for (int j = 0; j < temp.length; ++j)
            {
                int m = (temp[len - j - 1] - '0') * multiplier + carry;
                if (m > 9)
                {
                    carry = m / 10;
                    m %= 10;
                }
                else
                {
                    carry = 0;
                }

                temp[len - j - 1] = (char) (m + '0');
            }

            add(res, temp);
        }

        return res;
    }

    public static void add(char[] res, char[] temp)
    {
        int len = res.length;
        int carry = 0;
        for (int j = 0; j < len; ++j)
        {
            int m = res[len - j - 1] + temp[len - j - 1] + carry - '0' - '0';
            if (m > 9)
            {
                carry = m / 10;
                m %= 10;
            }
            else
            {
                carry = 0;
            }
            res[len - j - 1] = (char) (m + '0');
        }
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
}

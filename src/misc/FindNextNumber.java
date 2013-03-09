package misc;

import java.util.Arrays;

public class FindNextNumber
{
    public String nextNumber(String str)
    {
        char[] number = str.toCharArray();

        int[] digits = new int[10];
        int max = -1;

        for (int j = number.length - 1; j >= 0; --j)
        {
            int curr = number[j] - '0';
            max = Math.max(max, curr);
            digits[curr] = 1;
            if (curr < max)
            {
                for (int k = curr + 1; k < 10; ++k)
                {
                    if (digits[k] == 1)
                    {
                        number[j] = (char) (k + '0');
                        for (int l = j + 1; l < number.length; ++l)
                        {
                            if (number[l] == k + '0')
                            {
                                number[l] = (char) (curr + '0');
                                break;
                            }
                        }
                        break;
                    }
                }
                Arrays.sort(number, j + 1, number.length);
                break;
            }
        }
        return new String(number);
    }
}

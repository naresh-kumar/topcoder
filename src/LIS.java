public class LIS
{
    public int[] getLIS(int[] array)
    {
        int len = array.length;
        int[] lis = new int[len];
        int[] prev = new int[len];

        int ans = 0;
        int lastIndex = -1;
        for (int i = 0; i < len; ++i)
        {
            int max = 0;
            int index = -1;
            for (int j = 0; j < i; ++j)
            {
                if (array[j] < array[i])
                {
                    if (max < lis[j])
                    {
                        max = lis[j];
                        index = j;
                    }
                }
            }
            lis[i] = max + 1;
            prev[i] = index;
            if (ans < lis[i])
            {
                ans = lis[i];
                lastIndex = i;
            }
        }
        int[] seq = new int[ans];

        for (int i = ans - 1; i >= 0; --i)
        {
            seq[i] = array[lastIndex];
            lastIndex = prev[lastIndex];
        }
        return seq;
    }
}

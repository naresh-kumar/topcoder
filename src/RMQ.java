public class RMQ
{
    int[][] m;

    public RMQ(int[] array)
    {
        int size = array.length;

        int log = (int) Math.ceil(Math.log(size+1) / Math.log(2));
        m = new int[log][size];

        for (int i = 0; i < size; ++i)
        {
            m[0][i] = array[i];

        }

        int[] pow2 = new int[log + 1];
        pow2[0] = 1;
        for (int i = 1; i < log + 1; ++i)
        {
            pow2[i] = pow2[i - 1] * 2;
        }

        for (int i = 1; i < log; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                int next = j + pow2[i - 1];
                if (next < size)
                {
                    m[i][j] = Math.min(m[i - 1][j], m[i - 1][next]);
                }
                else
                {
                    m[i][j] = m[i - 1][j];
                }
            }
        }
    }

    public int getMin(int i, int j)
    {
        int log_min = (int) Math.floor(Math.log(j - i + 1) / Math.log(2));
        int i1 = j - (1 << log_min) + 1;
        return Math.min(m[log_min][i], m[log_min][i1]);
    }
}

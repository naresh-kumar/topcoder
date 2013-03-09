package misc;

public class RMQSegmentTree
{
    int[] m;
    int size;

    public RMQSegmentTree(int[] array)
    {
        size = array.length;
        int h = (int) Math.ceil(Math.log(size) / Math.log(2));
        m = new int[(1 << (h + 1)) - 1];
        init(0, size - 1, 0, m, array);
    }

    private void init(int start, int end, int node, int[] m, int[] array)
    {
        if (start == end)
        {
            m[node] = array[start];
        }
        else
        {
            int mid = (start + end) / 2;
            int left = 2 * node + 1;
            int right = 2 * node + 2;

            init(start, mid, left, m, array);
            init(mid + 1, end, right, m, array);

            m[node] = Math.min(m[left], m[right]);
        }
    }

    public int getMin(int i, int j)
    {
        return find(0, size - 1, 0, i, j);
    }

    private int find(int start, int end, int node, int i, int j)
    {
        if (start == end) return m[node];

        int mid = (start + end) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;

        if (i > mid)
        {
            return find(mid + 1, end, right, i, j);
        }
        else if (j < mid + 1)
        {
            return find(start, mid, left, i, j);
        }
        else
        {
            return Math.min(find(start, mid, left, i, mid), find(mid + 1, end, right, mid + 1, j));
        }
    }
}

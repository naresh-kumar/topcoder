package misc;

import java.util.*;

// SRM 310 - div 2 - level 3
public class FloatingMedian
{
    public long sumOfMedians(int seed, int mul, int add, int N, int K)
    {
        int MOD = 65536;
        int maxCap = K - K / 2;
        int minCap = K / 2;

        int maxSize = 0;
        int minSize = 0;
        Map<Integer, Integer> maxHeap = new TreeMap<Integer, Integer>(new Comparator<Integer>()
        {
            public int compare(Integer integer, Integer integer2)
            {
                return -integer.compareTo(integer2);
            }
        });

        Map<Integer, Integer> minHeap = new TreeMap<Integer, Integer>();

        int[] array = new int[N];
        array[0] = seed;

        for (int i = 1; i < N; ++i)
        {
            long tt = array[i - 1];
            tt = tt * mul;
            tt = tt % MOD;
            tt += add;
            tt = tt % MOD;
            array[i] = (int) tt;
        }

        long sum = 0;
        System.out.println(Arrays.toString(array));
        for (int i = 0; i < N; ++i)
        {
            System.out.println(maxHeap + " " + minHeap);
            if (i >= K)
            {
                int toBeRemoved = array[i - K];

                if (maxHeap.size() > 0 && peek(maxHeap) >= toBeRemoved)
                {
                    maxHeap.remove(toBeRemoved);
                }
                else
                {
                    minHeap.remove(toBeRemoved);
                }
            }
            System.out.println(maxHeap + " " + minHeap);

            if (maxHeap.size() > 0 && peek(maxHeap) >= array[i])
            {
                insert(maxHeap, array[i]);
            }
            else if (minHeap.size() > 0 && peek(minHeap) <= array[i])
            {
                insert(minHeap, array[i]);
            }
            else
            {
                insert(maxHeap, array[i]);
            }
            System.out.println(maxHeap + " " + minHeap);

            if (maxHeap.size() > maxCap)
            {
                insert(minHeap, remove(maxHeap));
            }
            else if (minHeap.size() > minCap)
            {
                insert(maxHeap, remove(minHeap));
            }

            System.out.println(maxHeap + " " + minHeap);
            System.out.println("-------------------------");
            if (i > K - 2)
            {
                sum += peek(maxHeap);
            }
        }

        return sum;
    }

    private int peek(Map<Integer, Integer> map)
    {
        Iterator<Integer> iterator = map.keySet().iterator();
        return iterator.next();
    }

    private void insert(Map<Integer, Integer> map, int x)
    {
        Integer integer = map.get(x);
        if (integer == null)
        {
            integer = 0;
        }
        integer += 1;
        map.put(x, integer);
    }

    private int remove(Map<Integer, Integer> map)
    {
        int x = peek(map);

        Integer integer = map.get(x);
        if (integer == 1)
        {
            map.remove(x);
        }
        else
        {
            map.put(x, integer - 1);
        }
        return x;
    }
}

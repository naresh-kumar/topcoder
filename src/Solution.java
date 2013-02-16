
import java.io.*;
import java.util.Arrays;
import java.util.Collection;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution
{
    static boolean debug = false;

    public static void main(String[] args) throws IOException
    {
        Reader reader = new Reader(System.in);
        Writer writer = new Writer(System.out);

        MinHeap<Integer> heap = new MinHeap<Integer>(new Integer[100]);
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>(100);

        int[] array = new RandomGenerator().getNumbers(100, 0, 100);
        System.out.println(Arrays.toString(array));
        for (int i = 0; i < 100; ++i)
        {
            heap.insert(array[i]);
            queue.add(array[i]);
            if (i > 5)
            {
                heap.remove();
                queue.poll();
            }
            System.out.println(heap.top() + " " + queue.peek());
        }

        reader.close();
        writer.finish();

    }


    public static class Reader extends BufferedReader
    {
        private StringTokenizer tokenizer;

        public Reader(String fileName) throws FileNotFoundException
        {
            super(new FileReader(fileName));
        }

        public Reader(InputStream in)
        {
            super(new InputStreamReader(in));
        }

        int[] readIntArray(int size) throws IOException
        {
            int[] array = new int[size];
            for (int i = 0; i < size; ++i)
            {
                array[i] = nextInt();
            }
            return array;
        }

        int nextInt() throws IOException
        {
            return Integer.parseInt(nextString());
        }

        long nextLong() throws IOException
        {
            return Long.parseLong(nextString());
        }

        double nextDouble() throws IOException
        {
            return Double.parseDouble(nextString());
        }

        String nextString() throws IOException
        {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
            {
                tokenizer = new StringTokenizer(readLine());
            }
            return tokenizer.nextToken();
        }

        public String nextLine() throws IOException
        {
            return readLine();
        }
    }


    public static class Writer extends PrintWriter
    {
        private long start;


        public Writer(OutputStream outputStream)
        {
            super(new BufferedOutputStream(outputStream));
            start = System.nanoTime();
        }

        public void finish()
        {
            logTime();
            flush();
            close();
        }

        public void logTime()
        {
            if (debug)
            {
                println("time: " + (System.nanoTime() - start) / 1000000);
            }
        }

        public void print(int[] array)
        {
            for (int i = 0; i < array.length; i++)
            {
                if (i != 0)
                    print(' ');
                print(array[i]);
            }

            append("\n");
        }

        public void print(int[][] m)
        {
            for (int i = 0; i < m.length; ++i)
            {
                print(m[i]);
            }
        }

        public <T> void print(Collection<T> collection)
        {
            boolean first = true;
            for (T e : collection)
            {
                if (!first)
                {
                    print(' ');
                }
                print(e);
                first = false;
            }
        }
    }
}


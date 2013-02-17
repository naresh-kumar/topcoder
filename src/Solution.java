
import java.io.*;
import java.util.*;

public class Solution
{
    static boolean debug = false;

    public static void main(String[] args) throws IOException
    {
        Reader reader = new Reader(System.in);
        Writer writer = new Writer(System.out);

        int n = reader.nextInt();

        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < n; ++i)
        {
            int x = reader.nextInt();
            Integer count = map.get(x);
            if (count == null)
            {
                count = 0;
            }

            count++;
            map.put(x, count);
        }

        List<Integer> ans = new ArrayList<Integer>();

        int maxCount = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet())
        {
            Integer number = entry.getKey();
            Integer count = entry.getValue();
            if (count > maxCount)
            {
                maxCount = count;
                ans.clear();
                ans.add(number);
            }
            else if (count == maxCount)
            {
                ans.add(number);
            }
        }

        for (Integer integer : ans)
        {
            writer.append(integer + "\n");
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
            while (!(tokenizer != null && tokenizer.hasMoreTokens()))
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

        public void print(boolean[] array)
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

        public void print(boolean[][] m)
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


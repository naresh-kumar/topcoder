// https://www.codechef.com/FEB13/status/CLMBSTRS,nemausus
// https://www.codechef.com/viewplaintext/1776332

import java.io.*;
import java.util.Collection;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Reader reader = new Reader(System.in);
        Writer writer = new Writer(System.out, false);
        //        Reader reader = new Reader("in.txt");
        //        Writer writer = new Writer(new FileOutputStream("output"), false);
        feb13ClimbingStairs(reader, writer);

        reader.close();
        writer.finish();
    }

    private static void feb13ClimbingStairs(Reader reader, Writer writer) throws IOException
    {
        int MOD = 1000000007;
        int t = reader.nextInt();
        int[] sol = new int[1000001];
        int max = 2;
        sol[1] = 1;
        sol[2] = 2;
        while (t-- > 0)
        {
            int n = reader.nextInt();
            int g = reader.nextInt();

            if (n > max)
            {
                for (int i = max + 1; i <= n; ++i)
                {
                    long temp = sol[i - 1] + sol[i - 2];
                    temp %= MOD;
                    sol[i] = (int) temp;
                }
                max = n;
            }
            int count = countOne(sol[n]);
            writer.append(count == g ? "CORRECT\n" : "INCORRECT\n");
        }
    }

    private static int countOne(int i)
    {
        int count = 0;
        while (i != 0)
        {
            if ((i & 1) == 1)
            {
                ++count;
            }
            i = i >> 1;
        }
        return count;
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
        private boolean fromFile;
        private long start;


        public Writer(OutputStream outputStream, boolean fromFile)
        {
            super(new BufferedOutputStream(outputStream));
            this.fromFile = fromFile;
            start = System.nanoTime();
        }

        public void finish()
        {
            if (fromFile)
            {
                println("time: " + (System.nanoTime() - start) / 1000000);
            }
            flush();
            close();
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

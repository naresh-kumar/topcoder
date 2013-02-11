
import java.io.*;
import java.util.Collection;
import java.util.StringTokenizer;

public class Solution
{

    static boolean debug = false;

    public static void main(String[] args) throws IOException
    {
        Reader reader = new Reader(System.in);
        Writer writer = new Writer(System.out, false);

        int[] array = new int[1000];
        int sum;
        while (true)
        {
            int n = reader.nextInt();
            if (n == 0) break;

            sum = 0;
            for (int i = 0; i < n; ++i)
            {
                int temp = reader.nextInt();
                if (temp < 0) temp = -temp;

                sum += temp;
                array[i] = temp;
            }

            boolean[][] part = new boolean[sum / 2 + 1][n + 1];

            // initialize top row as true
            for (int i = 0; i <= n; i++)
                part[0][i] = true;

            // initialize leftmost column, except part[0][0], as 0
            for (int i = 1; i <= sum / 2; i++)
                part[i][0] = false;

            // Fill the partition table in botton up manner
            for (int i = 1; i <= sum / 2; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    part[i][j] = part[i][j - 1];
                    if (i >= array[j - 1])
                        part[i][j] = part[i][j] || part[i - array[j - 1]][j - 1];
                }
            }

            for (int i = sum / 2; i >= 0; --i)
            {
                if (part[i][n])
                {
                    writer.append(sum - 2 * i + "\n");
                    break;
                }
            }
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
            logTime();
            flush();
            close();
        }

        public void logTime()
        {
            if (fromFile)
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


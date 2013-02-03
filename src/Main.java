
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
        //        Writer writer = new Writer(new FileOutputStream("output.txt"), false);
        hackerCupDeadPixels(reader, writer);

        reader.close();
        writer.finish();
    }

    private static class DPPoint
    {
        int left;
        int up;
    }

    private static void hackerCupDeadPixels(Reader reader, Writer writer) throws IOException
    {
        int t = reader.nextInt();
        int testCases = t;
        while (t-- > 0)
        {
            final int w = reader.nextInt();
            final int h = reader.nextInt();
            final int p = reader.nextInt();
            final int q = reader.nextInt();
            final int n = reader.nextInt();
            final int x = reader.nextInt();
            final int y = reader.nextInt();
            final int a = reader.nextInt();
            final int b = reader.nextInt();
            final int c = reader.nextInt();
            final int d = reader.nextInt();

            int[][] monitor = new int[h][w];

            int deadX = x;
            int deadY = y;

            monitor[deadY][deadX] = 1;
            for (int i = 1; i < n; ++i)
            {
                int tempDeadX = deadX;
                deadX = (deadX * a + deadY * b + 1) % w;
                deadY = (tempDeadX * c + deadY * d + 1) % h;
                monitor[deadY][deadX] = 1;
            }

//            for (int i = 0; i < h; ++i)
//            {
//                for (int j = 0; j < w; ++j)
//                {
//                    writer.append(monitor[i][j] + "");
//                }
//                writer.append("\n");
//            }

            DPPoint[][] dp = new DPPoint[h][w];

            int ans = 0;

            for (int i = 0; i < h; ++i)
            {
                for (int j = 0; j < w; ++j)
                {
                    DPPoint dpPoint = new DPPoint();
                    if (monitor[i][j] == 0)
                    {
                        dpPoint.up = i > 0 ? dp[i - 1][j].up + 1 : 1;
                        dpPoint.left = j > 0 ? dp[i][j - 1].left + 1 : 1;
                    }
                    dp[i][j] = dpPoint;

                    ans += check(dp, i, j, p, q);
                }
            }

            writer.append("Case #" + (testCases - t) + ": " + ans + "\n");
        }

    }

    private static int check(DPPoint[][] dp, int i, int j, int p, int q)
    {
        if (i >= q - 1 && j >= p - 1)
        {

            int min = Math.min(p, q);
            for (int loop = 0; loop < min; ++loop)
            {
                DPPoint dpPoint = dp[i - loop][j - loop];
                if (dpPoint.up < q - loop || dpPoint.left < p - loop)
                {
                    return 0;
                }
            }
            return 1;
        }
        return 0;
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


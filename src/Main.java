
import java.io.*;
import java.util.*;

public class Main
{

    static boolean debug = false;

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

    private static class Pixel implements Comparable<Pixel>
    {
        int x;
        int y;

        public Pixel(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pixel o)
        {
            return (x - o.x) != 0 ? (x - o.x) : y - o.y;
        }

        @Override
        public String toString()
        {
            return "[" + x + "," + y + "]";
        }

        @Override
        public boolean equals(Object o)
        {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pixel pixel = (Pixel) o;

            if (x != pixel.x) return false;
            if (y != pixel.y) return false;

            return true;
        }

        @Override
        public int hashCode()
        {
            int result = x;
            result = 31 * result + y;
            return result;
        }
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

            List<Pixel> deadPixels = new ArrayList<Pixel>(n);

            int deadX = x;
            int deadY = y;
            //            writer.logTime();
            deadPixels.add(new Pixel(deadY, deadX));
            for (int i = 1; i < n; ++i)
            {
                int tempDeadX = deadX;
                deadX = (deadX * a + deadY * b + 1) % w;
                deadY = (tempDeadX * c + deadY * d + 1) % h;
                deadPixels.add(new Pixel(deadY, deadX));
            }
            //            writer.logTime();

            Collections.sort(deadPixels);

            if (debug)
            {
                writer.append(deadPixels.toString() + "\n");
            }

            int[][] dpUp = new int[2][w];
            int[][] dpLeft = new int[2][w];
            int[][] dpOrder = new int[2][w];

            int ans = 0;

            int min = Math.min(p, q);
            int upDiff = q - min;
            int leftDiff = p - min;

            int curr = 0;
            int prev = inverse(curr);
            int currDeadIndex = 0;
            Pixel currDeadPixel = deadPixels.get(0);

            for (int i = 0; i < h; ++i)
            {
                for (int j = 0; j < w; ++j)
                {
                    int up = 0;
                    int left = 0;
                    int order = 0;
                    if (currDeadPixel == null || !pixelEquals(currDeadPixel, i, j))
                    {
                        up = i > 0 ? dpUp[prev][j] + 1 : 1;
                        left = j > 0 ? dpLeft[curr][j - 1] + 1 : 1;
                        int max_order = 1;
                        if (i > 0 && j > 0)
                        {
                            max_order = Math.max(dpOrder[prev][j - 1] + 1, 1);
                        }
                        int potential_order = Math.min(up - upDiff, left - leftDiff);
                        order = Math.min(max_order, potential_order);
                    }
                    else if (currDeadPixel != null)
                    {
                        while (true)
                        {
                            ++currDeadIndex;
                            if (currDeadIndex < deadPixels.size())
                            {
                                currDeadPixel = deadPixels.get(currDeadIndex);
                                if (!pixelEquals(currDeadPixel, i, j))
                                {
                                    break;
                                }
                            }
                            else
                            {
                                currDeadPixel = null;
                                break;
                            }
                        }
                    }
                    if (order >= min) ++ans;
                    dpUp[curr][j] = up;
                    dpLeft[curr][j] = left;
                    dpOrder[curr][j] = order;
                }
                prev = curr;
                curr = inverse(curr);
                if (debug)
                    writer.append("curr ans " + ans + "\n");
            }

            writer.append("Case #" + (testCases - t) + ": " + ans + "\n");
        }

    }

    private static boolean pixelEquals(Pixel currDeadPixel, int i, int j)
    {
        return currDeadPixel.x == i && currDeadPixel.y == j;
    }

    private static int inverse(int a)
    {
        return a ^ 1;
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


// https://www.codechef.com/APRIL15/status/BROKPHON,nemausus
// https://www.codechef.com/viewplaintext/6711298
import java.io.*;
import java.util.Arrays;
import java.util.Collection;
import java.util.StringTokenizer;

public class Main
{
  static int MOD = 1000000007;
  static int ie = 1000000;
  static long[] IE = new long[ie];
  static long[] arr = new long[1001];

  public static void main(String[] args) throws IOException
  {
    Reader reader = new Reader(System.in);
    Writer writer = new Writer(System.out, false);
    // Reader reader = new Reader("in.txt");
    // Writer writer = new Writer(new FileOutputStream("output"), false);
    BROKPHON(reader, writer);

    reader.close();
    writer.finish();
  }

  private static void BROKPHON(Reader reader, Writer writer) throws IOException
  {
    int t = reader.nextInt();
    while (t-- > 0)
    {
      int n = reader.nextInt();
      int last = 0;
      int ans = 0;
      int wrong = 0;
      for (int i = 0; i < n; ++i) {
        int curr = reader.nextInt();
        if (i > 0 && curr != last) {
          ans += 2 - wrong;
          wrong = 1;
        }
        else
        {
          wrong = 0;
        }
        last = curr;
      }
      writer.append(ans + "\n");
    }
  }

  static long pow(int a, int b)
  {
    long x = 1, y = a;
    while (b > 0)
    {
      if (b % 2 == 1)
      {
        x = (x * y);
        if (x > MOD) x %= MOD;
      }
      y = (y * y);
      if (y > MOD) y %= MOD;
      b /= 2;
    }
    return x;
  }

  static long InverseEuler(int n)
  {
    if (n < ie)
    {
      if (IE[n] == -1)
        IE[n] = pow(n, MOD - 2);
      return IE[n];
    }

    return pow(n, MOD - 2);
  }

  static long nCr(int n, int r)
  {
    r = Math.min(r, n - r);
    return (arr[n] * ((InverseEuler((int) arr[r]) * InverseEuler((int) arr[n - r])) % MOD)) % MOD;
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

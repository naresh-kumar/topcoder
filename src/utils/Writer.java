package utils;


import java.io.BufferedOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collection;

public class Writer extends PrintWriter
{
    private long start;

    public Writer(OutputStream outputStream)
    {
        super(new BufferedOutputStream(outputStream));
        start = System.nanoTime();
    }

    public void finish()
    {
        flush();
        close();
    }

    public void logTime()
    {
        println("time: " + (System.nanoTime() - start) / 1000000);
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
        for (int[] aM : m)
        {
            print(aM);
        }
    }

    public void print(boolean[][] m)
    {
        for (boolean[] aM : m)
        {
            print(aM);
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

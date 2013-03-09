package utils;

import java.util.List;
import java.util.Random;

public class Utils
{

    private Utils()
    {
        // do nothing
    }

    public static long getMemory()
    {
        Runtime runtime = Runtime.getRuntime();
        runtime.gc();
        return runtime.totalMemory() - runtime.freeMemory();
    }
}


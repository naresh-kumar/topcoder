import java.util.HashMap;
import java.util.Map;

public class TimeTracker
{
    private static Map<String, Long> map = new HashMap<String, Long>();

    public static void start(String eventName)
    {
        if (map.get(eventName) != null)
        {
            throw new IllegalArgumentException("tracking already started for " + eventName);
        }
        map.put(eventName, System.nanoTime());
    }

    public static long get(String eventName)
    {
        if (map.get(eventName) == null)
        {
            throw new IllegalArgumentException("tracking was not started for " + eventName);
        }
        long timeTaken = (System.nanoTime() - map.get(eventName)) / 1000000;
        System.out.println(eventName + " time taken: " + timeTaken);
        return timeTaken;
    }

    public static long stop(String eventName)
    {
        if (map.get(eventName) == null)
        {
            throw new IllegalArgumentException("tracking was not started for " + eventName);
        }
        long timeTaken = (System.nanoTime() - map.remove(eventName)) / 1000000;
        System.out.println(eventName + " time taken: " + timeTaken);
        return timeTaken;
    }

    public static long getBestTime(Runnable runnable, int iteration)
    {
        long best = 999999999999999999L;
        for (int i = 0; i < iteration; ++i)
        {
            start("a");
            runnable.run();
            best = Math.min(best, stop("a"));
        }
        return best;
    }
}

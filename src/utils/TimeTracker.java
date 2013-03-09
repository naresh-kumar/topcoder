package utils;


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

    public static void get(String eventName)
    {
        if (map.get(eventName) == null)
        {
            throw new IllegalArgumentException("tracking was not started for " + eventName);
        }
        System.out.println(eventName + " time taken: " + ((System.nanoTime() - map.get(eventName)) / 1000000));
    }

    public static void stop(String eventName)
    {
        if (map.get(eventName) == null)
        {
            throw new IllegalArgumentException("tracking was not started for " + eventName);
        }
        System.out.println(eventName + " time taken: " + ((System.nanoTime() - map.remove(eventName)) / 1000000));
    }
}


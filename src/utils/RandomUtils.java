package utils;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class RandomUtils
{
    private static final Random random = new Random();
    private static final String lowercaseAlphabet = "qwertyuiopasdfghjklzxcvbnm";
    private static final String uppercaseAlphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
    private static final String digits = "0123456789";
    private static final String characters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";

    private RandomUtils()
    {
    }

    public enum CharType
    {
        LOWER, UPPER, DIGIT, ALL
    }

    public static int getInt(int limit)
    {
        return random.nextInt(limit);
    }

    public static long getLong(long limit)
    {
        return random.nextLong();
    }

    public static String getString(int len, CharType charType)
    {
        char[] result = new char[len];
        String dict;
        switch (charType)
        {
            case LOWER:
                dict = lowercaseAlphabet;
                break;
            case UPPER:
                dict = uppercaseAlphabet;
                break;
            case DIGIT:
                dict = digits;
                break;
            case ALL:
                dict = characters;
                break;
            default:
                dict = characters;
        }

        for (int i = 0; i < len; ++i)
        {
            result[i] = dict.charAt(getInt(dict.length()));
        }

        return new String(result);
    }

    public static int[] getArray(int size, int limit)
    {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i)
        {
            array[i] = getInt(limit);
        }
        return array;
    }

    public static List<Integer> getArrayList(int size, int limit)
    {
        List<Integer> list = new ArrayList<Integer>(size);
        for (int i = 0; i < size; ++i)
        {
            list.add(getInt(limit));
        }
        return list;
    }

    public static List<String> getStringList(int size, int len, CharType charType)
    {
        List<String> list = new ArrayList<String>(size);
        for (int i = 0; i < size; ++i)
        {
            list.add(getString(len, charType));
        }
        return list;
    }
}

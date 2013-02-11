import java.util.Random;

public class RandomGenerator
{
    public int[] getNumbers(int size, int min, int max)
    {
        Random random = new Random();
        int[] numbers = new int[size];
        for (int i = 0; i < size; ++i)
        {
            numbers[i] = random.nextInt(max - min) + min;

        }
        return numbers;
    }

    public String getNumbers(int size, int min, int max, char delimiter)
    {
        int[] numbers = getNumbers(size, min, max);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < size; ++i)
        {
            sb.append(numbers[i]).append(delimiter);
        }
        return sb.toString();
    }
}

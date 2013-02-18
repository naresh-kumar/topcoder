public class Permutation
{
    public void printAllPermutations(String string)
    {
        char[] chars = string.toCharArray();

        permute(chars, 0, new Count());
    }

    private void permute(char[] chars, int i, Count count)
    {
        if (i == chars.length - 1)
        {
            System.out.println(count.count + " " + new String(chars));
            count.count++;
        }
        else
        {
            for (int j = i; j < chars.length; ++j)
            {
                swap(chars, i, j);
                permute(chars, i + 1, count);
                swap(chars, i, j);
            }
        }
    }

    private void swap(char[] chars, int i, int j)
    {
        char c = chars[i];
        chars[i] = chars[j];
        chars[j] = c;
    }

    private static class Count
    {
        int count=1;
    }
}

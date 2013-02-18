import java.util.Arrays;

public class Permutation
{
    public void printAllPermutations(String string)
    {
        char[] chars = string.toCharArray();

        permute(chars, 0, new Count());
    }

    public void printAllPermutationsWithDuplicates(String string)
    {
        char[] chars = string.toCharArray();

        permuteWithDuplicates(chars, 0, new Count());
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

    private void permuteWithDuplicates(char[] chars, int i, Count count)
    {
//        System.out.println("i" + i + " " + new String(chars));
        if (i == chars.length - 1)
        {
            System.out.println(count.count + " " + new String(chars));
            count.count++;
        }
        else
        {
            boolean[] used = new boolean[26];
            Arrays.fill(used, false);
            for (int j = i; j < chars.length; ++j)
            {
//                System.out.println(i + " " + j +  " " + new String(chars));
                if (!used[chars[j] - 'a'])
                {
                    used[chars[j] - 'a'] = true;
                    swap(chars, i, j);
                    permuteWithDuplicates(chars, i + 1, count);
                    swap(chars, i, j);
                }
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
        int count = 1;
    }
}

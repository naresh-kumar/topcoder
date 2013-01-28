import java.io.IOException;
import java.util.Arrays;

public class solutions
{

    private static void hackerCup3(Solution.Reader reader, Solution.Writer writer) throws IOException
    {
        int t = reader.nextInt();
        for (int testCase = 1; testCase <= t; ++testCase)
        {
            int n = reader.nextInt();
            int k = reader.nextInt();
            int a = reader.nextInt();
            int b = reader.nextInt();
            int c = reader.nextInt();
            int r = reader.nextInt();

            int index[] = new int[k];
            Arrays.fill(index, -1);


            long prev = a;

            if (prev < k) index[(int) prev] = 0;

            for (int i = 1; i < k; ++i)
            {
                prev = (b * prev) % r;
                if (prev < 0) prev += r;
                prev = (prev + c) % r;
                if (prev < 0) prev += r;
                if (prev < k) index[(int) prev] = i;
            }

            //            writer.print(index);

            int seq[] = new int[k + 1];
            Arrays.fill(seq, -1);

            int firstEmptyIndex = 0;

            int missing = -1;
            for (int i = 0; i < k; ++i)
            {
                if (index[i] == -1)
                {
                    seq[firstEmptyIndex] = i;
                    while (firstEmptyIndex < k && seq[firstEmptyIndex] != -1) ++firstEmptyIndex;
                }
                else
                {
                    int start = index[i] + 1;
                    while (start < k && seq[start] > 0) ++start;
                    if (start < k) seq[start] = i;
                    else missing = i;
                    while (firstEmptyIndex < k && seq[firstEmptyIndex] > 0) ++firstEmptyIndex;
                }
            }

            for (int i = 0; i < k; ++i)
            {
                if (seq[i] == -1)
                {
                    seq[i] = k;
                    break;
                }
            }

            if (missing == -1)
                seq[k] = k;
            else seq[k] = missing;

            //            writer.print(seq);

            int i = (n - k - 1) % (k + 1);
            if (i < 0) i += k + 1;
            writer.append("Case #" + testCase + ": " + seq[i] + "\n");

        }
    }

}

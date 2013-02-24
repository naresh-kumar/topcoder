public class RegexParser
{
    public static boolean match(String pattern, String string)
    {
        int p = 0;
        for (int i = 0; i < pattern.length(); ++i)
        {
            char c = pattern.charAt(i);
            if (i < pattern.length() - 1 && pattern.charAt(i + 1) == '*')
            {
                ++i;
                if (c == '.') return true;
                else
                    while (p < string.length() && string.charAt(p) == c) p++;
            }
            else if (p < string.length() && string.charAt(p) == c)
            {
                p++;
            }
            else return false;
        }

        return p == string.length();
    }
}

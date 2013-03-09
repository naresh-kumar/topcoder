package misc;

public class DecToBinary
{
    public static String printBinary(String n)
    {
        int intPart = Integer.parseInt(n.substring(0, n.indexOf('.')));
        int decPart = Integer.parseInt(n.substring(n.indexOf('.') + 1, n.length()));

        String int_string = "";

        while (intPart > 0)
        {
            int r = intPart % 2;
            intPart >>= 1;
            int_string = r + int_string;
        }

        StringBuffer dec_string = new StringBuffer();

        while (decPart > 0)
        {
            System.out.println(decPart);
            if (dec_string.length() > 32) return "ERROR";

            if (decPart == 1)
            {
                dec_string.append((int) decPart);
                break;
            }

            int r = decPart * 2;
            if (r >= 1)
            {
                dec_string.append(1);
                decPart = r - 1;
            }
            else
            {
                dec_string.append(0);
                decPart = r;
            }
            System.out.println(decPart);
        }

        return int_string + "." + dec_string.toString();
    }

}

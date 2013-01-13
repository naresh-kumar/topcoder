import com.google.i18n.phonenumbers.NumberParseException;
import com.google.i18n.phonenumbers.PhoneNumberUtil;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class PhoneNumberBoiler implements Runnable
{
    private static Reader reader;
    private static FileWriter writer;
    private static boolean fromFile = true;

    @Override
    public void run()
    {
        try
        {
            reader = fromFile ? new Reader("large_input") : new Reader(System.in);
            writer = new FileWriter("output");

            List<String> raw_numbers = new ArrayList<String>();

            String number = reader.nextLine();
            while (number != null)
            {
                raw_numbers.add(number);
                number = reader.nextLine();
            }

            List<String> numbers = new ArrayList<String>();
            PhoneNumberUtil util = PhoneNumberUtil.getInstance();

            TimeTracker.start("a");
            for (String string : raw_numbers)
            {
                numbers.add(util.parse(string, "IN").toString());
            }
            TimeTracker.stop("a");

            for (String string : numbers)
            {
                writer.append(string).append("\n");
            }
            reader.close();
            writer.flush();
            writer.close();

        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace();
        }
        catch (NumberParseException e)
        {
            e.printStackTrace();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}

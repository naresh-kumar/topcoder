import com.google.i18n.phonenumbers.NumberParseException;
import com.google.i18n.phonenumbers.PhoneNumberUtil;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TopCoder
{
    private static Reader reader;
    private static Writer writer;
    private static boolean fromFile = false;

    public static void main(String[] args) throws IOException, NumberParseException
    {
        reader = fromFile ? new Reader("in") : new Reader(System.in);
        writer = new Writer(System.out, fromFile);

        List<String> list = new ArrayList<String>();
        for (long i = 9873950000L; i < 9873960000L; ++i)
        {
            list.add("+91"+String.valueOf(i));
        }

        PhoneNumberUtil util = PhoneNumberUtil.getInstance();
        TimeTracker.start("a");
        for (String number: list)
        {
            util.parse(number, "IN");
        }
        TimeTracker.stop("a");
        reader.close();
        writer.finish();
    }


}


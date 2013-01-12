import java.io.IOException;

public class TopCoder
{
    private static Reader reader;
    private static Writer writer;
    private static boolean fromFile = false;

    public static void main(String[] args) throws IOException
    {
        reader = fromFile ? new Reader("in") : new Reader(System.in);
        writer = new Writer(System.out, fromFile);


        reader.close();
        writer.finish();
    }


}


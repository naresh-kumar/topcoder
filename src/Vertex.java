public class Vertex
{
    int id;
    Color color = Color.White;
    Vertex parent;
    int d;

    public Vertex(int id)
    {
        this.id = id;
    }

    enum Color
    {
        White, Gray, Black
    }
}

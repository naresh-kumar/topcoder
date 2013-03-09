package graph;

public class Vertex
{
    int id;
    Color color = Color.White;
    Vertex parent;
    int distance;
    int discoverTime;
    int finishTime;

    public Vertex(int id)
    {
        this.id = id;
    }

    enum Color
    {
        White, Gray, Black
    }

    @Override
    public String toString()
    {
        return "{id=" + id + ", time=[" + discoverTime + " " + finishTime + "]" + ", dist=" + distance + ", color=" + color + "}";
    }
}

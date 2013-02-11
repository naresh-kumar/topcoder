import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Graph
{
    List<List<Vertex>> adjacencyList;
    List<Vertex> vertexes;

    public void Graph(int count)
    {
        adjacencyList = new ArrayList<List<Vertex>>(count);
        vertexes = new ArrayList<Vertex>(count);
        for (int i = 0; i < count; ++i)
        {
            adjacencyList.add(new ArrayList<Vertex>());
            vertexes.add(new Vertex(i));
        }
    }

    public void addDirectedEdge(int from, int to)
    {
        adjacencyList.get(from).add(vertexes.get(to));
    }

    public void addEdge(int from, int to)
    {
        adjacencyList.get(from).add(vertexes.get(to));
        adjacencyList.get(to).add(vertexes.get(from));
    }

    public void bfs(int s, int x)
    {
        Vertex source = vertexes.get(s);
        source.color = Vertex.Color.Gray;
        source.d = 0;
        Queue<Vertex> queue = new LinkedList<Vertex>();
        queue.add(source);
        while (queue.size() > 0)
        {
            Vertex curr = queue.remove();
            for (Vertex vertex : adjacencyList.get(curr.id))
            {
                if (vertex.color == Vertex.Color.White)
                {
                    vertex.color = Vertex.Color.Gray;
                    vertex.d = curr.d + 1;
                    vertex.parent = curr;
                    queue.add(vertex);
                }
            }
            curr.color = Vertex.Color.Black;
        }
    }
}

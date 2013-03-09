package graph;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Graph
{
    List<List<Vertex>> adjacencyList;
    List<Vertex> vertexes;

    public Graph(int count)
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
        source.distance = 0;
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
                    vertex.distance = curr.distance + 1;
                    vertex.parent = curr;
                    queue.add(vertex);
                }
            }
            curr.color = Vertex.Color.Black;
        }
    }

    public List<Vertex> topologicalSort(int x)
    {
        Vertex source = vertexes.get(x);
        Integer time = 0;

        List<Vertex> list = new ArrayList<Vertex>();

        dfs(source, time, list);
        return list;
    }

    private void dfs(Vertex curr, Integer time, List<Vertex> list)
    {
        time += 1;
        curr.color = Vertex.Color.Gray;
        curr.discoverTime = time;

        for (Vertex vertex : adjacencyList.get(curr.id))
        {
            if (vertex.color == Vertex.Color.White)
            {
                dfs(vertex, time, list);
            }
        }

        time += 1;
        curr.color = Vertex.Color.Black;
        curr.finishTime = time;
        list.add(curr);
    }
}

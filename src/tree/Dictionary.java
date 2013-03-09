package tree;

import java.util.ArrayList;
import java.util.List;

public class Dictionary
{
    Node head = new Node();

    public void addWord(String word, String meaning)
    {
        Node node = head;
        for (char c : word.toCharArray())
        {
            boolean exist = false;
            for (Node n : node.children)
            {
                if (n.c == c)
                {
                    exist = true;
                    node = n;
                }
            }

            if (!exist)
            {
                Node node1 = new Node();
                node1.c = c;
                node.children.add(node1);
                node = node1;
            }
        }
        node.meaning = meaning;
    }

    public String meaning(String word)
    {
        Node node = head;
        for (char c : word.toCharArray())
        {
            boolean exist = false;
            for (Node n : node.children)
            {
                if (n.c == c)
                {
                    exist = true;
                    node = n;
                }
            }

            if (!exist)
            {
                return null;
            }
        }
        return node.meaning;
    }

    private static class Node
    {
        char c;
        List<Node> children = new ArrayList<Node>();
        String meaning;
    }
}

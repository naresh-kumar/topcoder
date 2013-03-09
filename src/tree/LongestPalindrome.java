package tree;

import java.util.ArrayList;
import java.util.List;

public class LongestPalindrome
{
    public String getLongestPalindrome(char[] string)
    {
        int length = string.length;
        char[] s = new char[length + 1];
        char[] r = new char[length + 1];

        for (int i = 0; i < length; ++i)
        {
            r[i] = string[length - i - 1];
            s[i] = string[i];
        }

        s[length] = '$';
        r[length] = '#';

        Node suffixTree = new Node(' ');

        addToTree(s, length, suffixTree);
        addToTree(r, length, suffixTree);

        dfs(suffixTree, 0, length);

        return null;

    }

    private void addToTree(char[] s, int length, Node suffixTree)
    {
        for (int i = 0; i < length; ++i)
        {
            Node curr = suffixTree;
            for (int j = i; j < length + 1; ++j)
            {
                boolean found = false;
                for (Node node : curr.list)
                {
                    if (node.c == s[j])
                    {
                        curr = node;
                        found = true;
                    }
                }

                if (!found)
                {
                    Node n = new Node(s[j]);
                    curr.list.add(n);
                    curr = n;
                }
            }
        }
    }

    private IndexInfo dfs(Node node, int level, int length)
    {
        IndexInfo indexInfo = new IndexInfo();
        if (node.c == '$')
        {
            indexInfo.first.add(length - level + 1);
        }
        else if (node.c == '#')
        {
            indexInfo.second.add(length - level + 1);
        }
        else
        {
            for (Node n : node.list)
            {
                IndexInfo ii = dfs(n, level + 1, length);
                indexInfo.first.addAll(ii.first);
                indexInfo.second.addAll(ii.second);
            }

            System.out.println(node.c + " " + indexInfo.first + " " + indexInfo.second);
        }
        return indexInfo;
    }

    public static class Node
    {
        char c;
        List<Node> list = new ArrayList<Node>();

        public Node(char c)
        {
            this.c = c;
        }
    }

    public static class IndexInfo
    {
        List<Integer> first = new ArrayList<Integer>();
        List<Integer> second = new ArrayList<Integer>();
    }
}

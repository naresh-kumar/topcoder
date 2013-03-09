package tree;

import java.util.Arrays;

public class Traversal
{
    public static Node createTreeByPreAndInOrder(int[] pre, int[] in)
    {
        System.out.println(Arrays.toString(pre));
        System.out.println(Arrays.toString(in));
        postOrder(pre, 0, pre.length - 1, in, 0, in.length - 1);
        System.out.println();
        return createTreeByPreAndInOrder(pre, 0, pre.length - 1, in, 0, in.length - 1);
    }

    private static void postOrder(int[] pre, int i, int j, int[] in, int k, int l)
    {
        if (i >= pre.length || j >= pre.length || k >= pre.length || l >= pre.length) return;

        if (i == j)
            System.out.print(pre[i] + " - ");
        else
        {
            int rootIndex = k;
            while (in[rootIndex] != pre[i]) rootIndex++;

            postOrder(pre, i + 1, i + rootIndex - k, in, k, rootIndex - 1);
            postOrder(pre, i + rootIndex - k + 1, j, in, rootIndex + 1, l);
            System.out.print(in[rootIndex] + " - ");
        }
    }

    private static Node createTreeByPreAndInOrder(int[] pre, int i, int j, int[] in, int k, int l)
    {
        if (i >= pre.length || j >= pre.length || k >= pre.length || l >= pre.length) return null;

        if (i == j)
            return new Node(pre[i]);

        int rootIndex = k;
        while (in[rootIndex] != pre[i]) rootIndex++;

        Node node = new Node(in[rootIndex]);
        node.left = createTreeByPreAndInOrder(pre, i + 1, i + rootIndex - k, in, k, rootIndex - 1);
        node.right = createTreeByPreAndInOrder(pre, i + rootIndex - k + 1, j, in, rootIndex + 1, l);
        return node;
    }

    public static void pre(Node node)
    {
        if (node == null) return;
        System.out.print(node.data + " ");
        pre(node.left);
        pre(node.right);
    }

    public static void post(Node node)
    {
        if (node == null) return;
        post(node.left);
        post(node.right);
        System.out.print(node.data + " ");
    }

    public static void in(Node node)
    {
        if (node == null) return;
        in(node.left);
        System.out.print(node.data + " ");
        in(node.right);
    }
}

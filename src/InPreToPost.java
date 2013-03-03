import java.util.Arrays;

public class InPreToPost
{
    public static TreeNode create(int[] pre, int[] in)
    {
        System.out.println(Arrays.toString(pre));
        System.out.println(Arrays.toString(in));
        postOrder(pre, 0, pre.length - 1, in, 0, in.length - 1);
        System.out.println();
        return create(pre, 0, pre.length - 1, in, 0, in.length - 1);
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

    private static TreeNode create(int[] pre, int i, int j, int[] in, int k, int l)
    {
        if (i >= pre.length || j >= pre.length || k >= pre.length || l >= pre.length) return null;

        if (i == j)
            return new TreeNode(pre[i]);

        int rootIndex = k;
        while (in[rootIndex] != pre[i]) rootIndex++;

        TreeNode node = new TreeNode(in[rootIndex]);
        node.left = create(pre, i + 1, i + rootIndex - k, in, k, rootIndex - 1);
        node.right = create(pre, i + rootIndex - k + 1, j, in, rootIndex + 1, l);
        return node;
    }

    public static void pre(TreeNode node)
    {
        if (node == null) return;
        System.out.print(node.data + " ");
        pre(node.left);
        pre(node.right);
    }

    public static void post(TreeNode node)
    {
        if (node == null) return;
        post(node.left);
        post(node.right);
        System.out.print(node.data + " ");
    }

    public static void in(TreeNode node)
    {
        if (node == null) return;
        in(node.left);
        System.out.print(node.data + " ");
        in(node.right);
    }
}

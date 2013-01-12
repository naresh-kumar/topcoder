public class AvlTree
{
    private Node root;

    void add(Node node)
    {
        if (root == null)
        {
            root = node;
        }
        else
        {
            insert(root, node);
        }
    }

    void insert(Node curr, Node node)
    {
        if (node.data < curr.data)
        {
            if (curr.left == null)
            {
                curr.left = node;
                node.parent = curr;
            }
            else
            {
                insert(curr.left, node);
            }
        }
        else
        {

            if (curr.right == null)
            {
                curr.right = node;
                node.parent = curr;
            }
            else
            {
                insert(curr.right, node);
            }
        }

        int left = height(curr.left);
        int right = height(curr.right);
        curr.height = Math.max(left, right) + 1;

        if (bFactor(curr) > 1)
        {
            if (bFactor(curr.left) < 0)
            {
                leftRotate(curr.left);
            }
            rightRotate(curr);
        }
        else if (bFactor(curr) < -1)
        {
            if (bFactor(curr.right) > 0)
            {
                rightRotate(curr.right);
            }
            leftRotate(curr);
        }
    }

    private void rightRotate(Node node)
    {
        Node parent = node.parent;
        Node left = node.left;

        if (parent != null)
        {
            if (parent.left == node) parent.left = left;
            else parent.right = left;
        }
        else
        {
            root = left;
        }

        left.parent = parent;
        node.parent = left;

        Node leftRight = left.right;
        left.right = node;
        node.left = leftRight;
        if (leftRight != null) leftRight.parent = node;

        node.height = Math.max(height(node.left), height(node.right)) + 1;
        left.height = Math.max(height(left.left), height(left.right)) + 1;
        if (parent != null)
            parent.height = Math.max(height(parent.left), height(parent.right)) + 1;

    }

    private void leftRotate(Node node)
    {
        Node parent = node.parent;
        Node right = node.right;

        if (parent != null)
        {
            if (parent.left == node) parent.left = right;
            else parent.right = right;
        }
        else
        {
            root = right;
        }

        right.parent = parent;
        node.parent = right;

        Node rightLeft = right.left;
        right.left = node;
        node.right = rightLeft;
        if (rightLeft != null) rightLeft.parent = node;

        node.height = Math.max(height(node.left), height(node.right)) + 1;
        right.height = Math.max(height(right.left), height(right.right)) + 1;
        if (parent != null)
            parent.height = Math.max(height(parent.left), height(parent.right)) + 1;

    }

    private int height(Node node)
    {
        return node == null ? 0 : node.height;
    }

    private int bFactor(Node node)
    {
        return node == null ? 0 : height(node.left) - height(node.right);
    }

    void print(Node node, Writer writer)
    {
        if (node != null)
        {
            print(node.left, writer);
            writer.print(node.data + "[" + node.height + "] ");
            print(node.right, writer);
        }
    }
}
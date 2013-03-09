package tree;

public class AvlTree
{
    private AvlTreeNode root;
    private int counter;

    public void add(AvlTreeNode node)
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

    private void insert(AvlTreeNode curr, AvlTreeNode node)
    {
        curr.size++;
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

    private void rightRotate(AvlTreeNode node)
    {
        AvlTreeNode parent = node.parent;
        AvlTreeNode left = node.left;

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

        AvlTreeNode leftRight = left.right;
        left.right = node;
        node.left = leftRight;
        if (leftRight != null) leftRight.parent = node;

        node.height = Math.max(height(node.left), height(node.right)) + 1;
        left.height = Math.max(height(left.left), height(left.right)) + 1;
        if (parent != null)
            parent.height = Math.max(height(parent.left), height(parent.right)) + 1;

    }

    private void leftRotate(AvlTreeNode node)
    {
        AvlTreeNode parent = node.parent;
        AvlTreeNode right = node.right;

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

        AvlTreeNode rightLeft = right.left;
        right.left = node;
        node.right = rightLeft;
        if (rightLeft != null) rightLeft.parent = node;

        node.height = Math.max(height(node.left), height(node.right)) + 1;
        right.height = Math.max(height(right.left), height(right.right)) + 1;
        if (parent != null)
            parent.height = Math.max(height(parent.left), height(parent.right)) + 1;

    }

    private int height(AvlTreeNode node)
    {
        return node == null ? 0 : node.height;
    }

    private int bFactor(AvlTreeNode node)
    {
        return node == null ? 0 : height(node.left) - height(node.right);
    }

    private void print(AvlTreeNode node, Solution.Writer writer)
    {
        if (node != null)
        {
            print(node.left, writer);
            writer.println("[" + counter + "] " + node);
            counter += 1;
            print(node.right, writer);
        }
    }

    public void print(Solution.Writer writer)
    {
        counter = 0;
        print(root, writer);
        writer.println();
    }

    public AvlTreeNode find(int i)
    {
        counter = 0;
        return find(this.root, i);
    }

    public AvlTreeNode findR(int i)
    {
        counter = 0;
        return findR(this.root, i);
    }


    private AvlTreeNode find(AvlTreeNode node, int i)
    {
        AvlTreeNode res = null;
        if (node != null)
        {
            res = find(node.left, i);
            if (res == null)
            {
                if (counter == i) res = node;
                counter += 1;
            }
            if (res == null)
                res = find(node.right, i);
        }
        return res;
    }

    private AvlTreeNode findR(AvlTreeNode node, int i)
    {
        AvlTreeNode res = null;
        if (node != null)
        {
            res = findR(node.right, i);
            if (res == null)
            {
                if (counter == i) res = node;
                counter += 1;
            }
            if (res == null)
                res = findR(node.left, i);
        }
        return res;
    }

    public AvlTreeNode getRoot()
    {
        return root;
    }
}
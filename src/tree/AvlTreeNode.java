package tree;

public class AvlTreeNode
{
    AvlTreeNode left;
    AvlTreeNode right;
    AvlTreeNode parent;
    int data;
    int height;
    int size;

    public AvlTreeNode(int data)
    {
        this.data = data;
        this.height = 1;
        this.size = 1;
    }

    @Override
    public String toString()
    {
        return "data:" + data + " size:" + size + " height:" + height;
    }
}
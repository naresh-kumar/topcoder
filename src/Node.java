public class Node
{
    Node left;
    Node right;
    Node parent;
    int data;
    int height;
    int size;

    public Node(int data)
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
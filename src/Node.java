public class Node
{
    Node left;
    Node right;
    Node parent;
    int data;
    int height;

    public Node(int data)
    {
        this.data = data;
        this.height = 1;
    }
}
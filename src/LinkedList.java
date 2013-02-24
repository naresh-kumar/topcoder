public class LinkedList
{
    public static class Node
    {
        int data;
        Node next;

        public Node(int data)
        {
            this.data = data;
        }
    }

    public void removeDuplicates(Node head)
    {
        Node curr = head;

        while (curr.next != null)
        {
            if (isDuplicate(curr.next, head))
            {
                curr.next = curr.next.next;
            }
            else
            {
                curr = curr.next;
            }
        }
    }

    private boolean isDuplicate(Node next, Node head)
    {
        while (head != next)
        {
            if (head.data == next.data)
            {
                return true;
            }
            head = head.next;
        }

        return false;
    }

    public Node createLinkedList(int[] array)
    {
        Node head = null;
        for (int i : array)
        {
            if (head == null) head = new Node(i);
            else
            {
                Node node = new Node(i);
                node.next = head;
                head = node;
            }
        }
        return head;
    }

    public void print(Node node)
    {
        while (node != null)
        {
            System.out.println(node.data);
            node = node.next;
        }
    }

    public Node add(Node first, Node second)
    {
        int carry = 0;
        Node sum = null;
        Node tail = null;
        while (first != null || second != null)
        {
            if (first != null) carry += first.data;
            if (second != null) carry += second.data;

            if (sum == null)
            {
                sum = new Node(carry % 10);
                tail = sum;
            }
            else
            {
                tail.next = new Node(carry % 10);
                tail = tail.next;
            }
            carry = carry / 10;

            first = first == null ? null : first.next;
            second = second == null ? null : second.next;
        }

        if (carry > 0)
        {
            tail.next = new Node(carry);
        }

        return sum;
    }
}

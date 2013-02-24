import org.junit.Test;

import java.util.Stack;

import static junit.framework.Assert.assertFalse;
import static junit.framework.Assert.assertTrue;

public class Tests
{
    @Test
    public void helloWorld()
    {
        System.out.println("hello world");
    }

    @Test
    public void palindrome()
    {
        new Permutation().printAllPermutationsWithDuplicates("aaabb");
    }

    @Test
    public void removeDuplicatesTest()
    {
        int[] array = {1, 1, 2, 3, 4, 5, 6, 6, 3, 3, 2, 2};
        LinkedList rd = new LinkedList();
        LinkedList.Node linkedList = rd.createLinkedList(array);
        rd.removeDuplicates(linkedList);
        rd.print(linkedList);
    }

    @Test
    public void addLinkedList()
    {
        int[] first = {9, 8, 8};
        int[] second = {1, 1, 1};

        LinkedList rd = new LinkedList();
        rd.print(rd.add(rd.createLinkedList(first), rd.createLinkedList(second)));
    }

    @Test
    public void testStack()
    {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(8);
        System.out.println(stack.pop());
    }

    @Test
    public void towerOfHanoi()
    {
        TowerOfHanoi.Tower s = new TowerOfHanoi.Tower(1);
        TowerOfHanoi.Tower d = new TowerOfHanoi.Tower(2);
        TowerOfHanoi.Tower b = new TowerOfHanoi.Tower(3);

        for (int i = 0; i < 5; i++)
        {
            s.push(5 - i);
        }

        new TowerOfHanoi().move(5, s, d, b);
    }

    @Test
    public void decToBinary()
    {
        int a = 14;

        int neg = 0;

        int d = a < 0 ? 1 : -1;

        while (a != 0)
        {
            neg += d;
            a += d;
        }

        System.out.println(neg);
    }

    @Test
    public void checkEqual()
    {
        assertTrue(RegexParser.match("a*", "aa"));
        assertFalse(RegexParser.match("a*", "ab"));
        assertTrue(RegexParser.match("a*b", "ab"));
        assertFalse(RegexParser.match("a*bcda", "aaaaaaaaaabcdaa"));
        assertTrue(RegexParser.match("a*bcda*uu", "aaaaaaaaaabcdaauu"));
        assertFalse(RegexParser.match("abcd", "abcde"));
    }

}


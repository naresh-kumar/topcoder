import dp.LCSString;
import dp.SubsetSum;
import misc.Permutation;
import misc.RegexParser;
import misc.TowerOfHanoi;
import org.junit.Test;
import tree.LinkedList;
import tree.Node;
import tree.Traversal;
import utils.MathUtils;
import utils.RandomUtils;
import utils.TimeTracker;

import java.util.Arrays;
import java.util.List;
import java.util.Stack;

import static junit.framework.Assert.*;

public class Tests
{
    @Test
    public void helloWorld()
    {
        System.out.println("hello world");
        System.out.println(MathUtils.multiply("343".toCharArray(), "2".toCharArray()));
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

    @Test
    public void inPrePost()
    {
        Node node = Traversal.createTreeByPreAndInOrder(new int[]{1, 2, 3, 5, 8, 9, 6, 10, 4, 7}, new int[]{2, 1, 8, 5, 9, 3, 10, 6, 7, 4});
        Traversal.pre(node);
        System.out.println();
        Traversal.post(node);
        System.out.println();
        Traversal.in(node);
        System.out.println();
    }

    @Test
    public void subSetSum()
    {
        SubsetSum.isSumZero(new int[]{-7, -3, -2, -8, 8});
    }

    @Test
    public void testStringLCS()
    {
        assertEquals(0, LCSString.getLCSLength(Arrays.asList("abc", "aac"), Arrays.asList("abb", "aab")));
        assertEquals(0, LCSString.getLCSLengthSorting(Arrays.asList("abc", "aac"), Arrays.asList("abb", "aab")));
        assertEquals(1, LCSString.getLCSLength(Arrays.asList("abc", "aac"), Arrays.asList("abb", "abc")));
        assertEquals(1, LCSString.getLCSLengthSorting(Arrays.asList("abc", "aac"), Arrays.asList("abb", "abc")));
        List<String> list1 = Arrays.asList("abc", "bde", "yyy", "uuu");
        List<String> list2 = Arrays.asList("abc", "bde", "yyy", "uuu");
        assertEquals(4, LCSString.getLCSLength(list1, list2));
        assertEquals(4, LCSString.getLCSLengthSorting(list1, list2));
        list1 = Arrays.asList("abc", "bde", "yyy", "uuu", "dfdfd");
        list2 = Arrays.asList("abc", "bde", "dfdfd", "yyy", "uuu");
        assertEquals(4, LCSString.getLCSLength(list1, list2));
        assertEquals(5, LCSString.getLCSLengthSorting(list1, list2));
    }

    @Test
    public void perfTestStringLCS()
    {
        List<String> strings1 = RandomUtils.getStrings(10000, 200, RandomUtils.CharType.ALL);
        List<String> strings2 = RandomUtils.getStrings(10000, 200, RandomUtils.CharType.ALL);

        TimeTracker.start("lcs");
        LCSString.getLCSLength(strings1, strings2);
        TimeTracker.stop("lcs");

        TimeTracker.start("lcs");
        LCSString.getLCSLengthSorting(strings1, strings2);
        TimeTracker.stop("lcs");
    }
}


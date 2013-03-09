package misc;

import java.util.Stack;

public class TowerOfHanoi
{
    public void move(int n, Tower s, Tower d, Tower b)
    {
        if (n == 1)
        {
            Integer pop = s.pop();
            d.push(pop);
            System.out.println(s.id + " -> " + d.id + " " + pop);
            return;
        }

        move(n - 1, s, b, d);
        Integer pop = s.pop();
        d.push(pop);
        System.out.println(s.id + " -> " + d.id + " " + pop);
        move(n - 1, b, d, s);
    }

    public static class Tower
    {
        Stack<Integer> disks;
        int id;

        public Tower(int id)
        {
            this.id = id;
            disks = new Stack<Integer>();
        }

        public void push(Integer integer)
        {
            disks.push(integer);
        }

        public Integer pop()
        {
            return disks.pop();
        }
    }
}


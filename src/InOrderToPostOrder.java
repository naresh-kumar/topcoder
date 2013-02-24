import java.util.Stack;

public class InOrderToPostOrder
{
    public static String convert(String str)
    {
        Stack<Character> stack = new Stack<Character>();
        StringBuilder sb = new StringBuilder(str.length());

        for (char c : str.toCharArray())
        {
            if (c == '+' || c == '-')
            {
                while (!stack.isEmpty() && stack.peek() != '(')
                {
                    sb.append(stack.pop());
                }

                stack.push(c);
            }
            else if (c == '*')
            {
                while (!stack.isEmpty() && stack.peek() == '*')
                {
                    sb.append(stack.pop());
                }

                stack.push(c);
            }
            else if (c == '(')
            {
                stack.push(c);
            }
            else if (c == ')')
            {
                while (!stack.isEmpty() && stack.peek() != '(')
                {
                    sb.append(stack.pop());
                }

                if (!stack.isEmpty())
                    stack.pop();
            }
            else
            {
                sb.append(c);
            }
        }

        while (!stack.isEmpty())
        {
            sb.append(stack.pop());
        }
        return sb.toString();
    }

    public static int evaluate(String expression)
    {
        Stack<Integer> stack = new Stack<Integer>();
        for (char c : expression.toCharArray())
        {
            if (c == '+')
            {
                int a = stack.pop();
                int b = stack.pop();
                stack.push(a + b);
            }
            else if (c == '-')
            {
                int a = stack.pop();
                int b = stack.pop();
                stack.push(a + b);
            }
            else if (c == '*')
            {
                int a = stack.pop();
                int b = stack.pop();
                stack.push(a * b);
            }
            else stack.push(c - '0');
        }
        return stack.pop();
    }
}

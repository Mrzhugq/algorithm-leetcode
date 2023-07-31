package stackandqueue;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
 * 请你计算该表达式。返回一个表示表达式值的整数。
 */
public class EvaluateReversePolishNotation_150 {

    public int evalRPN(String[] tokens) {
        Deque<Long> stack = new ArrayDeque<>();
        for (String token : tokens) {
            // '+'、'-'、'*' 和 '/'
            if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
                Long num1 = stack.pop();
                Long num2 = stack.pop();
                if (token.equals("+")) stack.push(num2 + num1);
                if (token.equals("-")) stack.push(num2 - num1);
                if (token.equals("*")) stack.push(num2 * num1);
                if (token.equals("/")) stack.push(num2 / num1);
            } else {
                stack.push(Long.parseLong(token));
            }
        }
        return stack.pop().intValue();
    }

}

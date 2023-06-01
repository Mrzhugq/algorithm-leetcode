package stackandqueue;

import java.util.ArrayDeque;

/**
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * <p>
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 */
public class ValidParentheses_20 {
    public boolean isValid(String s) {
        if (s.length() % 2 == 1) return false;
        ArrayDeque<Character> deque = new ArrayDeque<>();  // LinkedList也行
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                deque.push(')');
            } else if (ch == '{') {
                deque.push('}');
            } else if (ch == '[') {
                deque.push(']');
            } else if (deque.isEmpty() || ch != deque.peek()) {
                return false;
            } else { // ch == deque.peek()
                deque.pop();
            }
        }
        return deque.isEmpty();
    }
}

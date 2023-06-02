package stackandqueue;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 */
public class RemoveAllAdjacentDuplicatesInString_1047 {
    public String removeDuplicates(String s) {
        Deque<Character> deque = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            if (deque.isEmpty() || s.charAt(i) != deque.peek()) {
                deque.push(s.charAt(i));
            } else {
                deque.pop();
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!deque.isEmpty()) {
            sb.append(deque.pop());
        }
        return sb.reverse().toString();
    }
}

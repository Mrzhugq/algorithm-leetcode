package array;

/**
 * <a href="https://leetcode.cn/problems/backspace-string-compare/description/">比较含退格的字符串</a>
 */
public class BackspaceStringCompare_844 {
    // 双指针
    public boolean backspaceCompare(String s, String t) {
        int sSkipNum = 0, tSkipNum = 0; // 记录#的数量
        int i = s.length() - 1, j = t.length() - 1; // 双指针，从后往前遍历
        while (true) {
            while (i >= 0) {
                if (s.charAt(i) == '#') {
                    sSkipNum++;
                } else {
                    if (sSkipNum > 0) {
                        sSkipNum--;
                    } else {
                        break;
                    }
                }
                i--;
            }

            while (j >= 0) {
                if (t.charAt(j) == '#') {
                    tSkipNum++;
                } else {
                    if (tSkipNum > 0) {
                        tSkipNum--;
                    } else {
                        break;
                    }
                }
                j--;
            }
            if (i < 0 || j < 0) break; // 只有一个遍历完了不相等，所以出去判断一下
            if (s.charAt(i) != t.charAt(j)) return false;
            i--;
            j--;
        }
        if (i == -1 && j == -1) return true; // 两个同时遍历完相等
        return false;
    }

    // 模拟栈的方式
    public boolean backspaceCompare2(String s, String t) {
        return rebuild(s).equals(rebuild(t));
    }

    private String rebuild(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch != '#') {
                sb.append(ch);
            } else {
                if (sb.length() > 0) {
                    sb.deleteCharAt(sb.length() - 1);
                }
            }
        }
        return sb.toString();
    }
}
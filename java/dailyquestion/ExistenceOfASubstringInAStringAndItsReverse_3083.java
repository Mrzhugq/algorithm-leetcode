package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/">字符串及其反转中是否存在同一子字符串</a>
 *
 * @author sutong
 * @date 2024-12-26 13:55
 */
public class ExistenceOfASubstringInAStringAndItsReverse_3083 {

    // O(N^2)
    public boolean isSubstringPresent(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            StringBuilder sb = new StringBuilder(s.substring(i, i + 2)).reverse();
            if (s.contains(sb.toString())) {
                return true;
            }
        }
        return false;
    }

    // O(N)
    public boolean isSubstringPresent2(String s) {
        boolean[][] visited = new boolean[26][26];
        for (int i = 0; i < s.length() - 1; i++) {
            int x = s.charAt(i) - 'a';
            int y = s.charAt(i + 1) - 'a';
            visited[x][y] = true;
            if (visited[y][x]) {
                return true;
            }
        }
        return false;
    }
}

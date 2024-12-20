package dailyquestion;

import java.util.Arrays;

/**
 * <a href="https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/description/">同位字符串连接的最小长度</a>
 *
 * @author sutong
 * @date 2024-12-20 15:17
 */
public class MinimumLengthOfAnagramConcatenation_3138 {

    // 输入：s = "abba"
    // 输出：2
    public int minAnagramLength(String s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (n % i != 0) {
                continue;
            }
            if (check(s, i)) {
                return i;
            }
        }
        return n;
    }

    private boolean check(String s, int m) {
        int[] count1 = new int[26];
        for (int j = 0; j < s.length(); j += m) {
            int[] count2 = new int[26];
            for (int k = j; k < j + m; k++) {
                count2[s.charAt(k) - 'a']++;
            }
            if (j > 0 && !Arrays.equals(count1, count2)) {
                return false;
            }
            count1 = count2;
        }
        return true;
    }
}

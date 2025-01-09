package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/description/">统计重新排列后包含另一个字符串的子字符串数目 I</a>
 *
 * @author sutong
 * @date 2025-01-09 15:47
 */
public class CountSubstringsThatCanBeRearrangedToContainAStringI_3279 {

    public long validSubstringCount(String word1, String word2) {
        long res = 0;
        int[] count1 = new int[26], count2 = new int[26];
        for (int i = 0; i < word2.length(); i++) {
            count2[word2.charAt(i) - 'a']++;
        }

        int left = 0, right = 0;
        while (right < word1.length()) {
            count1[word1.charAt(right) - 'a']++;

            // 窗口的长度小于 word2 的长度
            if (right < word2.length() - 1) {
                right++;
                continue;
            }

            // 当窗口的字符频率满足条件时，左边界向右移动
            while (match(count1, count2)) {
                count1[word1.charAt(left) - 'a']--;
                left++;
            }

            // 遍历时如果right前面存在字符串满足条件，那么right肯定也至少有left个字符串是满足条件的
            res += left;
            right++;
        }
        return res;
    }

    private boolean match(int[] c1, int[] c2) {
        for (int i = 0; i < c1.length; i++) {
            if (c1[i] < c2[i]) {
                return false;
            }
        }
        return true;
    }

}

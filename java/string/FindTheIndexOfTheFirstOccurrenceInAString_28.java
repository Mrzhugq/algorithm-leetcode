package string;

/**
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
 * 如果 needle 不是 haystack 的一部分，则返回  -1 。
 */
public class FindTheIndexOfTheFirstOccurrenceInAString_28 {
    // KMP算法
    public int strStr(String haystack, String needle) {
        // 获取子串的前缀表
        int[] next = new int[needle.length()];
        getNext(next, needle);
        // 匹配
        int j = 0;
        for (int i = 0; i < haystack.length(); i++) {
            while (j > 0 && haystack.charAt(i) != needle.charAt(j)) {
                j = next[j - 1];
            }
            if (haystack.charAt(i) == needle.charAt(j)) {
                j++;
            }
            if (j >= needle.length()) {
                return i - j + 1;
            }
        }
        return -1;
    }

    // 构建前缀表 (也是使用了KMP思想)
    public void getNext(int[] next, String subStr) {
        int j = 0; // j代表前缀末尾位置，还代表i及i之前的最长相同前后缀长度
        next[0] = 0;
        for (int i = 1; i < subStr.length(); i++) { // i代表后缀末尾位置
            while (j > 0 && subStr.charAt(i) != subStr.charAt(j)) {
                j = next[j - 1];
            }
            if (subStr.charAt(i) == subStr.charAt(j)) {
                j++;
            }
            next[i] = j;
        }
    }

    // 暴力
    public int strStr2(String haystack, String needle) {
        int i = 0;
        int j = 0;
        while (i < haystack.length() && j < needle.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        return j >= needle.length() ? i - j : -1;
    }

    public static void main(String[] args) {
        new FindTheIndexOfTheFirstOccurrenceInAString_28().strStr("aabaabaaf", "aabaaf");
    }
}

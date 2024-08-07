package array;

import java.util.HashMap;
import java.util.Map;

/**
 * <a href="https://leetcode.cn/problems/minimum-window-substring/description/">最小覆盖子串</a>
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 */
public class MinimumWindowSubstring_76 {
    public String minWindow(String s, String t) {
        String res = "";
        int cnt = 0;
        int i = 0; // 滑动窗口左边界
        Map<Character, Integer> hs = new HashMap<>();
        Map<Character, Integer> ht = new HashMap<>();

        for (int k = 0; k < t.length(); k++) {
            ht.put(t.charAt(k), ht.getOrDefault(t.charAt(k), 0) + 1);
        }
        for (int j = 0; j < s.length(); j++) {  // 滑动窗口右边界
            hs.put(s.charAt(j), hs.getOrDefault(s.charAt(j), 0) + 1);
            if (hs.get(s.charAt(j)) <= ht.getOrDefault(s.charAt(j), 0)) {
                cnt++;
            }
            while (i < s.length() && hs.getOrDefault(s.charAt(i), 0) > ht.getOrDefault(s.charAt(i), 0)) {
                hs.put(s.charAt(i), hs.get(s.charAt(i)) - 1);
                i++;
            }
            if (cnt == t.length()) {
                if (res.equals("") || j - i + 1 < res.length()) {
                    res = s.substring(i, j + 1);
                    System.out.println(res);
                }
            }
        }
        return res;
    }

    // s = "ADOBEC ODEBANC", t = "ABC"
    public String minWindow2(String s, String t) {
        int left = 0, cnt = 0;
        String res = "";
        int[] hs = new int[128];
        int[] ht = new int[128];

        // 初始化hs
        for (int i = 0; i < t.length(); i++) {
            ht[t.charAt(i)]++;
        }

        // 滑动窗口
        for (int right = 0; right < s.length(); right++) {
            // 扩大右边界
            hs[s.charAt(right)]++;
            if (hs[s.charAt(right)] <= ht[s.charAt(right)]) {
                cnt++;
            }

            // 缩小左边界
            while (left < s.length() && hs[s.charAt(left)] > ht[s.charAt(left)]) {
                hs[s.charAt(left)]--;
                left++;
            }

            // 符合要求，保存答案
            if (cnt == t.length()) {
                if (res.isEmpty() || right - left + 1 < res.length()) {
                    res = s.substring(left, right + 1);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(new MinimumWindowSubstring_76().minWindow("ADOBECODEBANC", "ABC"));
    }
}
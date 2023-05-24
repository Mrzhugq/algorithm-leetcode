package array;

import java.util.HashMap;
import java.util.Map;

/**
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

    public static void main(String[] args) {
        System.out.println(new MinimumWindowSubstring_76().minWindow("ADOBECODEBANC", "ABC"));
    }
}
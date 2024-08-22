package hash;

import java.util.ArrayList;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/">找到字符串中所有字母异位词</a>
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 */
public class FindAllAnagramsInAString_438 {

    //  s = "c b a e b a b a c d", p = "abc"
    //       l     r
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        if (s.length() < p.length()) return res;
        int[] sHash = new int[26];
        int[] pHash = new int[26];
        for (int i = 0; i < p.length(); i++) {
            pHash[p.charAt(i) - 'a']++;
            sHash[s.charAt(i) - 'a']++;
        }
        if (isEqual(sHash, pHash)) res.add(0);
        // 固定滑动窗口
        int left = 0, right = p.length();
        while (right < s.length()) {
            sHash[s.charAt(left++) - 'a']--;
            sHash[s.charAt(right++) - 'a']++;
            if (isEqual(sHash, pHash)) res.add(left);
        }
        return res;
    }

    private boolean isEqual(int[] h1, int[] h2) {
        for (int i = 0; i < 26; i++) {
            if (h1[i] != h2[i]) return false;
        }
        return true;
    }

}

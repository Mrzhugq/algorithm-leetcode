package hash;

import java.util.HashMap;

/**
 * <a href="https://leetcode.cn/problems/ransom-note/description/">赎金信</a>
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 如果可以，返回 true ；否则返回 false 。
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 */
public class RansomNote_383 {
    // array
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] count = new int[26];
        for (char ch : magazine.toCharArray()) {
            count[ch - 'a']++;
        }
        for (char ch : ransomNote.toCharArray()) {
            if (count[ch - 'a'] > 0) {
                count[ch - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }

    // map
    public boolean canConstruct2(String ransomNote, String magazine) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < magazine.length(); i++) {
            map.put(magazine.charAt(i), map.getOrDefault(magazine.charAt(i), 0) + 1);
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            if (map.getOrDefault(ransomNote.charAt(i), 0) > 0) {
                map.put(ransomNote.charAt(i), map.get(ransomNote.charAt(i)) - 1);
            } else {
                return false;
            }
        }
        return true;
    }
}

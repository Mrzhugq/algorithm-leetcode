package hash;

import java.util.*;
import java.util.stream.Collectors;

/**
 * <a href="https://leetcode.cn/problems/group-anagrams/description/">字母异位词分组</a>
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 */
public class GroupAnagrams_49 {
    // 哈希
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String str : strs) {
            // 计数
            int[] count = new int[26];
            for (int i = 0; i < str.length(); i++) {
                count[str.charAt(i) - 'a']++;
            }
            // 将 [b,a,a,a,b,c] 编码成 a3b2c1，使用编码后的字符串作为 Map 的 Key 进行聚合
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                if (count[i] != 0) {
                    sb.append((char) i + 'a');
                    sb.append(count[i]);
                }
            }
            String key = sb.toString();
            List<String> list = map.getOrDefault(key, new ArrayList<>());
            list.add(str);
            map.put(key, list);
        }
        return new ArrayList<List<String>>(map.values());
    }

    // 排序
    public List<List<String>> groupAnagrams2(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String str : strs) {
            char[] array = str.toCharArray();
            Arrays.sort(array);
            String key = new String(array);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(str);

            // List<String> list = map.getOrDefault(key, new ArrayList<>());
            // list.add(str);
            // map.put(key, list);
        }
        return new ArrayList<List<String>>(map.values());
    }

    // stream 流
    public List<List<String>> groupAnagrams3(String[] strs) {
        Collection<List<String>> values = Arrays.stream(strs).collect(Collectors.groupingBy(s -> Arrays.toString(s.codePoints().sorted().toArray()))).values();
        return new ArrayList<>(values);
    }
}

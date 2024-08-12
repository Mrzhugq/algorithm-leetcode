package dailyquestion;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * <a href="https://leetcode.cn/problems/implement-magic-dictionary/description/">实现一个魔法字典</a>
 *
 * @author sutong
 * @date 2024-08-12 9:29
 */
public class ImplementMagicDictionary_676 {

    private String[] words;

    public ImplementMagicDictionary_676() {

    }

    public void buildDict(String[] dictionary) {
        words = dictionary;
    }

    public boolean search(String searchWord) {
        for (String word : words) {
            if (word.length() != searchWord.length()) {
                continue;
            }

            int diff = 0;
            for (int i = 0; i < word.length(); i++) {
                if (word.charAt(i) != searchWord.charAt(i)) {
                    diff++;
                }
                if (diff > 1) {
                    break;
                }
            }
            if (diff == 1) {
                return true;
            }
        }
        return false;
    }


    // -------------------------------------------------------------------------------------------------
    // 效率没有上面的高

    private Set<String> set;

    public void buildDict2(String[] dictionary) {
        set = new HashSet<>();
        set.addAll(Arrays.asList(dictionary));
    }

    public boolean search2(String searchWord) {
        char[] searchWordChars = searchWord.toCharArray();
        for (int i = 0; i < searchWordChars.length; i++) {
            char ch = searchWordChars[i];
            // dictionary[i]、searchWord 仅由小写英文字母组成
            for (int j = 0; j < 26; j++) {
                char temp = (char) (j + 'a');
                if (temp == ch) {
                    continue;
                }
                searchWordChars[i] = temp;
                if (set.contains(String.valueOf(searchWordChars))) {
                    return true;
                }
            }
            searchWordChars[i] = ch;
        }
        return false;
    }
}

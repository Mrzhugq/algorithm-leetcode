package recall;

import java.util.ArrayList;
import java.util.List;

/**
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 */
public class LetterCombinationsOfAPhoneNumber_17 {
    List<String> res = new ArrayList<>();
    StringBuilder path = new StringBuilder();
    String[] letterMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return res;
        }
        backtracking(digits, 0);
        return res;
    }

    /**
     * 回溯算法
     * @param digits 输入的数字
     * @param index  记录遍历第几个数字了
     */
    private void backtracking(String digits, int index) {
        if (index == digits.length()) {
            res.add(path.toString());
            return;
        }

        String letter = letterMap[digits.charAt(index) - '0'];  // letter表示当前num对应的字符串
        for (int i = 0; i < letter.length(); i++) {
            path.append(letter.charAt(i));
            backtracking(digits, index + 1);
            path.deleteCharAt(path.length() - 1);
        }
    }
}

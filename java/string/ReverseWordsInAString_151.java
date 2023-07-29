package string;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 */
public class ReverseWordsInAString_151 {
    // 不使用库函数
    public String reverseWords(String s) {
        int index = 0;
        char[] res = s.toCharArray();
        // 移除多余空格
        for (int i = 0; i < res.length; i++) {
            if (res[i] != ' ') {
                if (i > 0 && res[i - 1] == ' ' && index != 0) {
                    res[index++] = ' ';
                }
                res[index++] = res[i];
            }
        }
        // 将整个字符串反转
        reverseString(res, 0, index - 1);
        // 将每个单词反转
        int left = 0, right = 0;
        while (right <= index) {
            if (right == index || res[right] == ' ') {
                reverseString(res, left, right - 1);
                right++;
                left = right;
            } else {
                right++;
            }
        }
        return new String(res, 0, index);
    }

    public void reverseString(char[] s, int left, int right) {
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

    // 使用库函数
    public String reverseWords2(String s) {
        List<String> words = Arrays.asList(s.trim().split(" +"));
        Collections.reverse(words);
        return String.join(" ", words);
    }

    public static void main(String[] args) {
        System.out.println(new ReverseWordsInAString_151().reverseWords("  the  sky      is     blue  "));
    }
}
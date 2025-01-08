package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/largest-3-same-digit-number-in-string/description/">字符串中最大的 3 位相同数字</a>
 *
 * @author sutong
 * @date 2025-01-08 10:40
 */
public class Largest3SameDigitNumberInString_2264 {

    public String largestGoodInteger(String num) {
        String res = "";
        for (int i = 0; i < num.length() - 2; i++) {
            if (num.charAt(i) == num.charAt(i + 1) && num.charAt(i + 1) == num.charAt(i + 2)) {
                String cur = num.substring(i, i + 3);
                if (cur.compareTo(res) > 0) {
                    res = cur;
                }
            }
        }
        return res;
    }

}

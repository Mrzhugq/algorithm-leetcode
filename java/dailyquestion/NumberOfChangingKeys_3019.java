package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/number-of-changing-keys/description/">按键变更的次数</a>
 *
 * @author sutong
 * @date 2025-01-07 14:19
 */
public class NumberOfChangingKeys_3019 {

    public int countKeyChanges(String s) {
        int res = 0;
        for (int i = 1; i < s.length(); i++) {
            if (Character.toUpperCase(s.charAt(i - 1)) != Character.toUpperCase(s.charAt(i))) {
                res++;
            }
            // if (s.charAt(i - 1) != s.charAt(i) && Math.abs(s.charAt(i - 1) - s.charAt(i)) != 32) {
            //     res++;
            // }
        }
        return res;
    }

}

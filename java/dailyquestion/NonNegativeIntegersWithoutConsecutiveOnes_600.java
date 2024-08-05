package dailyquestion;

/**
 * 给定一个正整数 n ，请你统计在 [0, n] 范围的非负整数中，有多少个整数的二进制表示中不存在 连续的 1 。
 * <a href="https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/">不含连续1的非负整数</a>
 *
 * @author sutong
 * @date 2024-08-05 10:53
 */
public class NonNegativeIntegersWithoutConsecutiveOnes_600 {
    public int findIntegers(int n) {
        int[] dp = new int[31];
        dp[0] = dp[1] = 1;
        for (int i = 2; i < 31; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int pre = 0, res = 0;
        for (int i = 29; i >= 0; --i) {
            int val = 1 << i;
            if ((n & val) != 0) {
                res += dp[i + 1];
                if (pre == 1) {
                    break;
                }
                pre = 1;
            } else {
                pre = 0;
            }

            if (i == 0) {
                ++res;
            }
        }
        return res;
    }

    // 暴力 超时
    public int findIntegers2(int n) {
        int res = 0;
        for (int i = 0; i <= n; i++) {
            String binBase = getBinBase(i);
            System.out.println(i + "    " + binBase);
            if (check(binBase)) {
                res++;
            }
        }
        return res;
    }

    private String getBinBase(int n) {
        if (n == 0) return "0";
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            sb.append(n % 2);
            n /= 2;
        }
        return sb.reverse().toString();
    }

    private boolean check(String str) {
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i - 1) == '1' && str.charAt(i - 1) == str.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}

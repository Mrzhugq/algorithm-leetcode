package dailyquestion;

import java.util.Arrays;

/**
 * <a href="https://leetcode.cn/problems/special-array-ii/description/">特殊数组 II</a>
 *
 * @author sutong
 * @date 2024-08-14 9:19
 */
public class SpecialArrayII_3152 {

    // nums = [3,4,1,2,6], queries = [[0,4]]
    // dp =   [1,2,3,4,1]
    // 动态规划 O(N)
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int[] dp = new int[nums.length];
        boolean[] res = new boolean[queries.length];
        Arrays.fill(dp, 1);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                dp[i] = dp[i - 1] + 1;
            }
        }

        // 数组的任意连续子数组也一定也是特殊数组，因此我们只需要检测以 y 为结尾的最长特殊子数组是否可以覆盖区间 [x,y]
        // 即判断 dp[y] 是否大于等于区间 [x,y] 的长度即可
        for (int i = 0; i < queries.length; i++) {
            int x = queries[i][0], y = queries[i][1];
            res[i] = dp[y] >= y - x + 1;
        }
        return res;
    }

    // 暴力超时 O(N^2)
    public boolean[] isArraySpecial2(int[] nums, int[][] queries) {
        boolean[] res = new boolean[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            boolean flag = true;
            for (int j = query[0]; j < query[1]; j++) {
                if (nums[j] % 2 == nums[j + 1] % 2) {
                    res[i] = false;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res[i] = true;
            }
        }
        return res;
    }

}
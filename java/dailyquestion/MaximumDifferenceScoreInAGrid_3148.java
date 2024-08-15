package dailyquestion;

import java.util.Arrays;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/maximum-difference-score-in-a-grid/description/">矩阵中的最大得分</a>
 *
 * @author sutong
 * @date 2024-08-15 9:22
 */
public class MaximumDifferenceScoreInAGrid_3148 {

    /*
      [[9,5,7,3],
       [8,9,6,1],
       [6,7,14,3],
       [2,5,3,1]]
     */
    // 求出以每个点为终点的最大的分
    public int maxScore(List<List<Integer>> grid) {
        int n = grid.size(), m = grid.get(0).size();
        int[][] dp = new int[n][m];
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MIN_VALUE / 2);
        }

        // 第一层只能从左边一整个来跟从左边一个来取最值
        for (int j = 1; j < m; j++) {
            int diff = grid.get(0).get(j) - grid.get(0).get(j - 1);
            dp[0][j] = Math.max(dp[0][j - 1] + diff, diff);
            res = Math.max(res, dp[0][j]);
        }

        // 第一列只能从上边一整个来跟从上面一个来取最值
        for (int i = 1; i < n; i++) {
            int diff = grid.get(i).get(0) - grid.get(i - 1).get(0);
            dp[i][0] = Math.max(dp[i - 1][0] + diff, diff);
            res = Math.max(res, dp[i][0]);
        }


        // 四种情况取最大值  1、左边一整个来  2、由左边一个来 3、上边一整个来 4、由上边一个来
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int t1 = Math.max(dp[i - 1][j] + grid.get(i).get(j) - grid.get(i - 1).get(j), dp[i][j - 1] + grid.get(i).get(j) - grid.get(i).get(j - 1));
                int t2 = Math.max(grid.get(i).get(j) - grid.get(i - 1).get(j), grid.get(i).get(j) - grid.get(i).get(j - 1));
                dp[i][j] = Math.max(t1, t2);
                res = Math.max(res, dp[i][j]);
            }
        }
        return res;
    }

}

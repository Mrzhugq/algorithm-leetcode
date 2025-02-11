package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/unique-paths-ii/description/">不同路径 II</a>
 *
 * @author sutong
 * @date 2025-02-08 15:36
 */
public class UniquePathsII_63 {

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        // dp[i][j]: 从(0, 0)到(i, j)有dp[i][j]条不同的路径
        int n = obstacleGrid.length, m = obstacleGrid[0].length;
        int[][] db = new int[n][m];

        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            db[i][0] = 1;
        }
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            db[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    db[i][j] = 0;
                    continue;
                }
                db[i][j] = db[i - 1][j] + db[i][j - 1];
            }
        }
        return db[n - 1][m - 1];
    }

    public int uniquePathsWithObstacles2(int[][] obstacleGrid) {
        int n = obstacleGrid.length, m = obstacleGrid[0].length;
        int[] db = new int[m];

        db[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    db[j] = 0;
                    continue;
                }
                if (j > 0 && obstacleGrid[i][j - 1] == 0) {
                    db[j] += db[j - 1];
                }
            }
        }
        return db[m - 1];
    }
}

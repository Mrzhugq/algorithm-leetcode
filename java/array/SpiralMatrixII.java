package array;

/**
 * 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 */
public class SpiralMatrixII {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int startX = 0, startY = 0;   // 每循环一个圈的起始位置
        int loop = n / 2;             // 每个圈循环几次
        int mid = n / 2;              // 矩阵中间的位置
        int offset = 1;               // 控制每一圈里每一条边遍历的长度
        int count = 1;                // 用来给矩阵空赋值
        int i, j;

        while (loop-- != 0) {
            i = startX;
            j = startY;
            // 上行 从左到右(左闭右开)
            for (j = startY; j < n - offset; j++) {
                res[i][j] = count++;
            }
            // 右行 从上到下(左闭右开)
            for (i = startX; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 下行 从右到左(左闭右开)
            for (; j > startY; j--) {
                res[i][j] = count++;
            }
            // 左行 从下到上(左闭右开)
            for (; i > startX; i--) {
                res[i][j] = count++;
            }
            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startX++;
            startY++;
            offset += 1;
        }
        if (n % 2 == 1) {
            res[mid][mid] = count;
        }
        return res;
    }
}
package array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/spiral-matrix/description/">螺旋矩阵</a>
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 */
public class SpiralMatrix_54 {
    /*
       [[1,2,3,4],
        [5,6,7,8],
        [9,10,11,12]]
     */
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        int loop = 1, offset = 1;
        int startX = 0, startY = 0;
        int m = matrix.length, n = matrix[0].length; // m行n列
        while (loop <= Math.min(m / 2, n / 2)) {
            int i = startX, j = startY;
            for (j = startY; j < n - offset; j++) {
                result.add(matrix[i][j]);
            }
            for (i = startX; i < m - offset; i++) {
                result.add(matrix[i][j]);
            }
            for (; j > startY; j--) {
                result.add(matrix[i][j]);
            }
            for (; i > startX; i--) {
                result.add(matrix[i][j]);
            }
            startX++;
            startY++;
            loop++;
            offset++;
        }
        if (m % 2 == 1 && n % 2 == 1 && m == n) {
            result.add(matrix[startX][startY]);
        }
        if (n % 2 == 1 && m > n) {
            for (int k = 0; k <= m - n; k++) {
                result.add(matrix[startX + k][startY]);
            }
        }
        if (m % 2 == 1 && n > m) {
            for (int k = 0; k <= n - m; k++) {
                result.add(matrix[startX][startY + k]);
            }
        }
        return result;
    }

    public List<Integer> spiralOrder2(int[][] matrix) {
        ArrayList<Integer> res = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return res;
        int left = 0, right = matrix[0].length - 1;
        int top = 0, bottom = matrix.length;
        int numEle = matrix.length * matrix[0].length;

        while (numEle >= 1) {
            // 上行
            for (int i = left; i <= right; i++) {
                res.add(matrix[top][i]);
                numEle--;
            }
            top++;

            // 右行
            for (int i = top; i <= bottom; i++) {
                res.add(matrix[i][right]);
                numEle--;
            }
            right--;

            // 下行
            for (int i = right; i >= left; i--) {
                res.add(matrix[bottom][i]);
                numEle--;
            }
            bottom--;

            // 左行
            for (int i = bottom; i >= top; i--) {
                res.add(matrix[i][left]);
                numEle--;
            }
            left++;
        }
        return res;
    }


    /**
     * <a href="https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/">LCR 146. 螺旋遍历二维数组</a>
     */
    public int[] spiralArray(int[][] array) {
        if (array == null || array.length == 0 || array[0].length == 0) {
            return new int[0];
        }
        int loop = 1, offset = 1, count = 0;
        int startX = 0, startY = 0;
        int m = array.length, n = array[0].length;
        int[] res = new int[m * n];

        while (loop <= Math.min(m / 2, n / 2)) {
            int i = startX, j = startY;
            for (j = startY; j < n - offset; j++) {
                res[count++] = array[i][j];
            }
            for (i = startX; i < m - offset; i++) {
                res[count++] = array[i][j];
            }
            for (; j > startY; j--) {
                res[count++] = array[i][j];
            }
            for (; i > startX; i--) {
                res[count++] = array[i][j];
            }
            loop++;
            offset++;
            startX++;
            startY++;
        }

        if (n == m && n % 2 == 1) {
            res[count++] = array[startX][startY];
        }
        // m = 3    n = 4
        if (m > n && n % 2 == 1) {
            for (int k = 0; k <= m - n; k++) {
                res[count++] = array[startX + k][startY];
            }
        }
        if (n > m && m % 2 == 1) {
            for (int k = 0; k <= n - m; k++) {
                res[count++] = array[startX][startY + k];
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[][] ints = new int[1][2];
        ints[0] = new int[]{2, 3};
        System.out.println(Arrays.toString(new SpiralMatrix_54().spiralArray(ints)));
        // System.out.println(new SpiralMatrix_54().spiralOrder(ints));
    }
}

package array;

import java.util.ArrayList;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/spiral-matrix/description/">螺旋矩阵</a>
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 */
public class SpiralMatrix_54 {
    public List<Integer> spiralOrder(int[][] matrix) {
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
}

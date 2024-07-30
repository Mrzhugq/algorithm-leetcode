package dailyquestion;

import java.util.ArrayList;
import java.util.List;

/**
 * 给你一个下标从 0 开始的二维数组 variables ，其中 variables[i] = [ai, bi, ci, mi]，以及一个整数 target 。
 * 如果满足以下公式，则下标 i 是 好下标：
 * 0 <= i < variables.length
 * ((ai^bi % 10)^ci) % mi == target
 * 返回一个由 好下标 组成的数组，顺序不限 。
 *
 * @author sutong
 * @date 2024-07-30 9:45
 */
public class DoubleModularExponentiation_2961 {

    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> res = new ArrayList<>();
        if (variables.length == 0) return res;
        for (int i = 0; i < variables.length; i++) {
            int[] variable = variables[i];
            double temp = powMod(powMod(variable[0], variable[1], 10), variable[2], variable[3]);
            if (temp == target) {
                res.add(i);
            }
        }
        return res;
    }

    /**
     * 快速幂
     *
     * @param x
     * @param y
     * @param mod
     * @return
     */
    private int powMod(int x, int y, int mod) {
        int res = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            y /= 2;
        }
        return res;
    }

}

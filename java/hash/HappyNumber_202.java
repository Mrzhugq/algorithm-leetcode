package hash;

import java.util.HashSet;

/**
 * <a href="https://leetcode.cn/problems/happy-number/description/">快乐数</a>
 * 编写一个算法来判断一个数 n 是不是快乐数。
 * 「快乐数」定义为：
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为1，那么这个数就是快乐数。
 */
public class HappyNumber_202 {

    public boolean isHappy(int n) {
        //  无限循环，那么也就是说求和的过程中，sum会重复出现
        HashSet<Integer> set = new HashSet<>();
        while (n != 1) {
            int sum = getSum(n);
            if (set.contains(sum)) {
                return false;
            } else {
                set.add(sum);
            }
            n = sum;
        }
        return true;
    }

    private int getSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
        return sum;
    }

}

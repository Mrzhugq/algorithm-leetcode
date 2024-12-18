package string;

/**
 * <a href="https://leetcode.cn/problems/product-of-array-except-self/description/">除自身以外数组的乘积</a>
 *
 * @author sutong
 * @date 2024-12-18 13:51
 */
public class ProductOfArrayExceptSelf_238 {

    /*
        输入: nums = [1,2,3,4]
                    [1,1,2,6]
                    [24,12,4,1]
        输出: [24,12,8,6]
     */
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] res = new int[n], leftMulti = new int[n], rightMulti = new int[n];

        // leftMulti[i] 为 nums[i] 左边所有元素的乘机
        leftMulti[0] = 1;
        for (int i = 1; i < n; i++) {
            leftMulti[i] = leftMulti[i - 1] * nums[i - 1];
        }
        // rightMulti[i] 为 nums[i] 右边所有元素的乘机
        rightMulti[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            rightMulti[i] = rightMulti[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            res[i] = leftMulti[i] * rightMulti[i];
        }
        return res;
    }

    public int[] productExceptSelf2(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];

        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int rightMulti = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = rightMulti * res[i];
            rightMulti *= nums[i];
        }
        return res;
    }
}

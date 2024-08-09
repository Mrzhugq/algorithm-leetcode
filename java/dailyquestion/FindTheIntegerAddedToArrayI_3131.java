package dailyquestion;

import java.util.Arrays;

/**
 * <a href="https://leetcode.cn/problems/find-the-integer-added-to-array-i/description/">找出与数组相加的整数 I</a>
 *
 * @author sutong
 * @date 2024-08-08 16:29
 */
public class FindTheIntegerAddedToArrayI_3131 {
    // nums1 = [2,6,4], nums2 = [9,7,5]
    //           12                21
    public int addedInteger(int[] nums1, int[] nums2) {
        int sum1 = Arrays.stream(nums1).sum();
        int sum2 = Arrays.stream(nums2).sum();
        return (sum2 - sum1) / nums1.length;
    }

    // 把两个数组的最小值找出来相减就行
    public int addedInteger2(int[] nums1, int[] nums2) {
        return Arrays.stream(nums2).min().getAsInt() - Arrays.stream(nums1).min().getAsInt();
    }
}

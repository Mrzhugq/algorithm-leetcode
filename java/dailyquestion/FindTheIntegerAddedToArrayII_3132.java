package dailyquestion;

import java.util.Arrays;

/**
 * <a href="https://leetcode.cn/problems/find-the-integer-added-to-array-ii/description/">找出与数组相加的整数 II</a>
 *
 * @author sutong
 * @date 2024-08-09 11:01
 */
public class FindTheIntegerAddedToArrayII_3132 {

    /*
        nums1 = [3,5,5,3], nums2 = [7,7]
        nums1 = [3,3,5,5], nums2 = [7,7]

        nums1 =  [4,20,16,12,8], nums2 = [14,18,10]
        nums1 =  [4,8,12,16,20], nums2 = [10,14,18]
     */
    // 排序后，nums1的前3个数至少有一个是最终要保留的
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int m = nums1.length;
        int n = nums2.length;

        for (int i = 2; i >= 0; i--) {
            int left = i + 1, right = 1;
            while (left < m && right < n) {
                if (nums1[left] - nums2[right] == nums1[i] - nums2[0]) {
                    right++;
                }
                left++;
            }
            if (right == n) {
                return nums2[0] - nums1[i];
            }
        }
        return 0;
    }
}

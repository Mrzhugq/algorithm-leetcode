package dailyquestion;

/**
 * <a href="https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/description/">或值至少 K 的最短子数组 II</a>
 *
 * @author sutong
 * @date 2025-01-16 15:04
 */
public class ShortestSubarrayWithOrAtLeastKII_3097 {

    // O(nlogU)
    public int minimumSubarrayLength(int[] nums, int k) {
        // 由于给定数组 nums 中的元素大小不超过 10^9，因此最多需要考虑二进制表示的前 30 位
        int[] bits = new int[30];
        int res = Integer.MAX_VALUE, left = 0, right = 0;
        while (right < nums.length) {
            for (int i = 0; i < 30; i++) {
                bits[i] += (nums[right] >> i) & 1;
            }
            while (left <= right && calc(bits) >= k) {
                res = Math.min(res, right - left + 1);
                for (int i = 0; i < 30; i++) {
                    bits[i] -= (nums[right] >> i) & 1;
                }
                left++;
            }
            right++;
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }

    //   00001
    //   00010
    //   10010
    // = 10011
    private int calc(int[] bits) {
        int value = 0;
        for (int i = 0; i < bits.length; i++) {
            if (bits[i] > 0) {
                value |= 1 << i;
            }
        }
        return value;
    }

    // public int minimumSubarrayLength(int[] nums, int k) {
    //     int n = nums.length;
    //     int[] bits = new int[30];
    //     int res = Integer.MAX_VALUE;
    //     for (int left = 0, right = 0; right < n; right++) {
    //         for (int i = 0; i < 30; i++) {
    //             bits[i] += (nums[right] >> i) & 1;
    //         }
    //         while (left <= right && calc(bits) >= k) {
    //             res = Math.min(res, right - left + 1);
    //             for (int i = 0; i < 30; i++) {
    //                 bits[i] -= (nums[left] >> i) & 1;
    //             }
    //             left++;
    //         }
    //     }
    //
    //     return res == Integer.MAX_VALUE ? -1 : res;
    // }
    //
    // private int calc(int[] bits) {
    //     int ans = 0;
    //     for (int i = 0; i < bits.length; i++) {
    //         if (bits[i] > 0) {
    //             ans |= 1 << i;
    //         }
    //     }
    //     return ans;
    // }

}

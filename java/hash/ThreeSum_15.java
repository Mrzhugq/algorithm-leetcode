package hash;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 * 你返回所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 */
public class ThreeSum_15 {
    // 不适合哈希，适合双指针
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                return res;
            }
            // 去重，当起始的值等于前一个元素，那么得到的结果将会和前一次相同
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int left = i + 1;
            int right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    res.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    //去重，因为 i 不变，当此时 right取的数的值与前一个数相同，所以不用在计算，直接跳
                    while (left < right && nums[right - 1] == nums[right]) {
                        right--;
                    }
                    //去重，因为 i 不变，当此时 left取的数的值与后一个数相同，所以不用在计算，直接跳
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    right--;
                    left++;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        new ThreeSum_15().threeSum(new int[]{-1, 0, 1, 2, -1, -4});
    }
}

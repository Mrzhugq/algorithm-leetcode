package hash;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 你可以按 任意顺序 返回答案 。
 */
public class FourSum_18 {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int k = 0; k < nums.length; k++) {
            // 剪枝
            // nums[i] >= 0代表后面都是正数了，并且nums[i]以及大于target了。后面不可能再求和等于target
            if (nums[k] >= 0 && nums[k] > target) {
                break;
            }
            // 去重
            if (k > 0 && nums[k - 1] == nums[k]) {
                continue;
            }
            for (int i = k + 1; i < nums.length; i++) {
                // 剪枝
                if (nums[k] + nums[i] >= 0 && nums[k] + nums[i] > target) {
                    break;
                }
                // 去重
                if (i > k + 1 && nums[i - 1] == nums[i]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.length - 1;
                while (left < right) {
                    long sum = nums[k] + nums[i] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        res.add(Arrays.asList(nums[k], nums[i], nums[left], nums[right]));
                        // 去重
                        while (left < right && nums[right - 1] == nums[right]) {
                            right--;
                        }
                        // 去重
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
}

package recall;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * <a href="https://leetcode.cn/problems/permutations-ii/description/">全排列 II</a>
 * <p>
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 */
public class PermutationsII_47 {
    List<List<Integer>> res = new ArrayList<>();
    LinkedList<Integer> path = new LinkedList<>();

    public List<List<Integer>> permuteUnique(int[] nums) {
        boolean[] used = new boolean[nums.length];
        Arrays.sort(nums); // 去重一定要对元素进行排序，这样我们才方便通过相邻的节点来判断是否重复使用了
        backtracking(nums, used);
        return res;
    }

    private void backtracking(int[] nums, boolean[] used) {
        if (path.size() == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            // 如果同一树层nums[i - 1]未被使用过则，直接跳过
            // !used[i - 1]、used[i - 1] 都行，前者能够提前剪枝
            if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i]) {
                continue;
            }
            // path里已经收录的元素，直接跳过
            if (used[i]) {
                continue;
            }
            path.add(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.removeLast();
            used[i] = false;
        }
    }
}

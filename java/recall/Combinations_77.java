package recall;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 */
public class Combinations_77 {
    List<List<Integer>> res = new ArrayList<>(); // 存放符合条件结果的集合
    LinkedList<Integer> path = new LinkedList<>(); // 用来存放符合条件结果

    public List<List<Integer>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }

    void backtracking(int n, int k, int startIndex) {
        // 终止条件
        if (path.size() == k) {
            res.add(new ArrayList<>(path));
            return;
        }

        for (int i = startIndex; i <= n; i++) {
            path.add(i);
            backtracking(n, k, i + 1);
            path.removeLast(); // 回溯，撤销处理的节点
        }
    }

    // 剪枝优化
    void backtrackingPruning(int n, int k, int startIndex) {
        if (path.size() == k) {
            res.add(new ArrayList<>(path));
            return;
        }

        // 例如：4个元素选3个，最多要从第2个元素开始选，所以就是4-3+1
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {  // 这里
            path.add(i);
            backtracking(n, k, i + 1);
            path.removeLast();
        }
    }
}

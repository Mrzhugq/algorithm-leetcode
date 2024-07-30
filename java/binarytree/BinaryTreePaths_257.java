package binarytree;

import java.util.ArrayList;
import java.util.List;

/**
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 */
public class BinaryTreePaths_257 {

    public List<String> binaryTreePaths(TreeNode root) {
        List<Integer> paths = new ArrayList<>(); // 记录路径
        List<String> res = new ArrayList<>();
        traversal(root, paths, res);
        return res;
    }

    // 回溯的思想
    private void traversal(TreeNode cur, List<Integer> paths, List<String> res) {
        paths.add(cur.val);
        if (cur.left == null && cur.right == null) {  // 左右都为null才是叶子节点
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < paths.size() - 1; i++) {
                sb.append(paths.get(i)).append("->");
            }
            sb.append(paths.get(paths.size() - 1));
            res.add(sb.toString());
            return;
        }

        if (cur.left != null) {
            traversal(cur.left, paths, res);
            paths.remove(paths.size() - 1);
        }
        if (cur.right != null) {
            traversal(cur.right, paths, res);
            paths.remove(paths.size() - 1);
        }
    }

}

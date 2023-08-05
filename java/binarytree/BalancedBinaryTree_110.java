package binarytree;

/**
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1
 */
public class BalancedBinaryTree_110 {

    // 求度可以从上到下去查 所以需要前序遍历（中左右），而高度只能从下到上去查，所以只能后序遍历（左右中）
    public boolean isBalanced(TreeNode root) {
        int res = getHeight(root);
        return res != -1;
    }

    // 如果已经不是二叉平衡树了，可以返回-1 来标记已经不符合平衡树的规则了
    private int getHeight(TreeNode cur) {
        if (cur == null) return 0;

        int leftHeight = getHeight(cur.left); // 左
        if (leftHeight == -1) return -1;

        int rightHeight = getHeight(cur.right); // 右
        if (rightHeight == -1) return -1;

        if (Math.abs(leftHeight - rightHeight) > 1) return -1; // 中
        return Math.max(leftHeight, rightHeight) + 1;
    }

}

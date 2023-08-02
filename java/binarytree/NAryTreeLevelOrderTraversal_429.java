package binarytree;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
 */
public class NAryTreeLevelOrderTraversal_429 {

    public List<List<Integer>> levelOrder(Node root) {
        Deque<Node> queue = new ArrayDeque<>();
        if (root != null) {
            queue.offer(root);
        }
        List<List<Integer>> res = new ArrayList<>();
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                list.add(node.val);
                for (int j = 0; j < node.children.size(); j++) {
                    queue.offer(node.children.get(j));
                }
            }
            res.add(list);
        }
        return res;
    }

    // 节点定义
    static class Node {
        public int val;
        public List<Node> children;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    }
}



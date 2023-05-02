/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
自下向上查找 -> 回溯 -> 后序遍历（天然的回溯过程） -> 最先处理的一定是叶子节点
如果找到一个节点，发现左子树出现p(或q)，右子树出现q(或p)，那么该节点就是pq的最近公共祖先

本题我们应该遍历整棵树，因为如果左子树找到答案了，还要递归右子树看看是否有更深的结果，
而递归函数又有返回值，所以我们要处理完再返回，比较绕。
*/
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {      
        if(root == NULL || root == q || root == p)  return root;//结束条件关键

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)
        {
            return root;
        }

        if(left != NULL && right == NULL) //一个为空一个不为空，不为空即找到满足条件了
        {                                 //返回不为空的即可，画图理解理解，看似简单但实际不简单
            return left;
        }
        else if(left == NULL && right != NULL)
        {
            return right;
        }
        else //left == NULL && right == NULL
        {
            return NULL;
        }
    }
};

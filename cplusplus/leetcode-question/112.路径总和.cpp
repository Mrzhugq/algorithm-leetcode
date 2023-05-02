/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//前中后遍历都行，因为中节点没有处理逻辑
class Solution 
{
private: 
    //每层递归累加看是否等于targetSum 
    bool traversal(TreeNode* root, int targetSum, int curSum)
    {
        if(root->left == NULL && root->right == NULL && targetSum == curSum)
        {
            return true;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return false;
        }

        if(root->left != NULL)
        {
            curSum += root->left->val;
            if(traversal(root->left, targetSum, curSum)) return true;
            curSum -= root->left->val; //回溯
        }
        if(root->right!= NULL)
        {
            curSum += root->right->val;
            if(traversal(root->right, targetSum, curSum)) return true;
            curSum -= root->right->val; //回溯
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL) return false;
        return traversal(root, targetSum, 0 + root->val); //注意第三个参数
    }
};



/*
简化后：（不是累加节点值，是递减targetSum）
class Solution 
{
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL & targetSum == root->val)
        {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
*/

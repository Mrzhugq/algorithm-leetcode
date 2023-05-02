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

//前中后遍历都行
//本题递归函数不需要返回值，因为需要遍历整颗树

//本题使用减法，和112思路差不多
//递归结束条件判断是否count == 0就行，而112用的加法判断count == targetSum

class Solution 
{
private: 
    vector<vector<int>> res;
    vector<int> path;
    void traversal(TreeNode* root, int targetSum, int count)
    {
        //符合条件保存下来
        if(root->left == NULL && root->right == NULL && count == 0)
        {
            res.push_back(path);
            return;
        }

        if(root->left != NULL)
        {
            path.push_back(root->left->val);
            count -= root->left->val;
            traversal(root->left, targetSum, count);//递归
            path.pop_back(); //回溯
            count += root->left->val;
        }
        if(root->right != NULL)
        {
            path.push_back(root->right->val);
            count -= root->right->val;
            traversal(root->right, targetSum, count);//递归
            path.pop_back(); //回溯
            count += root->right->val;

        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        res.clear();
        path.clear();
        if(root == NULL)  return res;

        path.push_back(root->val); //记得先处理好头节点
        int count = targetSum - root->val;
        traversal(root, targetSum, count);
        return res;
    }
};

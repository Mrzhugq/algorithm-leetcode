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

//暴力--枚举 root 中的每一个节点，判断以这个点的子树是否和 subRoot 相等
class Solution 
{
private:
    bool check(TreeNode* s, TreeNode* t)
    {
        //排除为空情况
        if(s == NULL && t == NULL)  return true;
        else if(s != NULL && t == NULL)  return false;
        else if(s == NULL && t != NULL)  return false;
        //排除数值不相同
        else if(s->val != t->val)  return false;

        //节点不为空而且数值相同，然后比较剩下的节点是否相等
        return check(s->left, t->left) && check(s->right, t->right);
    }

    bool dfs(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL)  return false;
        //找到一个与sunRoot匹配就行，所以用||
        return check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        return dfs(root, subRoot);
    }
};

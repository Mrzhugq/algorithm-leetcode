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

//只有当左右孩子都为空时候才说明遍历到最低点了，有一个孩子为空则不是最低点

class Solution 
{
public:
    int minDepth(TreeNode* root) 
    {
        queue<TreeNode*> que;
        int depth = 0;
        if(root != NULL)  que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            depth++; //先运行这行，要在33行之前
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left == NULL && node->right == NULL)
                {
                    return depth;
                } 
                if(node->left != NULL)  que.push(node->left);
                if(node->right != NULL)  que.push(node->right);
            }
        } 
        return depth;
    }
};

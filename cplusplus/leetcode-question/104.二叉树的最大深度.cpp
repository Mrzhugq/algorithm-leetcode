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

//最大深度就是层数

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        queue<TreeNode*> que;
        int depth = 0;
        if(root != NULL)  que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left != NULL)  que.push(node->left);
                if(node->right != NULL)  que.push(node->right);
            }  
            depth++;
        }
        return depth;
    }
};


//C递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root)
{
    if(root==0) return 0;
    int LeftMax=maxDepth(root->left);
    int RightMax=maxDepth(root->right);
    return (LeftMax>RightMax?LeftMax:RightMax)+1;
} 

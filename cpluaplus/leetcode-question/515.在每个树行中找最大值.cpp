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
class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> res;
        queue<TreeNode*> que;
    
        if(root != NULL)  que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            int maxValue = INT_MIN; //存每层的最大值
            for(int i=0; i<size; i++) //注意size
            {
                TreeNode* node = que.front();
                que.pop();
                maxValue = node->val > maxValue ? node->val : maxValue;
                if(node->left != NULL)   que.push(node->left);
                if(node->right != NULL)  que.push(node->right);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};

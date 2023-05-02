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

//用队列 先进先出符合一层一层遍历的逻辑

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        queue<TreeNode*> que;

        if(root != NULL)  que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            //for里的size不能是写成que.size()，因为for循环中que.size()是不断变换的
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left != NULL)   que.push(node->left);   
                if(node->right != NULL)  que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};




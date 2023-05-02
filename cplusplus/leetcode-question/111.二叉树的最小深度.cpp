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

//ֻ�е����Һ��Ӷ�Ϊ��ʱ���˵����������͵��ˣ���һ������Ϊ��������͵�

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
            depth++; //���������У�Ҫ��33��֮ǰ
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

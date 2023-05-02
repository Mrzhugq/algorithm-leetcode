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

//�ö��� �Ƚ��ȳ�����һ��һ��������߼�

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
            //for���size������д��que.size()����Ϊforѭ����que.size()�ǲ��ϱ任��
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




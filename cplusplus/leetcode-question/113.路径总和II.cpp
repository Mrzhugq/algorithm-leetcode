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

//ǰ�к��������
//����ݹ麯������Ҫ����ֵ����Ϊ��Ҫ����������

//����ʹ�ü�������112˼·���
//�ݹ���������ж��Ƿ�count == 0���У���112�õļӷ��ж�count == targetSum

class Solution 
{
private: 
    vector<vector<int>> res;
    vector<int> path;
    void traversal(TreeNode* root, int targetSum, int count)
    {
        //����������������
        if(root->left == NULL && root->right == NULL && count == 0)
        {
            res.push_back(path);
            return;
        }

        if(root->left != NULL)
        {
            path.push_back(root->left->val);
            count -= root->left->val;
            traversal(root->left, targetSum, count);//�ݹ�
            path.pop_back(); //����
            count += root->left->val;
        }
        if(root->right != NULL)
        {
            path.push_back(root->right->val);
            count -= root->right->val;
            traversal(root->right, targetSum, count);//�ݹ�
            path.pop_back(); //����
            count += root->right->val;

        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        res.clear();
        path.clear();
        if(root == NULL)  return res;

        path.push_back(root->val); //�ǵ��ȴ����ͷ�ڵ�
        int count = targetSum - root->val;
        traversal(root, targetSum, count);
        return res;
    }
};

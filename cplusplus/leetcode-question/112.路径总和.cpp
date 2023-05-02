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

//ǰ�к�������У���Ϊ�нڵ�û�д����߼�
class Solution 
{
private: 
    //ÿ��ݹ��ۼӿ��Ƿ����targetSum 
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
            curSum -= root->left->val; //����
        }
        if(root->right!= NULL)
        {
            curSum += root->right->val;
            if(traversal(root->right, targetSum, curSum)) return true;
            curSum -= root->right->val; //����
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL) return false;
        return traversal(root, targetSum, 0 + root->val); //ע�����������
    }
};



/*
�򻯺󣺣������ۼӽڵ�ֵ���ǵݼ�targetSum��
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

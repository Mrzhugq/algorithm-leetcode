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


//������Ҫ���������������Բ�Ҫ����ֵ��������ֵ���԰�����������޼���������

//�ⷨ�
class Solution 
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root == NULL)  return NULL;
        if(root->val < low) //root���������нڵ㣬Ӧֱ����ȥ����Ϊroot��������нڵ�ֵһ����low��С
        {
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if(root->val > high) //root���������нڵ㣬Ҳֱ����ȥ
        {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        //root->val ��[low, hight]����
        root->left = trimBST(root->left, low, high); //����һ��Ľ�ס��ɾ���Ĺؼ�
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

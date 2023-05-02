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

//��ȫ������˼·��

class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        if(root == NULL)  return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftHeight = 0, rightHeight = 0;
        while(left != NULL) //һֱ�����ߵ����
        {
            left = left->left;
            ++leftHeight;
        }
        while(right != NULL) //һֱ�����ߵ����
        {
            right = right->right;
            ++rightHeight;
        }
        //cout << leftHeight << endl;
        if(leftHeight == rightHeight) //������������������ڵ���Ϊ (2^�߶�)-1
        {
            //���� ��һ���������������(���ڵ�Ϊ��һ��),�ߵ�����leftHeight == rightHeight == 2
            //(2 << 2) -1  ==  (2 ^ 3) - 1; 
            return (2 << leftHeight) - 1;
        }
        //����������������������ݹ���������ֱ��������������Ϊֹ��һ���ڵ�Ҳ������������
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

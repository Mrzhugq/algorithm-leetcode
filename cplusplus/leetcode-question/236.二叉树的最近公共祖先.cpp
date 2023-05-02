/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
�������ϲ��� -> ���� -> �����������Ȼ�Ļ��ݹ��̣� -> ���ȴ����һ����Ҷ�ӽڵ�
����ҵ�һ���ڵ㣬��������������p(��q)������������q(��p)����ô�ýڵ����pq�������������

��������Ӧ�ñ�������������Ϊ����������ҵ����ˣ���Ҫ�ݹ������������Ƿ��и���Ľ����
���ݹ麯�����з���ֵ����������Ҫ�������ٷ��أ��Ƚ��ơ�
*/
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {      
        if(root == NULL || root == q || root == p)  return root;//���������ؼ�

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)
        {
            return root;
        }

        if(left != NULL && right == NULL) //һ��Ϊ��һ����Ϊ�գ���Ϊ�ռ��ҵ�����������
        {                                 //���ز�Ϊ�յļ��ɣ���ͼ�����⣬���Ƽ򵥵�ʵ�ʲ���
            return left;
        }
        else if(left == NULL && right != NULL)
        {
            return right;
        }
        else //left == NULL && right == NULL
        {
            return NULL;
        }
    }
};

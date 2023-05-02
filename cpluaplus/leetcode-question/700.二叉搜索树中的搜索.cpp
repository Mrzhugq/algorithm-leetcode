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

/*
��������һ����������
���������������գ��������������н���ֵ��С�����ĸ�����ֵ��
���������������գ��������������н���ֵ���������ĸ�����ֵ��
������������Ҳ�ֱ�Ϊ����������
��;����ˣ���������������ͨ�������ı����͵�������ͬ
*/

class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root == NULL || root->val == val)  return root;

        if(root->val > val)
        {
            return searchBST(root->left, val);
            //ע���������return����Ϊ�ҵ�Ŀ��ֵ�������ؾ��У����ñ���������
        }
        if(root->val < val)
        {
            return searchBST(root->right, val);
        }
        return NULL;
    }
};



//---------------------------------------------------------- 
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

//����Ҫʹ�ø����ռ䣬����Ҫ���ݣ���Ϊ�����԰�����ȷ���������ķ���
class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        while(root != NULL)
        {
            if(root->val > val)
            {
                root = root->left;
            }
            else if(root->val < val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return NULL;
    }
};

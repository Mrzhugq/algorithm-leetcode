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

//�жϵ�ǰ�ڵ��ǲ�����Ҷ�����޷��жϵģ�����ͨ���ڵ�ĸ��ڵ��ж������ǲ�����Ҷ��
//��Ҷ�ӣ�����ýڵ�����Ӳ�Ϊ�գ����Ҹýڵ�����ӵ�����Ϊ�գ��ýڵ�����ӵ��Һ���ҲΪ��
//        ��ýڵ�����Ӿ�����һ����Ҷ�ӣ����ҵ���һ����Ҷ��

//�ݹ���Ҫ ��������������У�����ΪҪͨ���ݹ麯���ķ���ֵ���ۼ���ȡ��Ҷ����ֵ֮��
class Solution 
{
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(root == NULL)  return 0;
        
        int leftValue = sumOfLeftLeaves(root->left);
        int rightValue = sumOfLeftLeaves(root->right);

        int Value = 0;
        //ͨ�����׽ڵ�ͱ���ĺ����ж��ǲ�����Ҷ��
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            Value = root->left->val;
        }
        return leftValue + rightValue + Value;
    }
};



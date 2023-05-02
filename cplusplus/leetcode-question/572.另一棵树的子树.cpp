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

//����--ö�� root �е�ÿһ���ڵ㣬�ж��������������Ƿ�� subRoot ���
class Solution 
{
private:
    bool check(TreeNode* s, TreeNode* t)
    {
        //�ų�Ϊ�����
        if(s == NULL && t == NULL)  return true;
        else if(s != NULL && t == NULL)  return false;
        else if(s == NULL && t != NULL)  return false;
        //�ų���ֵ����ͬ
        else if(s->val != t->val)  return false;

        //�ڵ㲻Ϊ�ն�����ֵ��ͬ��Ȼ��Ƚ�ʣ�µĽڵ��Ƿ����
        return check(s->left, t->left) && check(s->right, t->right);
    }

    bool dfs(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL)  return false;
        //�ҵ�һ����sunRootƥ����У�������||
        return check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        return dfs(root, subRoot);
    }
};

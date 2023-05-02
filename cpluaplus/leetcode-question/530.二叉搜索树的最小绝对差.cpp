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

//�������������������������ת��Ϊ���飬ת�������һ�������������飬
//��������������������������������ֵ����С��
//��Ϊ����������������������ֵ��С����С��ֵ -> ������������ֵ����С��

class Solution 
{
private:
    vector<int> vec;
    void traversal(TreeNode* root)
    {
        if(root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) 
    {
        vec.clear();
        traversal(root);
        if(vec.size() < 2)  return 0;
        int res = INT_MAX;
        for(int i=1; i<vec.size(); i++)
        {
            res = min(res, vec[i] - vec[i - 1]);
        }
        return res;
    }
};

//---------------------------------------------------- 
//��ʵ���ǿ��Բ��ø������飬��������������У��Ϳ���ֱ�Ӽ�����
//��ʵ��ת��Ϊ���飬Ҳ���Ƴ� ���������ڵ����ֵ��ֵ��С ->  ���������ڵ�Ĳ�ֵ

class Solution 
{
private: 
    int res = INT_MAX;
    TreeNode* pre = NULL; //��¼cur�ڵ��ǰһ���ڵ�
    void traversal(TreeNode* cur)
    {
        if(cur == NULL)  return;
        traversal(cur->left);
        if(pre != NULL)
        {
            res = min(res, cur->val - pre->val);
        }
        pre = cur; //��¼ǰһ��
        traversal(cur->right);
    }
public:
    int getMinimumDifference(TreeNode* root) 
    {
        traversal(root);
        return res;
    }
};



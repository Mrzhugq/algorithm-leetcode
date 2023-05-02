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

//��������£������������һ����������

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
    bool isValidBST(TreeNode* root) 
    {
        vec.clear();
        traversal(root);
        for(int i = 1; i < vec.size(); i++)
        {
            //ע��Ҫ���ڵ��ڣ�����ֻ���ڣ���Ϊ�����������ﲻ������ͬԪ��
            if(vec[i - 1] >= vec[i])
            {
                return false;
            }
        }
        return true;
    }
};
//-------------------------------------------------------------------- 
//��ʵ���ô���һ�����飬�ڵݹ�����о����ж��Ƿ�����
class Solution 
{
public:
    long long maxVal = LONG_MIN;//����ʼ��ΪINT_MIN����Ϊ������������int��Сֵ
    bool isValidBST(TreeNode* root) 
    {
        if(root == NULL)  return true;

        bool left = isValidBST(root->left);
        //���ܵ����Ƚ���ڵ�С���м�ڵ㣬�ҽڵ�����м�ڵ�
        //����Ҫ�Ƚ��ǣ������������нڵ�С���м�ڵ㣬�����������нڵ�����м�ڵ�
        if(maxVal < root->val)
        {
            maxVal = root->val;
        }
        else
        {
            return false;
        }
        bool right = isValidBST(root->right);
        return left && right;
        //�ݹ麯���з���ֵ����ΪֻҪ�ҵ�һ�������������ľ���������������Ҫ������Сȥ��
    }
};

//---------------------------------------------------------------------------------
class Solution 
{
public:
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) 
    {
        if(root == NULL)  return true;
        bool left = isValidBST(root->left);

        if(pre != NULL && pre->val >= root->val)
        {
            return false;
        }
        pre = root;
        
        // if(pre == NULL || pre->val < root->val)
        // {
        //     pre = root;
        // } 
        // else
        // {
        //     return false;
        // }

        bool right = isValidBST(root->right);
        return left && right;
    }
}; 

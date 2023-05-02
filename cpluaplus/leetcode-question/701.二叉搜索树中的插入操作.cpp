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

//���Բ�������Ŀ�еĸı�������ṹ�Ĳ��뷽ʽ,ֻҪ�������������Ĺ���ȥ����,�����սڵ�Ͳ���ڵ�Ϳ���

// ���ͨ���ݹ麯������ֵ����¼���ڵ�ĸ��ӹ�ϵ��ֵ������
// ��һ�㽫�½ڵ㷵�أ�������root->left����root->right�����ס��
class Solution 
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL) 
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(root->val > val)
        {
            root->left = insertIntoBST(root->left, val); //��ֵ�ؼ�
        }
        else if(root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

//------------------------------------------------------------------------
//����з���ֵ���޷���ֵ�ĸ��鷳һ��
class Solution 
{
private:
    TreeNode* parent;
    void traversal(TreeNode* cur, int val) //�޷���ֵ
    {
        if(cur == NULL)
        {
            TreeNode* node = new TreeNode(val);
            if(val < parent->val) //���븸�׵����
            {
                parent->left = node;
            }
            else //���븸�׽ڵ��ұ�
            {
                parent->right = node;
            }
            return;
        }

        parent = cur; //��¼����
        if(cur->val > val)  traversal(cur->left, val);
        if(cur->val < val)  traversal(cur->right, val);
        return;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        parent = new TreeNode(0);
        if(root == NULL) 
        {
            root = new TreeNode(val);
        }
        traversal(root, val);
        return root;
    }
}; 

//---------------------------------------------------------------------------
//������ -> �͵ݹ麯���޷���ֵ���ƣ���Ҫ��һ��parent��¼���׽ڵ�
class Solution 
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* parent = root; //�������Ҫ
        TreeNode* cur = root;
        while(cur != NULL)
        {
            parent = cur; //��¼���׽ڵ�
            if(cur->val > val) 
            {
                cur = cur->left;
            }
            else 
            {
                cur = cur->right;
            }
        }
        //����
        TreeNode *node = new TreeNode(val);
        if(val < parent->val) //���ڸ��׽ڵ�����
        {
            parent->left = node;
        }
        else //�����ұ�
        {
            parent->right = node;
        }
        return root;
    }
}; 

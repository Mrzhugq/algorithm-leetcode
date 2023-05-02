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
 
 
 
//�ۼ�����ʹ��ÿ���ڵ��ֵ��ԭ���Ľڵ�ֵ�������д������Ľڵ�ֵ֮��
//[2, 5, 13]  ->  [20, 18, 13]  ���������Ӻ���ǰ�ۼӾ�����
//�����������أ������򼴿� -> ���������ƽ���)
class Solution 
{
private:
    //���������������Բ���Ҫ����ֵ
    TreeNode* pre; //��¼ǰһ���ڵ㣬�����ۼ�
    void traversal(TreeNode* cur)
    {
        if(cur == NULL) return;
        
        traversal(cur->right);
        if(pre != NULL)
        {
            cur->val += pre->val;
        }
        pre = cur;//��¼
        traversal(cur->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        pre = NULL;
        traversal(root);
        return root;
    }
};


//----------------------------------------------------------------------- 
//���� - ģ��ݹ�
class Solution 
{
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while(cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur = cur->right;  //��
            }
            else
            {
                cur = st.top();    //��
                st.pop();
                if(pre != NULL)
                {
                    cur->val += pre->val;
                }
                pre = cur;         //��¼ǰһ���ڵ�
                cur = cur->left;   //��
            }
        }
        return root;
    }
};

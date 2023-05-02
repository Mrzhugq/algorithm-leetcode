/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//���������� -> ֻҪ������ʱ��cur�ڵ�����ֵ��[p, q]��������˵���ýڵ�cur���������������
//��Ϊ��ͨ������������Ҫ���������������ݣ�
//����������������Ͳ���Ҫ�����ˣ���Ϊ�����Դ����򣩣�ֻҪ�������±����Ϳ�����

//���������������ʵʲô�������У�����û�д����м�ڵ㴦���߼�����
//���Ҳ���Ҫ��������������Ϊ���򣩣��ҵ����ֱ�ӷ���
class Solution 
{
private:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q)
    {
        if(cur == NULL)  return NULL;
        
        if(cur->val > p->val && cur->val > q->val) //��Ϊ��֪��p,q�Ǹ����Ǹ�С�����Զ��Ƚ�һ��
        {
            TreeNode* left = traversal(cur->left, p, q);
            if(left != NULL) //�ҵ��ͷ���
            {
                return left;
            }
        }
        if(cur->val < p->val && cur->val < q->val)
        {
            TreeNode* right = traversal(cur->right, p, q);
            if(right != NULL)
            {
                return right;
            }
        }
        return cur;  //cur��[p,q]������
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return traversal(root, p, q);
    }
};

//-------------------------------------------------------------------------------
//�������͵ݹ�˼·һ��
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        while(root != NULL)
        {
            if(root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else //root�� [p,q]��
            {
                return root;
            }
        }
        return NULL;
    }
}; 

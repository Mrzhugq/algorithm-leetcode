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
//��ת���������� ->  ���ǰ�ÿ���ڵ�����Һ��ӷ�תһ��
//BFS - ǰ������������С�Ψ������������У�
//��Ϊ���������������,��ת������,�����ߵ��Ѿ���ת�õķ�ת���ұߣ���������ʱ�ְѷ�ת�õ��ַ�ת��һ��
//���Ի��ĳЩ�ڵ�����Һ��ӷ�ת����
*/

//------------------------------------------------------------------------------------ 
//������� BFS
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        queue<TreeNode*> que;
        if(root != NULL)  que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right); //����ڵ�
                if(node->left != NULL)   que.push(node->left);
                if(node->right != NULL)  que.push(node->right);
            }
        }
        return root;
    }
};



//---------------------------------------------------------------------------------------- 
//ǰ�� - �ݹ�
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};



//--------------------------------------------------------------------------------------- 
//ǰ�� - ����
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);                  //��
            if(node->right != NULL) st.push(node->right);   //�ң���Ϊ��ջ���������ң�
            if(node->left != NULL)  st.push(node->left);    //��
        }
        return root;
    }
};



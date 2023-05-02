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
//翻转整个二叉树 ->  就是把每个节点的左右孩子翻转一下
//BFS - 前序后后序遍历都行。唯独中序遍历不行，
//因为中序遍历是左中右,翻转完左中,会把左边的已经翻转好的翻转到右边，而反翻右时又把翻转好的又翻转了一遍
//所以会把某些节点的左右孩子翻转两次
*/

//------------------------------------------------------------------------------------ 
//层序遍历 BFS
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
                swap(node->left, node->right); //处理节点
                if(node->left != NULL)   que.push(node->left);
                if(node->right != NULL)  que.push(node->right);
            }
        }
        return root;
    }
};



//---------------------------------------------------------------------------------------- 
//前序 - 递归
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
//前序 - 迭代
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
            swap(node->left, node->right);                  //中
            if(node->right != NULL) st.push(node->right);   //右（因为是栈所以先入右）
            if(node->left != NULL)  st.push(node->left);    //左
        }
        return root;
    }
};



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
二叉搜是一个有序树：
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
它的左、右子树也分别为二叉搜索树
这就决定了，二叉搜索树和普通二叉树的遍历和迭代法不同
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
            //注意这里加了return，因为找到目标值立即返回就行，不用遍历整棵树
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

//不需要使用辅助空间，不需要回溯，因为有序性帮我们确定了搜索的方向
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

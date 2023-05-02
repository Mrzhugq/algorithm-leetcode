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


//本题需要遍历整颗树，可以不要返回值，但返回值可以帮助我们完成修剪，更方便

//解法妙啊
class Solution 
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root == NULL)  return NULL;
        if(root->val < low) //root的左子树有节点，应直接舍去，因为root的左边所有节点值一定比low还小
        {
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if(root->val > high) //root的右子树有节点，也直接舍去
        {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        //root->val 在[low, hight]区间
        root->left = trimBST(root->left, low, high); //把上一层的接住，删除的关键
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

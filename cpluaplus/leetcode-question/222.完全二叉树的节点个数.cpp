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

//完全二叉树思路：

class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        if(root == NULL)  return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftHeight = 0, rightHeight = 0;
        while(left != NULL) //一直往左走的深度
        {
            left = left->left;
            ++leftHeight;
        }
        while(right != NULL) //一直往右走的深度
        {
            right = right->right;
            ++rightHeight;
        }
        //cout << leftHeight << endl;
        if(leftHeight == rightHeight) //相等则是满二叉树，节点数为 (2^高度)-1
        {
            //比如 是一棵三层的满二叉树(根节点为第一层),走到这里leftHeight == rightHeight == 2
            //(2 << 2) -1  ==  (2 ^ 3) - 1; 
            return (2 << leftHeight) - 1;
        }
        //整个树不是满二叉树，则递归左右子树直到遇到满二叉树为止（一个节点也是满二叉树）
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

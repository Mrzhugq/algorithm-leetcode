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

//判断当前节点是不是左叶子是无法判断的，必须通过节点的父节点判断左孩子是不是左叶子
//左叶子：如果该节点的左孩子不为空，而且该节点的左孩子的左孩子为空，该节点的左孩子的右孩子也为空
//        则该节点的左孩子就是是一个左叶子，即找到了一个左叶子

//递归需要 后序遍历（左右中）：因为要通过递归函数的返回值来累加求取左叶子数值之和
class Solution 
{
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(root == NULL)  return 0;
        
        int leftValue = sumOfLeftLeaves(root->left);
        int rightValue = sumOfLeftLeaves(root->right);

        int Value = 0;
        //通过父亲节点和本身的孩子判断是不是左叶子
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            Value = root->left->val;
        }
        return leftValue + rightValue + Value;
    }
};



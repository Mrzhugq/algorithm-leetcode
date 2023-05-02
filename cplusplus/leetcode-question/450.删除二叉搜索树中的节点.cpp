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
删除搜索二叉树节点思路：
一.没有找到要删除节点

二.找到删除的节点
    1.要删除节点的左右孩子都为空 -> 直接删除，返回NULL
    2.要删除节点的左孩子为空，右孩子不为空 -> 删除该节点右孩子补位
    3.要删除节点的左孩子不为空，右孩子为空 -> 删除该节点左孩子补位
    4.如果要删除节点的左右节点都不为空，怎么处理？
    将删除节点的左子树头节点（左孩子）放到要删除节点的右子树的最左边节点的左孩子上，
    返回要删除节点右孩 子为新的跟节点
*/

//二叉树思路：
class Solution 
{
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)  return NULL; //没找到
        if(root->val == key)
        {
            //如果要删除节点的左右孩子都为空直接删除，返回NULL
            if(root->left == NULL) //要删除节点的左节点为空，右不为空，删除该节点右孩子补位
            {
                TreeNode* temp = root->right; //这三行就是释放要删除节点的内存，下面一样
                delete root;
                return temp;
                //return root->right;         //这样写是不释放内存
            }
            else if(root->right == NULL)//要删除节点的右节点为空，左不为空，删除该节点左孩子补位 
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
                //return root->left;
            }
            else //要删除节点的左右节点都不为空
            {
                TreeNode* cur = root->right;
                while(cur->left != NULL)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* temp = root; //记录要删除的节点，以便于释放内存
                root = root->right;
                delete temp;
                return root; 
            }
        }

        if(root->val > key)
        {
            root->left = deleteNode(root->left, key); 
            //这里相当于把新的节点返回上一层，上一层就要用root->left或者root->right接住
        }
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};



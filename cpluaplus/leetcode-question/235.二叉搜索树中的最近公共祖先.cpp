/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//搜索二叉树 -> 只要遍历的时候，cur节点是数值在[p, q]区间中则说明该节点cur就是最近公共祖先
//因为普通二叉树无序需要自下向上搜索回溯，
//而搜索二叉树有序就不需要回溯了，因为有序（自带方向），只要从上向下遍历就可以了

//采用中序遍历（其实什么遍历都行，本题没有处理中间节点处理逻辑），
//而且不需要遍历整个树（因为有序），找到结果直接返回
class Solution 
{
private:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q)
    {
        if(cur == NULL)  return NULL;
        
        if(cur->val > p->val && cur->val > q->val) //因为不知道p,q那个大那个小，所以都比较一下
        {
            TreeNode* left = traversal(cur->left, p, q);
            if(left != NULL) //找到就返回
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
        return cur;  //cur在[p,q]区间内
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return traversal(root, p, q);
    }
};

//-------------------------------------------------------------------------------
//迭代，和递归思路一样
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
            else //root在 [p,q]内
            {
                return root;
            }
        }
        return NULL;
    }
}; 

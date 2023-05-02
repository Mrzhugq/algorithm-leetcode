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

//可以不考虑题目中的改变二叉树结构的插入方式,只要按二叉搜索树的规则去遍历,遇到空节点就插入节点就可了

// 如何通过递归函数返回值完成新加入节点的父子关系赋值操作？
// 下一层将新节点返回，本层用root->left或者root->right将其接住。
class Solution 
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL) 
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(root->val > val)
        {
            root->left = insertIntoBST(root->left, val); //赋值关键
        }
        else if(root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

//------------------------------------------------------------------------
//相比有返回值，无返回值的更麻烦一点
class Solution 
{
private:
    TreeNode* parent;
    void traversal(TreeNode* cur, int val) //无返回值
    {
        if(cur == NULL)
        {
            TreeNode* node = new TreeNode(val);
            if(val < parent->val) //插入父亲的左边
            {
                parent->left = node;
            }
            else //插入父亲节点右边
            {
                parent->right = node;
            }
            return;
        }

        parent = cur; //记录父亲
        if(cur->val > val)  traversal(cur->left, val);
        if(cur->val < val)  traversal(cur->right, val);
        return;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        parent = new TreeNode(0);
        if(root == NULL) 
        {
            root = new TreeNode(val);
        }
        traversal(root, val);
        return root;
    }
}; 

//---------------------------------------------------------------------------
//迭代法 -> 和递归函数无返回值类似，需要有一个parent记录父亲节点
class Solution 
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* parent = root; //这个很重要
        TreeNode* cur = root;
        while(cur != NULL)
        {
            parent = cur; //记录父亲节点
            if(cur->val > val) 
            {
                cur = cur->left;
            }
            else 
            {
                cur = cur->right;
            }
        }
        //插入
        TreeNode *node = new TreeNode(val);
        if(val < parent->val) //插在父亲节点的左边
        {
            parent->left = node;
        }
        else //插入右边
        {
            parent->right = node;
        }
        return root;
    }
}; 

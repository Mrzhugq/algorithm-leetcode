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

//中序遍历下，输出的数组是一个有序数组

class Solution 
{
private:
    vector<int> vec;
    void traversal(TreeNode* root)
    {
        if(root == NULL) return;

        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        vec.clear();
        traversal(root);
        for(int i = 1; i < vec.size(); i++)
        {
            //注意要大于等于，不能只大于，因为二叉搜索树里不能有相同元素
            if(vec[i - 1] >= vec[i])
            {
                return false;
            }
        }
        return true;
    }
};
//-------------------------------------------------------------------- 
//其实不用创建一个数组，在递归过程中就能判断是否有序
class Solution 
{
public:
    long long maxVal = LONG_MIN;//不初始胡为INT_MIN是因为测试用例中有int最小值
    bool isValidBST(TreeNode* root) 
    {
        if(root == NULL)  return true;

        bool left = isValidBST(root->left);
        //不能单纯比较左节点小于中间节点，右节点大于中间节点
        //我们要比较是：左子树上所有节点小于中间节点，右子树上所有节点大于中间节点
        if(maxVal < root->val)
        {
            maxVal = root->val;
        }
        else
        {
            return false;
        }
        bool right = isValidBST(root->right);
        return left && right;
        //递归函数有返回值是因为只要找到一个不符合条件的就立即结束，不需要继续找小去了
    }
};

//---------------------------------------------------------------------------------
class Solution 
{
public:
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) 
    {
        if(root == NULL)  return true;
        bool left = isValidBST(root->left);

        if(pre != NULL && pre->val >= root->val)
        {
            return false;
        }
        pre = root;
        
        // if(pre == NULL || pre->val < root->val)
        // {
        //     pre = root;
        // } 
        // else
        // {
        //     return false;
        // }

        bool right = isValidBST(root->right);
        return left && right;
    }
}; 

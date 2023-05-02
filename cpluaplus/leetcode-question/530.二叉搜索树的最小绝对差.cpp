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

//可以用中序遍历把搜索二叉树转化为数组，转化后就是一个有序升序数组，
//即在有序升序数组中找任意两个数差值的最小，
//因为是升序中找任意两个数差值最小，最小差值 -> 相邻两个数差值中最小的

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
    int getMinimumDifference(TreeNode* root) 
    {
        vec.clear();
        traversal(root);
        if(vec.size() < 2)  return 0;
        int res = INT_MAX;
        for(int i=1; i<vec.size(); i++)
        {
            res = min(res, vec[i] - vec[i - 1]);
        }
        return res;
    }
};

//---------------------------------------------------- 
//其实我们可以不用辅助数组，在中序遍历过程中，就可以直接计算了
//其实不转化为数组，也可推出 任意两个节点绝对值差值最小 ->  相邻两个节点的差值

class Solution 
{
private: 
    int res = INT_MAX;
    TreeNode* pre = NULL; //记录cur节点的前一个节点
    void traversal(TreeNode* cur)
    {
        if(cur == NULL)  return;
        traversal(cur->left);
        if(pre != NULL)
        {
            res = min(res, cur->val - pre->val);
        }
        pre = cur; //记录前一个
        traversal(cur->right);
    }
public:
    int getMinimumDifference(TreeNode* root) 
    {
        traversal(root);
        return res;
    }
};



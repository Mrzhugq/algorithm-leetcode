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

//区间都是左闭右开 [ )
class Solution 
{
private:
    TreeNode* traversal(vector<int>& nums, int left, int right)
    {
        //if(left == right)
        if(left >= right) //因为是左闭右开，所以当left==right时就代表数组内没有数值了
        {
            return NULL;
        }
        //找最大值下标
        int maxValIndex = left;
        for(int i = left + 1; i < right; i++)
        {
            if(nums[i] > nums[maxValIndex])
            {
                maxValIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxValIndex]);//创建节点
        //不需要if判断，因为结束条件允许空节点进入递归
        root->left = traversal(nums, left, maxValIndex); //左闭右开
        root->right = traversal(nums, maxValIndex + 1, right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return traversal(nums, 0, nums.size());
    }
};


/*
什么时候递归加if什么时候不加呢?
其实只是不同的代码风格实现，只要递归结束条件能对应就行，
一般情况来说：如果让空节点（空指针）进入递归，就不加if，
如果不让空节点进入递归，就加if限制一下，终止条件也会相应的调整。
*/

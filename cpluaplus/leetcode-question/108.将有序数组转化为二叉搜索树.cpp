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

//高度平衡 -> 只要我们把数组的中间数值作为节点元素，自然而然就是高度平和树
//（一般我们都是默认把数值中间数值作为节点元素）

//数值切割点 -> 数值中间位置（如果长度为偶数，取中间偏左偏右都行）
class Solution 
{
private:
    //区间采用左闭右闭写法[ ];
    TreeNode* traversal(vector<int>& nums, int left, int right)
    {
        if(left > right)  return NULL; //左闭右闭

        int mid = (right - left) / 2 + left; //这样写防止溢出
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return traversal(nums, 0, nums.size() - 1);
    }
};

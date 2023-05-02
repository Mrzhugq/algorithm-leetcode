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

//�߶�ƽ�� -> ֻҪ���ǰ�������м���ֵ��Ϊ�ڵ�Ԫ�أ���Ȼ��Ȼ���Ǹ߶�ƽ����
//��һ�����Ƕ���Ĭ�ϰ���ֵ�м���ֵ��Ϊ�ڵ�Ԫ�أ�

//��ֵ�и�� -> ��ֵ�м�λ�ã��������Ϊż����ȡ�м�ƫ��ƫ�Ҷ��У�
class Solution 
{
private:
    //�����������ұ�д��[ ];
    TreeNode* traversal(vector<int>& nums, int left, int right)
    {
        if(left > right)  return NULL; //����ұ�

        int mid = (right - left) / 2 + left; //����д��ֹ���
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

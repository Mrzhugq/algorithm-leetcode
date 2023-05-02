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

//���䶼������ҿ� [ )
class Solution 
{
private:
    TreeNode* traversal(vector<int>& nums, int left, int right)
    {
        //if(left == right)
        if(left >= right) //��Ϊ������ҿ������Ե�left==rightʱ�ʹ���������û����ֵ��
        {
            return NULL;
        }
        //�����ֵ�±�
        int maxValIndex = left;
        for(int i = left + 1; i < right; i++)
        {
            if(nums[i] > nums[maxValIndex])
            {
                maxValIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxValIndex]);//�����ڵ�
        //����Ҫif�жϣ���Ϊ������������սڵ����ݹ�
        root->left = traversal(nums, left, maxValIndex); //����ҿ�
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
ʲôʱ��ݹ��ifʲôʱ�򲻼���?
��ʵֻ�ǲ�ͬ�Ĵ�����ʵ�֣�ֻҪ�ݹ���������ܶ�Ӧ���У�
һ�������˵������ÿսڵ㣨��ָ�룩����ݹ飬�Ͳ���if��
������ÿսڵ����ݹ飬�ͼ�if����һ�£���ֹ����Ҳ����Ӧ�ĵ�����
*/

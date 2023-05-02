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

//��106��˼·һ���ģ�����ȫ��������ҿ� [ )
class Solution 
{
private:
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd,
                        vector<int>& preorder, int preorderBegin, int preorderEnd)
    {
        if(preorderBegin == preorderEnd)  return NULL;
        int rootValue = preorder[preorderBegin]; //ע��Ҫ��preorderBegin��Ҫ��0
        TreeNode* root = new TreeNode(rootValue);
        if(preorderEnd - preorderBegin == 1)  return root; //Ҷ�ӽڵ�

        int delimiterIndex;
        for(delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
        {
            if(inorder[delimiterIndex] == rootValue)  break;
        }
        //�и���������
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInoderBegin = delimiterIndex + 1;
        int rightInoderEnd = inorderEnd;
        
        //�����������飬�и�ǰ������
        int leftPreorderBegin = preorderBegin + 1;
        //preorderBegin + 1,��һ����Ϊǰһ���Ѿ����ù�����ͷ�ڵ��ˣ���Ҫ����
        int leftPreorderEnd = leftPreorderBegin + (leftInorderEnd - leftInorderBegin);
        //��ֹλ������ʼλ�ü�������������Ĵ�Сsize
        int rightPreorderBegin = leftPreorderBegin + (leftInorderEnd - leftInorderBegin);
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,
                                preorder, leftPreorderBegin, leftPreorderEnd);
        root->right = traversal(inorder, rightInoderBegin, rightInoderEnd,
                                preorder, rightPreorderBegin, rightPreorderEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.size() ==0 || inorder.size() == 0)
        {
            return NULL;
        }
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};

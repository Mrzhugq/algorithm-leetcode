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

//和106题思路一样的，区间全部是左闭右开 [ )
class Solution 
{
private:
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd,
                        vector<int>& preorder, int preorderBegin, int preorderEnd)
    {
        if(preorderBegin == preorderEnd)  return NULL;
        int rootValue = preorder[preorderBegin]; //注意要用preorderBegin不要用0
        TreeNode* root = new TreeNode(rootValue);
        if(preorderEnd - preorderBegin == 1)  return root; //叶子节点

        int delimiterIndex;
        for(delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
        {
            if(inorder[delimiterIndex] == rootValue)  break;
        }
        //切割中序数组
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        int rightInoderBegin = delimiterIndex + 1;
        int rightInoderEnd = inorderEnd;
        
        //根据中序数组，切割前序数组
        int leftPreorderBegin = preorderBegin + 1;
        //preorderBegin + 1,加一是因为前一个已经被用过来当头节点了，需要跳过
        int leftPreorderEnd = leftPreorderBegin + (leftInorderEnd - leftInorderBegin);
        //终止位置是起始位置加上中序左区间的大小size
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

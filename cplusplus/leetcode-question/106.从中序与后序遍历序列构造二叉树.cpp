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

//中序：左中右
//后序: 左右中

//过程中的区间都采用 左闭右开
//切割过程中中序数组和后序数组大小一定是一样的（重要理解）
class Solution 
{
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
    {
        if(postorder.size() == 0) return NULL;

        int rootVal = postorder[postorder.size() - 1]; //节点值就是后序数值里面最后一个数
        TreeNode* root = new TreeNode(rootVal);
        //叶子节点
        if(inorder.size() == 1)  return root;
        //用节点值切割中序数组，先找到节点值在中序数组的位置
        int delimiterIndex;
        for(delimiterIndex = 0; delimiterIndex<inorder.size(); delimiterIndex++)
        {
            if(inorder[delimiterIndex] == rootVal)
                break;
        }

        //开始切割中序数组 [ 左闭右开 )
        //[ 0, delimiterIndex )
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        //[ delimiterIndex + 1, end )
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        //舍去后序数组最后一个元素
        postorder.resize(postorder.size() - 1);
        //开始切割后序数组 [ 左闭右开 )，这里使用左中序数组大小作为切割点
        //[ 0, leftInorder.size )
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        //[ leftInorder.size, end ) //postorder已经不是原来的大小了，舍去了最后一个
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder); //递归建树
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size() == 0 || postorder.size() == 0)
        {
            return NULL;
        }
        return traversal(inorder, postorder);
    }
};



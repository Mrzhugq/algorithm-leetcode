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

//层序遍历比较好理解-最后一行的第一个数值
class Solution 
{
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> que;
        int res = 0;
        if(root != NULL)  que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if(i == 0)//记录最后一行第一个数。每进入新行都会被重新赋值
                {
                    res = node->val;
                }
                if(node->left != NULL)   que.push(node->left);
                if(node->right != NULL)  que.push(node->right);
            } 
        }
        return res;
    }
};


//----------------------------------------------------------------- 
//利用回溯 -
//深度最大- 最后一行
//如何找到深度最大的 最左边 的叶子节点？前序遍历 - 优先左边搜索

class Solution 
{
private:
    //两个全局变量
    int maxLen = INT_MIN; //记录最大深度
    int maxLeftValue;     //最大深度最左边的数值
    void traversal(TreeNode* root, int leftLen)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(leftLen > maxLen)
            {
                maxLen = leftLen;
                maxLeftValue = root->val;
            }
            return;
        }

        if(root->left != NULL) 
        {
            leftLen++;
            traversal(root->left, leftLen);
            leftLen--;
        }
        if(root->right != NULL)
        {
            leftLen++;
            traversal(root->right, leftLen);
            leftLen--;
        }
    }
public:
    int findBottomLeftValue(TreeNode* root) 
    {
        traversal(root, 0);
        return maxLeftValue;
    }
}; 

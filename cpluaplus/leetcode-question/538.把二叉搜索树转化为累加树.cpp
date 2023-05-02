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
 
 
 
//累加树：使得每个节点的值是原来的节点值加上所有大于它的节点值之和
//[2, 5, 13]  ->  [20, 18, 13]  如果是数组从后往前累加就行了
//搜索二叉树呢？反中序即可 -> 右中左（类似降序)
class Solution 
{
private:
    //遍历整颗树，所以不需要返回值
    TreeNode* pre; //记录前一个节点，方便累加
    void traversal(TreeNode* cur)
    {
        if(cur == NULL) return;
        
        traversal(cur->right);
        if(pre != NULL)
        {
            cur->val += pre->val;
        }
        pre = cur;//记录
        traversal(cur->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        pre = NULL;
        traversal(root);
        return root;
    }
};


//----------------------------------------------------------------------- 
//迭代 - 模拟递归
class Solution 
{
public:
    TreeNode* convertBST(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while(cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur = cur->right;  //右
            }
            else
            {
                cur = st.top();    //中
                st.pop();
                if(pre != NULL)
                {
                    cur->val += pre->val;
                }
                pre = cur;         //记录前一个节点
                cur = cur->left;   //左
            }
        }
        return root;
    }
};

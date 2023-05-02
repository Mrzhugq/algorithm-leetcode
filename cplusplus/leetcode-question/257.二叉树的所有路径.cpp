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

//要求从根节点到叶子节点路径，所以需要前序遍历，这样才方便让父节点指向孩子节点，找到对于路径
//利用回溯法 - path记录符合条件的单一路线，result记录符合的所有路径

class Solution 
{
private:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result)
    {
        path.push_back(cur->val); //中

        if(cur->left == NULL && cur->right == NULL)
        {
            string s;
            for(int i=0; i<path.size()-1; i++) //注意结束条件，最后一个数字特殊处理
            {
                s += to_string(path[i]);  //不能直接在这行后面直接 + "->"，因为string没有重载+
                s += "->";
            }
            s += to_string(path[path.size() - 1]);//最后一个数字后面没有->
            result.push_back(s);
            return;
        }
        //前序
        if(cur->left != NULL)  //左
        {
            traversal(cur->left, path, result);//一个递归一个pop
            path.pop_back();
        }
        if(cur->right != NULL)  //右
        {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<int> path;
        vector<string> result;
        if(root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};

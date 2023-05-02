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

//Ҫ��Ӹ��ڵ㵽Ҷ�ӽڵ�·����������Ҫǰ������������ŷ����ø��ڵ�ָ���ӽڵ㣬�ҵ�����·��
//���û��ݷ� - path��¼���������ĵ�һ·�ߣ�result��¼���ϵ�����·��

class Solution 
{
private:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result)
    {
        path.push_back(cur->val); //��

        if(cur->left == NULL && cur->right == NULL)
        {
            string s;
            for(int i=0; i<path.size()-1; i++) //ע��������������һ���������⴦��
            {
                s += to_string(path[i]);  //����ֱ�������к���ֱ�� + "->"����Ϊstringû������+
                s += "->";
            }
            s += to_string(path[path.size() - 1]);//���һ�����ֺ���û��->
            result.push_back(s);
            return;
        }
        //ǰ��
        if(cur->left != NULL)  //��
        {
            traversal(cur->left, path, result);//һ���ݹ�һ��pop
            path.pop_back();
        }
        if(cur->right != NULL)  //��
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

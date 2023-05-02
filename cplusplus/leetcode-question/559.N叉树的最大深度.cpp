/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//和104.二叉树的最大深度思路一样
class Solution 
{
public:
    int maxDepth(Node* root) 
    {
        if(root == 0) return 0;
        int depth = 0;
        for(int i = 0; i < root->children.size(); i++)
        {
            //不是不是左右子树的最大深度+1，而是所有子树的最大深度+1
            depth = max( depth, maxDepth(root->children[i]) );
        }
        return depth + 1; //最后加1，不是再for循环里面
    }
};



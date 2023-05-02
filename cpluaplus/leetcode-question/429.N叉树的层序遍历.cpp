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

class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> res;
        queue<Node*> que;
        if(root != NULL)  que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for(int i=0; i<size; i++) //注意size
            {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                //注意每个节点里面不是只有左右节点了，而是一个所有孩子节点的数组
                for(int j=0; j < node->children.size(); j++)
                {
                    if( (node->children)[j] != NULL )
                    {
                        que.push( (node->children)[j] );
                    }
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};



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

//��104.��������������˼·һ��
class Solution 
{
public:
    int maxDepth(Node* root) 
    {
        if(root == 0) return 0;
        int depth = 0;
        for(int i = 0; i < root->children.size(); i++)
        {
            //���ǲ�������������������+1����������������������+1
            depth = max( depth, maxDepth(root->children[i]) );
        }
        return depth + 1; //����1��������forѭ������
    }
};



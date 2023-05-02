/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        queue<Node*> que;
        if(root != NULL)  que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            Node* nodePrev;
            Node* node;
            for(int i=0; i<size; i++) //注意size
            {
                if(i == 0)
                {
                    nodePrev = que.front(); //先取出一层的头节点
                    que.pop();
                    node = nodePrev; //同时初始化一下node，方便47，48的判断
                }
                else
                {
                    node = que.front();
                    que.pop();
                    nodePrev->next = node;  //横向链接上
                    nodePrev = node;        //nodePrev每层往右走
                }
                if(node->left != NULL)  que.push(node->left); //记得同时把左右节点入队列
                if(node->right != NULL)  que.push(node->right);
            }
            nodePrev->next = NULL; //每层最后
        }
        return root;
    }
};




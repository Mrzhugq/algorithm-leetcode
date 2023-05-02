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
            for(int i=0; i<size; i++) //ע��size
            {
                if(i == 0)
                {
                    nodePrev = que.front(); //��ȡ��һ���ͷ�ڵ�
                    que.pop();
                    node = nodePrev; //ͬʱ��ʼ��һ��node������47��48���ж�
                }
                else
                {
                    node = que.front();
                    que.pop();
                    nodePrev->next = node;  //����������
                    nodePrev = node;        //nodePrevÿ��������
                }
                if(node->left != NULL)  que.push(node->left); //�ǵ�ͬʱ�����ҽڵ������
                if(node->right != NULL)  que.push(node->right);
            }
            nodePrev->next = NULL; //ÿ�����
        }
        return root;
    }
};




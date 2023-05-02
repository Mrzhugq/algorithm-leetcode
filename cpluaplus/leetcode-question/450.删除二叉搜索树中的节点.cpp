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

/*
ɾ�������������ڵ�˼·��
һ.û���ҵ�Ҫɾ���ڵ�

��.�ҵ�ɾ���Ľڵ�
    1.Ҫɾ���ڵ�����Һ��Ӷ�Ϊ�� -> ֱ��ɾ��������NULL
    2.Ҫɾ���ڵ������Ϊ�գ��Һ��Ӳ�Ϊ�� -> ɾ���ýڵ��Һ��Ӳ�λ
    3.Ҫɾ���ڵ�����Ӳ�Ϊ�գ��Һ���Ϊ�� -> ɾ���ýڵ����Ӳ�λ
    4.���Ҫɾ���ڵ�����ҽڵ㶼��Ϊ�գ���ô����
    ��ɾ���ڵ��������ͷ�ڵ㣨���ӣ��ŵ�Ҫɾ���ڵ��������������߽ڵ�������ϣ�
    ����Ҫɾ���ڵ��Һ� ��Ϊ�µĸ��ڵ�
*/

//������˼·��
class Solution 
{
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)  return NULL; //û�ҵ�
        if(root->val == key)
        {
            //���Ҫɾ���ڵ�����Һ��Ӷ�Ϊ��ֱ��ɾ��������NULL
            if(root->left == NULL) //Ҫɾ���ڵ����ڵ�Ϊ�գ��Ҳ�Ϊ�գ�ɾ���ýڵ��Һ��Ӳ�λ
            {
                TreeNode* temp = root->right; //�����о����ͷ�Ҫɾ���ڵ���ڴ棬����һ��
                delete root;
                return temp;
                //return root->right;         //����д�ǲ��ͷ��ڴ�
            }
            else if(root->right == NULL)//Ҫɾ���ڵ���ҽڵ�Ϊ�գ���Ϊ�գ�ɾ���ýڵ����Ӳ�λ 
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
                //return root->left;
            }
            else //Ҫɾ���ڵ�����ҽڵ㶼��Ϊ��
            {
                TreeNode* cur = root->right;
                while(cur->left != NULL)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* temp = root; //��¼Ҫɾ���Ľڵ㣬�Ա����ͷ��ڴ�
                root = root->right;
                delete temp;
                return root; 
            }
        }

        if(root->val > key)
        {
            root->left = deleteNode(root->left, key); 
            //�����൱�ڰ��µĽڵ㷵����һ�㣬��һ���Ҫ��root->left����root->right��ס
        }
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};



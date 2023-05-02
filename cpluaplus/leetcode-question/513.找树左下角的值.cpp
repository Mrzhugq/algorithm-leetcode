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

//��������ȽϺ����-���һ�еĵ�һ����ֵ
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
                if(i == 0)//��¼���һ�е�һ������ÿ�������ж��ᱻ���¸�ֵ
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
//���û��� -
//������- ���һ��
//����ҵ�������� ����� ��Ҷ�ӽڵ㣿ǰ����� - �����������

class Solution 
{
private:
    //����ȫ�ֱ���
    int maxLen = INT_MIN; //��¼������
    int maxLeftValue;     //����������ߵ���ֵ
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

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

//0����ýڵ�δ����
//1����ýڵ�������ͷ
//2����ýڵ��и���

//̰��-�ֲ����ţ���Ҷ�ӽڵ�ĸ��׽ڵ㰴����ͷ����������ͷ����
//���Ƿ�������Ҷ�ӽڵ�û�з�ֹ����ͷ�����(��Ϊ���Ҷ�ӽڵ������ͷ���˷���һ��ĸ���) 
//�������ǿ��ԴӴ˳�����������ͷ����Ҷ�ӽڵ���(��Ҫ�������)
class Solution 
{
private:
    int res;
    int traversal(TreeNode* cur)
    {
        //�սڵ�Ҫ����Ϊ�и���(��������Ϊ������ͷ�������Ļ�Ҷ�ӽڵ�ĸ��׽ڵ���ò�����������ͷ��)
        if(cur == NULL) return 2;
        //����������������Ͽ�
        int left = traversal(cur->left);
        int right = traversal(cur->right);

        //���Ҷ��и���
        if(left == 2 && right ==2)
        {
            return 0;
        }
        //����������һ���޸���
        if(left == 0 || right == 0)
        {
            res++;
            return 1; 
        }
        //����������һ������ͷ(�����������Ĵ��붼������)
        if(left == 1 || right == 1)
        {
            return 2;
        }
        return -1; //��ʵ���붼�߲���������ӱ������ᱨ��
    }
public:
    int minCameraCover(TreeNode* root) 
    {
        res = 0;
        //����ж�һ��ͷ�ڵ��Ƿ��и��ǣ��޸��ǵĻ�res++һ��
        if(traversal(root) == 0)
        {
            res++;
        }
        return res;
    }
};



/*
�����ѵ㣿
1.�������ı���
2.����������ڵ��һ������ͷ
*/



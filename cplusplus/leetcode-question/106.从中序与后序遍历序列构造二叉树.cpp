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

//����������
//����: ������

//�����е����䶼���� ����ҿ�
//�и��������������ͺ��������Сһ����һ���ģ���Ҫ��⣩
class Solution 
{
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
    {
        if(postorder.size() == 0) return NULL;

        int rootVal = postorder[postorder.size() - 1]; //�ڵ�ֵ���Ǻ�����ֵ�������һ����
        TreeNode* root = new TreeNode(rootVal);
        //Ҷ�ӽڵ�
        if(inorder.size() == 1)  return root;
        //�ýڵ�ֵ�и��������飬���ҵ��ڵ�ֵ�����������λ��
        int delimiterIndex;
        for(delimiterIndex = 0; delimiterIndex<inorder.size(); delimiterIndex++)
        {
            if(inorder[delimiterIndex] == rootVal)
                break;
        }

        //��ʼ�и��������� [ ����ҿ� )
        //[ 0, delimiterIndex )
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        //[ delimiterIndex + 1, end )
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        //��ȥ�����������һ��Ԫ��
        postorder.resize(postorder.size() - 1);
        //��ʼ�и�������� [ ����ҿ� )������ʹ�������������С��Ϊ�и��
        //[ 0, leftInorder.size )
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        //[ leftInorder.size, end ) //postorder�Ѿ�����ԭ���Ĵ�С�ˣ���ȥ�����һ��
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder); //�ݹ齨��
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size() == 0 || postorder.size() == 0)
        {
            return NULL;
        }
        return traversal(inorder, postorder);
    }
};



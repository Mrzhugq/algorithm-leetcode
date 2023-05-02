/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool compare(struct TreeNode* left,struct TreeNode* right)
{
    if((left==NULL && right!=NULL) || (left!=NULL && right==NULL)) 
    return false;
    else if(left==NULL && right==NULL)
    return true;
    else if(left->val != right->val)
    return false;
    //������->��ǰ�ڵ㲻Ϊ�գ��ҽڵ�ֵ��ȣ���ʼ�ݹ� 
    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    return outside && inside;
}

bool isSymmetric(struct TreeNode* root)
{
	if(root==NULL) return true; 
    return compare(root->left,root->right);
}

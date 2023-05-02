/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int TreeSize(struct TreeNode* root)
{
    return root==NULL ? 0 : 
    TreeSize(root->left)+TreeSize(root->right)+1;
}

void _Preorder(struct TreeNode* root, int* ret,int *i)
{
    if(root==NULL)
    return;

    ret[*i]=root->val;
    (*i)++;
    _Preorder(root->left,ret,i);
    _Preorder(root->right,ret,i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int len=TreeSize(root);
    *returnSize=len;
    int i=0;
    int *ret=(int*)malloc(sizeof(int)*len);
    _Preorder(root,ret,&i);
    return ret;
}

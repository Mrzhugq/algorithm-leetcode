
int TreeHight(struct TreeNode* root)//求节点高度函数 
{
    if(root==NULL) return 0;
    int L1=TreeHight(root->left);
    int L2=TreeHight(root->right);
    return (L1>L2 ? L1 : L2) + 1;
}

bool isBalanced(struct TreeNode* root)
{
    if(root==NULL) return true;

    return abs(TreeHight(root->left)-TreeHight(root->right))<=1 
	&& isBalanced(root->left)
    && isBalanced(root->right);
}

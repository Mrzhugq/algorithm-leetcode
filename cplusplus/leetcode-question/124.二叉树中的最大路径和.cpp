/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 
//返回从root开始到任意位置终点的最大路径和（可以不选，都不选为0）
int maxPathSumRoot(struct TreeNode* root)
{
    if(root == NULL) return 0;
    
    //有root
    //1）选左
    int left = maxPathSumRoot(root->left) + root->val;
    //2）选右
    int right = maxPathSumRoot(root->right) + root->val;

    //没有root
    int result = 0;
    return fmax(fmax(left, right), 0);
}

//返回任意起点走到任意终点的最大路径和（不可以不选，至少有一个可选）
int maxPathSum(struct TreeNode* root)
{
    if(root == NULL) return INT_MIN;

    //经过中间（root）的最大路径和
    int middle = root->val + maxPathSumRoot(root->left) + maxPathSumRoot(root->right);

    //不经过中间（root）的最大路径和
    //1）最大路径和在左边
    int left = maxPathSum(root->left);   //如果root->left==NULL left就会被赋值INT_MIN 不影响算最大值
    //2）最大路径和在右边
    int right = maxPathSum(root->right);
    return fmax(middle, fmax(left, right));
}

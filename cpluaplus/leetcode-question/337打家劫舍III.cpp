/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
//下标的含义：下标为0记录不偷该节点所得到的的最多金钱，下标为1记录偷该节点所得到的的最多金钱。
//robRange返回数组就是dp数组

//首先明确的是使用后序遍历。 因为通过递归函数的返回值来做下一步计算。
//通过递归左节点，得到左节点偷与不偷的钱。
//通过递归右节点，得到右节点偷与不偷的钱

int *robRange(struct TreeNode* root)
{
    int *ret=(int*)calloc(sizeof(int),2);
    if(root==NULL)
    {
        return ret;
    }

    int *leftvalue=(int*)calloc(sizeof(int),2);
    int *rightvalue=(int*)calloc(sizeof(int),2);
    leftvalue=robRange(root->left);
    rightvalue=robRange(root->right);
    //选root->val
    ret[0]=root->val+leftvalue[1]+rightvalue[1];
    //不选root->val
    ret[1]=fmax(leftvalue[0],leftvalue[1]) + fmax(rightvalue[0],rightvalue[1]);
    return ret;
}

int rob(struct TreeNode* root)
{
    int *dp=(int*)calloc(sizeof(int),2);
    dp=robRange(root);
    
    return fmax(dp[0],dp[1]);
}
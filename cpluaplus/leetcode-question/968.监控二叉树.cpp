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

//0代表该节点未覆盖
//1代表该节点有摄像头
//2代表该节点有覆盖

//贪心-局部最优：让叶子节点的父亲节点按摄像头，所用摄像头最少
//我们发现例子叶子节点没有防止摄像头的情况(因为如果叶子节点放摄像头就浪费了一层的覆盖) 
//所以我们可以从此出发，把摄像头放在叶子节点上(需要后序遍历)
class Solution 
{
private:
    int res;
    int traversal(TreeNode* cur)
    {
        //空节点要设置为有覆盖(不能设置为有摄像头，这样的话叶子节点的父亲节点就用不到放置摄像头了)
        if(cur == NULL) return 2;
        //后序遍历，从下往上看
        int left = traversal(cur->left);
        int right = traversal(cur->right);

        //左右都有覆盖
        if(left == 2 && right ==2)
        {
            return 0;
        }
        //左右至少有一个无覆盖
        if(left == 0 || right == 0)
        {
            res++;
            return 1; 
        }
        //左右至少有一个摄像头(其他情况上面的代码都讨论了)
        if(left == 1 || right == 1)
        {
            return 2;
        }
        return -1; //其实代码都走不到这里，不加编译好像会报错
    }
public:
    int minCameraCover(TreeNode* root) 
    {
        res = 0;
        //最后判断一下头节点是否有覆盖，无覆盖的话res++一下
        if(traversal(root) == 0)
        {
            res++;
        }
        return res;
    }
};



/*
两个难点？
1.二叉树的遍历
2.如果隔两个节点放一个摄像头
*/



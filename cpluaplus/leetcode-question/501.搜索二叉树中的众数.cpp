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



//按照普通二叉树处理，先遍历用unordered_map统计频率,然后转化为vector，按频率排序
class Solution 
{
private:
    //前序遍历统计，其实什么遍历方式都行
    void traversal(TreeNode* root, unordered_map<int, int>& mp)
    {
        if(root == NULL) return;
        mp[root->val]++;
        traversal(root->left, mp);
        traversal(root->right, mp);
        return;
    }
    bool static cmp(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return p1.second > p2.second;
    }
public:
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL)  return res;
        unordered_map<int, int> mp;
        traversal(root, mp); //统计频率
        vector<pair<int, int>> vec(mp.begin(), mp.end());//map转化为vector
        sort(vec.begin(), vec.end(), cmp);//按频率排序

        res.push_back(vec[0].first);
        for(int i=1; i<vec.size(); i++) //可能有多个数频率相同
        {
            if(vec[i].second == vec[0].second)
            {
                res.push_back(vec[i].first);
            }
            else
            {
                break;
            }
        }
        return res;
    }
};



//------------------------------------------------------
//可以遍历两次树，先找出最大频率，然后把等于最大频率的（多个）数加入res。

//当然还要更优方法  ->  遍历一次树，就能找到众数
//中序遍历-相同数的节点一定相邻，用pre记录cur前一个节点，来比较是否相等
class Solution 
{
private:
    int count;     //统计频率
    int maxCount;  //最大频率
    TreeNode* pre;
    vector<int> res;
    void searchBST(TreeNode* cur)
    {
        if(cur == NULL)  return;
        searchBST(cur->left);

        if(pre == NULL) //第一个节点
        {
            count = 1;
        }
        else if(pre->val == cur->val)
        {
            count++;
        }
        else //与前一个节点数值不同
        {
            count = 1;
        }
        pre = cur; //更新上一节点

        if(count == maxCount)
        {
            res.push_back(cur->val);
        }
        if(count > maxCount) 
        {
            //只遍历一遍，所以当出现比当前最大频率还大的数，不但更新最大值，还要清空res，
            //因为有新数的频率比之前数的频率大了，之前的数都失效了，最后把这个新数加入
            maxCount = count;
            res.clear(); //关键一步
            res.push_back(cur->val);
        }

        searchBST(cur->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) 
    {
        count = 0;
        maxCount = 0;
        pre = NULL;
        res.clear();

        searchBST(root);
        return res;
    }
};

 
//------------------------------------------------------ 
class Solution 
{
public:
    vector<int> findMode(TreeNode* root) 
    {
        int count = 0;
        int maxCount = 0;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        stack<TreeNode*> st;
        vector<int> res;

        while(cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur = cur->left; //左
            }
            else
            {
                cur = st.top();  //中
                st.pop();

                //和递归一样思路，只是用栈模拟递归
                if(pre == NULL)
                {
                    count = 1;
                }
                else if(pre->val == cur->val)
                {
                    count++;
                }
                else
                {
                    count = 1;
                }
                if(count == maxCount)
                {
                    res.push_back(cur->val);
                }
                if(count > maxCount)
                {
                    maxCount = count;
                    res.clear();//关键一步
                    res.push_back(cur->val);
                }
                pre = cur;         //记录前一个节点
                cur = cur->right;  //右
            }
        }
        return res;
    }
};



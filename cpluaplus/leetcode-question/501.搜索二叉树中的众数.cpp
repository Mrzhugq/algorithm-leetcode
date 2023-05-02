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



//������ͨ�����������ȱ�����unordered_mapͳ��Ƶ��,Ȼ��ת��Ϊvector����Ƶ������
class Solution 
{
private:
    //ǰ�����ͳ�ƣ���ʵʲô������ʽ����
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
        traversal(root, mp); //ͳ��Ƶ��
        vector<pair<int, int>> vec(mp.begin(), mp.end());//mapת��Ϊvector
        sort(vec.begin(), vec.end(), cmp);//��Ƶ������

        res.push_back(vec[0].first);
        for(int i=1; i<vec.size(); i++) //�����ж����Ƶ����ͬ
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
//���Ա��������������ҳ����Ƶ�ʣ�Ȼ��ѵ������Ƶ�ʵģ������������res��

//��Ȼ��Ҫ���ŷ���  ->  ����һ�����������ҵ�����
//�������-��ͬ���Ľڵ�һ�����ڣ���pre��¼curǰһ���ڵ㣬���Ƚ��Ƿ����
class Solution 
{
private:
    int count;     //ͳ��Ƶ��
    int maxCount;  //���Ƶ��
    TreeNode* pre;
    vector<int> res;
    void searchBST(TreeNode* cur)
    {
        if(cur == NULL)  return;
        searchBST(cur->left);

        if(pre == NULL) //��һ���ڵ�
        {
            count = 1;
        }
        else if(pre->val == cur->val)
        {
            count++;
        }
        else //��ǰһ���ڵ���ֵ��ͬ
        {
            count = 1;
        }
        pre = cur; //������һ�ڵ�

        if(count == maxCount)
        {
            res.push_back(cur->val);
        }
        if(count > maxCount) 
        {
            //ֻ����һ�飬���Ե����ֱȵ�ǰ���Ƶ�ʻ�������������������ֵ����Ҫ���res��
            //��Ϊ��������Ƶ�ʱ�֮ǰ����Ƶ�ʴ��ˣ�֮ǰ������ʧЧ�ˣ����������������
            maxCount = count;
            res.clear(); //�ؼ�һ��
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
                cur = cur->left; //��
            }
            else
            {
                cur = st.top();  //��
                st.pop();

                //�͵ݹ�һ��˼·��ֻ����ջģ��ݹ�
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
                    res.clear();//�ؼ�һ��
                    res.push_back(cur->val);
                }
                pre = cur;         //��¼ǰһ���ڵ�
                cur = cur->right;  //��
            }
        }
        return res;
    }
};


